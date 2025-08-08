#include "combined.h"

#include <iostream>

#include "keccack.h"


#define SHA3_256_RATE 136

#define SHA3_512_RATE 72

#define SHAKE128_RATE 168

#define SHAKE256_RATE 136

#define KECCAKF_ROUNDS 24

#define N 256

#define Q 3329

#define ETA 2

#define OUTLEN 128

#define BLOCK_G 0

#define BLOCK_H 8

#define BLOCK_SHAKE_128 0

#define BLOCK_SHAKE_256 0

#define MAX_LEN 168

#define MAX_RATE64 21

#define MAX_OUTLEN OUTLEN

#define RATE_64(x) ((x) >> 3)


void absorb_block(sc_uint<64> *state, sc_uint<8> *buffer, sc_uint<8> rate) {


    for (sc_uint<8> j = 0; j < MAX_RATE64; j++) {

        if (j >= RATE_64(rate)) continue;


        sc_uint<64> t = 0;

        for (sc_uint<8> k = 0; k < 8; k++) {

            //HLS_UNROLL_LOOP(ON, "absorb");

            t |= ((sc_uint<64>)buffer[(j << 3) + k]) << (k << 3);

        }

        state[j] ^= t;

    }

    keccack::keccakf(state);

}


void keccak_absorb(sc_uint<64> *state, sc_uint<8> *input, sc_uint<8> blocks, sc_uint<8> pad, sc_uint<8> rate, sc_uint<16> len) {


    for (sc_uint<8> i = 0; i < 25; i++) {

        //HLS_UNROLL_LOOP(ON, "absorb_init");

        state[i] = 0;

    }


    sc_uint<16> offset = 0;

    if (blocks == 8) {

        for (sc_uint<8> i = 0; i < 8; i++) {

            absorb_block(state, &input[offset], rate);

            offset += rate;

        }

    }


    sc_uint<16> remaining;

    if(blocks == 0) remaining = len;

    else remaining = len - (sc_uint<16>)1088;


    std::cout << "offfffffsett:" << std::endl;

    std::cout << std::dec << offset << " ";


    sc_uint<8> temp[MAX_LEN] = {0};


    for (sc_uint<8> i = 0; i < MAX_LEN; i++) {

        //assert(offset + remaining - 1 < len);

        if((offset + i) < len){

            temp[i] = input[offset + i];

        }

        else {temp[i] = (sc_uint<8>)0;}

    }


    if (remaining < MAX_LEN) temp[remaining] = pad;

    if (rate - 1 < MAX_LEN) temp[rate - 1] |= 0x80;


    absorb_block(state, temp, rate);

}


void keccak_squeeze(sc_uint<64> *state, sc_uint<8> *output, sc_uint<8> rate, sc_uint<8> outlen) {



    sc_uint<16> output_index = 0;

    sc_uint<16> chunk_count = (MAX_OUTLEN + rate - 1) / rate;


    for (sc_uint<16> chunk = 0; chunk < chunk_count; chunk++) {

        for (sc_uint<8> j = 0; j < MAX_RATE64; j++) {

            if (j >= RATE_64(rate)) continue;


            for (sc_uint<8> k = 0; k < 8; k++) {

                //HLS_UNROLL_LOOP(ON, "squeeze_output");

                sc_uint<16> idx = output_index + (j << 3) + k;

                if (idx < outlen) {

                    output[idx] = (state[j] >> (k << 3)) & 0xFF;

                }

            }

        }

        output_index += rate;

        if (output_index < outlen) {

            keccack::keccakf(state);

        }

    }

}


void shake(sc_uint<8> *input, sc_uint<8> *output, sc_uint<8> outlen, sc_uint<8> blocks, sc_uint<8> pad, sc_uint<8> rate, sc_uint<16> len) {

    sc_uint<64> state[25];

    keccak_absorb(state, input, blocks, pad, rate, len);

    keccak_squeeze(state, output, rate, outlen);

}


void bytes_to_bits(const sc_uint<8> *B, sc_uint<8> *b) {

    for (sc_uint<8> i = 0; i < OUTLEN; i++) {

        sc_uint<8> byte = B[i];

        for (sc_uint<8> j = 0; j < 8; j++) {

            //HLS_UNROLL_LOOP(ON, "byte_bits");

            b[(i << 3) | j] = (byte >> j) & 1;

        }

    }

}


void sample_poly_CBD(const sc_uint<8> *B, sc_int<16> *f) {

    sc_uint<8> b[1024];

    bytes_to_bits(B, b);


    for (sc_uint<16> i = 0; i < N; i++) {

        //HLS_PIPELINE_LOOP(HARD_STALL, 2, "cbd1");

        sc_uint<16> a = 0, b_sum = 0;

        sc_uint<16> base_idx = i << 2;

        for (sc_uint<8> j = 0; j < ETA; j++) {

            //HLS_UNROLL_LOOP(ON, "cbd2");

            a += b[base_idx + j];

            b_sum += b[base_idx + ETA + j];

        }


        sc_int<16> diff = a - b_sum;

        sc_int<16> reduced = diff;

        if (diff < 0) reduced += Q;

        if (reduced >= Q) reduced -= Q;


        f[i] = reduced;

    }

}


void sampleNTT(sc_uint<16> a_hat[256],  sc_uint<8> input[34]) {

    sc_uint<64> s[25];

    sc_uint<8> out[3];

    sc_uint<16> j = 0;


    keccak_absorb(s, input, BLOCK_SHAKE_256, 0x1F, SHAKE128_RATE, 34);


    for (sc_uint<16> iter = 0; iter < 384; iter++) { // conservative max iterations

        if (j >= 256) break;

        keccak_squeeze(s, out, SHAKE128_RATE, 3);


        sc_uint<16> d1 = out[0] | ((out[1] & 0xF) << 8);

        sc_uint<16> d2 = (out[1] >> 4) | (out[2] << 4);


        if (d1 < Q) a_hat[j++] = d1;

        if (d2 < Q && j < 256) a_hat[j++] = d2;

    }

}


void combined::thread1() {

    CYN_PROTOCOL("reset");

    inputs.reset();

    outputs.reset();

    wait();


    while (true) {

        combined_INPUT_DT input_val = inputs.get();

        combined_OUTPUT_DT output_val = {};


        if (input_val.start_g) {

            sc_uint<8> out[64];

            shake(input_val.din, out, 64, BLOCK_G, 0x06, SHA3_512_RATE, 32);

            for (sc_uint<8> i = 0; i < 32; i++) {

                //HLS_PIPELINE_LOOP(HARD_STALL, 2, "startg");

                output_val.rho_out[i] = out[i];

                output_val.sigma_out[i] = out[i + 32];

            }

            output_val.done_g = 1;

        }

        else if (input_val.start_h) {

            sc_uint<8> out[32];

            shake(input_val.ek, out, 32, BLOCK_H, 0x06, SHA3_256_RATE, 1184);

            for (sc_uint<8> i = 0; i < 32; i++) {

                //HLS_PIPELINE_LOOP(HARD_STALL, 2, "starth");

                output_val.H_ek[i] = out[i];

            }

            output_val.done_h = 1;

        }

        else if (input_val.start_prf) {

            for (sc_uint<8> i = 0; i < 6; i++) {

                sc_uint<8> temp_in[33];

                for (sc_uint<8> j = 0; j < 32; j++){

                    //HLS_PIPELINE_LOOP(HARD_STALL, 2, "startprf1");

                    temp_in[j] = input_val.sigma[j];}

                temp_in[32] = i;


                sc_uint<8> shake_out[OUTLEN];

                shake(temp_in, shake_out, OUTLEN, BLOCK_SHAKE_256, 0x1F, SHAKE256_RATE, 33);


                sc_int<16> f[256];

                sample_poly_CBD(shake_out, f);

                for (sc_uint<16> j = 0; j < 256; j++){

                    //HLS_PIPELINE_LOOP(HARD_STALL, 2, "startprf2");

                    output_val.se[i][j] = f[j];}

            }

            output_val.done_prf = 1;

        }

        else if (input_val.start_sntt) {

            sc_uint<8> in[34];

            for (sc_uint<8> i = 0; i < 32; i++){

                //HLS_PIPELINE_LOOP(HARD_STALL, 2, "startsntt1");

                in[i] = input_val.rho[i];}


            for (sc_uint<8> i = 0; i < 3; i++) {

                //HLS_UNROLL_LOOP(ON, "sntt1");

                for (sc_uint<8> j = 0; j < 3; j++) {

                    //HLS_UNROLL_LOOP(ON, "sntt2");

                    in[32] = j;

                    in[33] = i;


                    sc_uint<16> result[256];

                    sampleNTT(result, in);


                    for (sc_uint<16> k = 0; k < 256; k++) {

                        //HLS_PIPELINE_LOOP(HARD_STALL, 2, "startsntt2");

                        output_val.A[(i << 1) + i + j][k] = result[k];

                    }

                }

            }

            output_val.done_sntt = 1;

        }


        if (input_val.start_combined) {

            output_val.done_combined = 1;

        }


        outputs.put(output_val);

    }

}



