#include "mul.h"
#include "zeta.h"
#include <cstdlib> // for abs()

#define K 3
#define N 256
#define Q 3329

void ntt_base_multiplication(sc_uint<16> *r0, sc_uint<16> *r1,
                            sc_uint<16> a0, sc_uint<16> a1,
                            sc_uint<16> b0, sc_uint<16> b1,
                            sc_uint<16> zeta) {
    sc_int<32> t0 = (sc_int<32>)a0 * b0;
    sc_int<32> t1 = (sc_int<32>)zeta * a1 % Q;
    t1 = t1 * b1 % Q;
    *r0 = (t0 + t1) % Q;

    sc_int<32> t2 = (sc_int<32>)a1 * b0 + (sc_int<32>)a0 * b1;
    *r1 = t2 % Q;
}

void poly_basemul_montgomery(sc_uint<16> r[N], const sc_uint<16> a[N], const sc_uint<16> b[N]) {
    for (int i = 0; i < 64; i++) {
        sc_uint<16> a0 = a[(i << 2)];
        sc_uint<16> a1 = a[(i << 2) + 1];
        sc_uint<16> a2 = a[(i << 2) + 2];
        sc_uint<16> a3 = a[(i << 2) + 3];

        sc_uint<16> b0 = b[(i << 2)];
        sc_uint<16> b1 = b[(i << 2) + 1];
        sc_uint<16> b2 = b[(i << 2) + 2];
        sc_uint<16> b3 = b[(i << 2) + 3];

        sc_uint<16> r0, r1, r2, r3;

        // first pair
        ntt_base_multiplication(&r0, &r1, a0, a1, b0, b1, zeta::zetas[64 + i]);

        // second pair with -zeta
        ntt_base_multiplication(&r2, &r3, a2, a3, b2, b3, (Q - zeta::zetas[64 + i]) % Q);

        r[(i << 2) + 0] = r0;
        r[(i << 2) + 1] = r1;
        r[(i << 2) + 2] = r2;
        r[(i << 2) + 3] = r3;
    }
}

void polyvec_pointwise_acc_montgomery(sc_uint<16> r[N], const sc_uint<16> a[K][N], const sc_uint<16> b[K][N]) {
    sc_uint<16> temp[N];

    // Initialize result with first multiplication
    poly_basemul_montgomery(r, a[0], b[0]);

    // Accumulate remaining multiplications
    for (int i = 1; i < K; i++) {
        poly_basemul_montgomery(temp, a[i], b[i]);
        for (int j = 0; j < N; j++) {
            r[j] = (r[j] + temp[j]) % Q;
        }
    }
}

void matrix_vector_mul(sc_uint<16> r[K][N], const sc_uint<16> A[K*K][N], const sc_uint<16> s[K][N]) {
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            r[i][j] = 0;
        }
        polyvec_pointwise_acc_montgomery(r[i], &A[K*i], s);
    }
}

void mul::Mul()
{
    mul_INPUT_DT input_val;
    mul_OUTPUT_DT output_val;

    {
        CYN_PROTOCOL("reset");
        inputs.reset();
        outputs.reset();
        wait();
    }

    while (1) {
        input_val = inputs.get();
        if(input_val.start_mul){
            output_val.done_mul = 0;
        }
        output_val = my_function(input_val);
        outputs.put(output_val);
    }
}

mul_OUTPUT_DT mul::my_function(mul_INPUT_DT var)
{
    mul_OUTPUT_DT my_outputs;
    std::cout << "hello mullllllllllllllllll: " << std::endl;

    sc_uint<16> A[K*K][N];
    sc_uint<16> s[K][N];
    sc_uint<16> e[K][N];
    sc_uint<16> t[K][N] = {0};

    for(int k = 0; k < 3; k++){
        for(int n = 0; n < 3; n++){
            for(int m = 0; m < 256; m++){
                A[k * K + n][m] = var.A_mul[((k<<1)+k) + n][m];
            }
        }
    }

    for(int n = 0; n < 3; n++){
        for(int m = 0; m < 256; m++){
            s[n][m] = var.se_mul[n][m];
            e[n][m] = var.se_mul[n + 3][m];
        }
    }

    // Compute t = A*s + e
    matrix_vector_mul(t, A, s);
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < N; j++) {
            t[i][j] = (t[i][j] + e[i][j]) % Q;
        }
    }

    for(int n = 0; n < 3; n++){
        for(int m = 0; m < 256; m++){
            my_outputs.t[n][m] = t[n][m];
        }
    }

    for(int j = 0; j < 3; j++){
        for (int i = 0; i < 256; ++i) {
            std::cout << std::hex << my_outputs.t[j][i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    my_outputs.done_mul = 1;
    return my_outputs;
}
