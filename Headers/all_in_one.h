#ifndef ALL_IN_ONE_H
#define ALL_IN_ONE_H

#include <systemc.h>
#include <cynw_p2p.h>

#include "KeyGen_input_type.h"
#include "KeyGen_output_type.h"
#include "combined_input_type.h"
#include "combined_output_type.h"
#include "ntt_input_type.h"
#include "ntt_output_type.h"
//#include "benc1_input_type.h"
//#include "benc1_output_type.h"
//#include "benc2_input_type.h"
//#include "benc2_output_type.h"
#include "byenc.h"
#include "mul_input_type.h"
#include "mul_output_type.h"

#include "benc_struct.h"

SC_MODULE(all_in_one) {
    sc_in_clk  clk;
    sc_in<bool> rst;

    cynw_p2p_in<KeyGen_INPUT_DT> in1;
    cynw_p2p_out<combined_INPUT_DT> out_comb;
    cynw_p2p_in<combined_OUTPUT_DT> in_comb;
    cynw_p2p_out<ntt_INPUT_DT> out5;
    cynw_p2p_in<ntt_OUTPUT_DT> in5;
    cynw_p2p_out<mul_INPUT_DT> out6;
    cynw_p2p_in<mul_OUTPUT_DT> in6;
//    cynw_p2p_out<benc1_INPUT_DT> out7;
//    cynw_p2p_in<benc1_OUTPUT_DT> in7;
//    cynw_p2p_out<benc2_INPUT_DT> out8;
//    cynw_p2p_in<benc2_OUTPUT_DT> in8;
    cynw_p2p_out<KeyGen_OUTPUT_DT> in10;
    sc_uint<8> rho_benc1[32];

    SC_CTOR(all_in_one) {
        SC_CTHREAD(process, clk.pos());
        set_stack_size(0x200000);
        reset_signal_is(rst, 0);

        in1.clk_rst(clk, rst);
        out_comb.clk_rst(clk, rst);
        in_comb.clk_rst(clk, rst);
        out5.clk_rst(clk, rst);
        in5.clk_rst(clk, rst);
        out6.clk_rst(clk, rst);
        in6.clk_rst(clk, rst);
//        out7.clk_rst(clk, rst);
//        in7.clk_rst(clk, rst);
//        out8.clk_rst(clk, rst);
//        in8.clk_rst(clk, rst);
        in10.clk_rst(clk, rst);
    }

    enum State {
        IDLE, G, PRF, NTT_SNTT_PARALLEL, BYTE_ENCODE_MUL_PARALLEL,
        BYTE_ENCODE, H, FUSE, FINISH
    };

    void process() {
        {
            HLS_DEFINE_PROTOCOL("reset");
            in1.reset(); in_comb.reset(); in5.reset();
            in6.reset();
            out_comb.reset(); out5.reset(); out6.reset(); in10.reset();
            wait();
        }

        State state = IDLE;

        KeyGen_INPUT_DT input_val;
        KeyGen_OUTPUT_DT output_val;
        ntt_INPUT_DT ntt_in;
        ntt_OUTPUT_DT ntt_out;
        mul_INPUT_DT mul_in;
        mul_OUTPUT_DT mul_out;
        combined_INPUT_DT comb_in;
        combined_OUTPUT_DT comb_out;
        BENC_in be_in;
        BENC_out be_out;


        be_in.start_benc = 0;
        be_out.done_benc = 0;
        be_in.start_benc1 = 0;
        be_out.done_benc1 = 0;
        be_in.start_benc2 = 0;
        be_out.done_benc2 = 0;

        while (true) {
            std::cout << "[DEBUG] Current state: " << state << std::endl; // Add this
            switch (state) {
                case IDLE: {
                    std::cout << "[KeyGen] State: IDLE\n";
                    input_val = in1.get();
                    output_val.done_kg = 0;

                    for (int i = 0; i < 32; ++i){
                        comb_in.din[i] = input_val.d[i];
                    }
                    comb_in.start_g = 1;
                    comb_in.start_h = 0;
                    comb_in.start_prf = 0;
                    comb_in.start_sntt = 0;
                    out_comb.put(comb_in);
                    state = G;
                    break;
                }
                case G: {
                    std::cout << "[KeyGen] State: G\n";
                    comb_out = in_comb.get();

                    if (comb_out.done_g) {
                        for (int i = 0; i < 32; i++) {
                            comb_in.sigma[i] = comb_out.sigma_out[i];
                            comb_in.rho[i] = comb_out.rho_out[i];

                            rho_benc1[i] = comb_out.rho_out[i];
                        }

                        comb_in.start_g = 0;
                        comb_in.start_h = 0;
                        comb_in.start_sntt = 0;
                        comb_in.start_prf = 1;
                        out_comb.put(comb_in);
                        state = PRF;
                    }
                    break;
                }
                case PRF: {
                    std::cout << "[KeyGen] State: PRF\n";
                    comb_out = in_comb.get();

                    if (comb_out.done_prf) {
                        for (int i = 0; i < 6; i++)
                            for (int j = 0; j < 256; j++)
                                ntt_in.se_ntt[i][j] = comb_out.se[i][j];

                        for (int i = 0; i < 32; i++)
                            comb_in.rho[i] = comb_out.rho_out[i];

                        comb_in.start_prf = 0;
                        comb_in.start_g = 0;
                        comb_in.start_h = 0;
                        comb_in.start_sntt = 1;
                        out_comb.put(comb_in);

                        ntt_in.start_ntt = 1;
                        out5.put(ntt_in);
                        state = NTT_SNTT_PARALLEL;
                    }
                    break;
                }
                case NTT_SNTT_PARALLEL: {
                    std::cout << "[KeyGen] State: NTT & SNTT\n";
                    comb_out = in_comb.get();
                    ntt_out = in5.get();

                    if (comb_out.done_sntt && ntt_out.done_ntt) {
                        for (int i = 0; i < 3; i++)
                            for (int j = 0; j < 256; j++)
                                be_in.benc_in[i][j] = ntt_out.se_arr[i][j];

                        for (int j = 0; j < 9; j++)
                            for (int i = 0; i < 256; i++)
                                mul_in.A_mul[j][i] = comb_out.A[j][i];

                        for (int j = 0; j < 6; j++)
                            for (int i = 0; i < 256; i++)
                                mul_in.se_mul[j][i] = ntt_out.se_arr[j][i];

                        comb_in.start_sntt = 0;
                        be_in.start_benc = 1;
                        be_in.start_benc2 = 1;
                        be_in.start_benc1 = 0;
                        mul_in.start_mul = 1;
                        out6.put(mul_in);
                        state = BYTE_ENCODE_MUL_PARALLEL;
                    }
                    break;
                }
                case BYTE_ENCODE_MUL_PARALLEL: {
                    std::cout << "[KeyGen] State: BENC2 & MUL\n";

                    byenc::my_function(be_in, be_out);
                    mul_out = in6.get();
                        std::cout << "done_benc: " << be_out.done_benc
                                  << " done_benc2: " << be_out.done_benc2
                                  << " done_mul: " << mul_out.done_mul << std::endl;
                    if (be_out.done_benc && be_out.done_benc2 && mul_out.done_mul) {
                        std::cout << "[KeyGen] State: BENC2 & MUL--------3\n";

                        for (int j = 0; j < 3; ++j)
                            for (int i = 0; i < 256; ++i)
                                be_in.benc_in[j][i] = mul_out.t[j][i];

                        be_in.start_benc = 1;
                        be_in.start_benc1 = 1;
                        be_in.start_benc2 = 0;
                        state = BYTE_ENCODE;
                    }
                    break;
                }
                case BYTE_ENCODE: {
                    std::cout << "[KeyGen] State: BENC1\n";
                    //comb_out = in_comb.get();
                    byenc::my_function(be_in, be_out);
                    if(be_out.done_benc1 && be_out.done_benc){
                        for(int i = 0; i < 32; i++)
                            be_out.ekpke_benc1[i + 1152] = rho_benc1[i];

                        for (int i = 0; i < 1184; i++)
                            comb_in.ek[i] = be_out.ekpke_benc1[i];

                        comb_in.start_g = 0;
                        comb_in.start_prf = 0;
                        comb_in.start_sntt = 0;
                        comb_in.start_h = 1;
                        out_comb.put(comb_in);
                        state = H;
                    }
                    break;
                }
                case H: {
                    std::cout << "[KeyGen] State: H\n";
                    comb_out = in_comb.get();

                    if (comb_out.done_h) {
                        state = FUSE;
                    }
                    break;
                }
                case FUSE: {
                    std::cout << "[KeyGen] State: FUSE\n";
                    for (int i = 0; i < 1184; i++)
                        output_val.ek[i] = be_out.ekpke_benc1[i];

                    for (int i = 0; i < 1152; i++)
                        output_val.dk[i] = be_out.dkpke_benc2[i];

                    for (int i = 0; i < 1184; i++)
                        output_val.dk[i + 1152] = be_out.ekpke_benc1[i];

                    for (int i = 0; i < 32; i++)
                        output_val.dk[i + 1152 + 1184] = comb_out.H_ek[i];

                    for (int i = 0; i < 32; i++)
                        output_val.dk[i + 1152 + 1184 + 32] = input_val.z[i];

                    state = FINISH;
                    break;
                }
                case FINISH: {
                    std::cout << "[KeyGen] State: FINISH\n";
                    output_val.done_kg = 1;
                    in10.put(output_val);
                    state = IDLE;
                    break;
                }
            }
            wait();
        }
    }
};

#endif // ALL_IN_ONE_H
