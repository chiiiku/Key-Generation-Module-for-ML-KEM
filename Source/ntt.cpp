
#include "ntt.h"
#define N 256  // Vector length
#define Q 3329 // Modulus
#include "zeta.h"

sc_uint<16> mod_add(sc_uint<16> a, sc_uint<16> b) {
    sc_uint<16> sum = a + b;
    if (sum >= Q) sum -= Q;
    return sum;
}

// Modular subtraction
sc_uint<16> mod_sub(sc_uint<16> a, sc_uint<16> b) {
    return (a >= b) ? (a - b) : (a + Q - b);
}

// Modular multiplication
sc_uint<16> mod_mul(sc_uint<16> a, sc_uint<16> b) {
    //const sc_uint<16> Q = 3329;

    sc_uint<32> prod = (sc_uint<32>)a * b;
    sc_uint<16> res = prod % Q;

    return res;
}



void Ntt(sc_uint<16> *f) {
    sc_uint<16> len, start, j, k = 1;

    for (len = N >> 1; len >= 2; len = (len >> 1)) {
        for (start = 0; start < N; start += (len << 1)) {
            sc_uint<16> zeta = zeta::zetas[k];
            k++;
            for (j = start; j < start + len ; j++) {
                sc_uint<32> t = mod_mul(zeta, f[j + len]);
                f[j + len] = mod_sub(f[j], t);
                f[j] = mod_add(f[j], t);
            }
        }
    }
}


// The thread function for the design
void ntt::NTT()
{
    ntt_INPUT_DT  input_val;
    //ntt_INPUT_DT in;
    ntt_OUTPUT_DT output_val;
    // Reset the interfaces
    {
        CYN_PROTOCOL("reset");

        inputs.reset();
        outputs.reset();

        wait();
    }

    // Main execution loop
    while (1)
    {
        input_val = inputs.get();
        if(input_val.start_ntt){
            output_val.done_ntt = 0;
        }
        output_val = my_function(input_val);
        outputs.put(output_val);
    }
}
//
//  User's computation function
//
ntt_OUTPUT_DT ntt::my_function(ntt_INPUT_DT var)
{
    ntt_OUTPUT_DT my_outputs;
    std::cout << "hello nttttttttt: " << std::endl;

    // Computation
        sc_uint<16> output_temp[6][256];
        sc_uint<16> input_temp[256];
        for(int j=0; j<256; j++){
            input_temp[j] = 0;
        }

        for( int i=0; i<6;i++){
            for(int j=0; j<256; j++){
                input_temp[j] = var.se_ntt[i][j];
            }
            Ntt(input_temp);
            for(int j=0; j<256; j++){
                my_outputs.se_arr[i][j] = input_temp[j];
            }
        }

        std::cout << "nttttttttttt:" << std::endl;
        for(int j = 0; j < 6; j++){
            for (int i = 0; i < 256; ++i) {
                std::cout << std::dec << my_outputs.se_arr[j][i] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

    my_outputs.done_ntt = 1;

    return (my_outputs);
}

