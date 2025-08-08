#ifndef __KECCACK__H
#define __KECCACK__H

#include <systemc.h>

#define KECCAKF_ROUNDS 24

namespace keccack {
namespace constants {
    // Round constants
    const sc_dt::sc_uint<64> rndc[24] = {
        0x0000000000000001ULL, 0x0000000000008082ULL, 0x800000000000808AULL,
        0x8000000080008000ULL, 0x000000000000808BULL, 0x0000000080000001ULL,
        0x8000000080008081ULL, 0x8000000000008009ULL, 0x000000000000008AULL,
        0x0000000000000088ULL, 0x0000000080008009ULL, 0x000000008000000AULL,
        0x000000008000808BULL, 0x800000000000008BULL, 0x8000000000008089ULL,
        0x8000000000008003ULL, 0x8000000000008002ULL, 0x8000000000000080ULL,
        0x000000000000800AULL, 0x800000008000000AULL, 0x8000000080008081ULL,
        0x8000000000008080ULL, 0x0000000080000001ULL, 0x8000000080008008ULL
    };
    //HLS_MAP_TO_MEMORY(rndc);


    // Rotation constants
    const sc_dt::sc_uint<6> rotc[24] = {
        1,  3,  6, 10, 15, 21, 28, 36, 45, 55, 2, 14,
        27, 41, 56, 8, 25, 43, 62, 18, 39, 61, 20, 44
    };
    //HLS_MAP_TO_MEMORY(rotc);

    // Pi lane indices
    const sc_dt::sc_uint<5> piln[24] = {
        10,  7, 11, 17, 18, 3,  5, 16, 8, 21, 24, 4,
        15, 23, 19, 13, 12, 2, 20, 14, 22, 9,  6,  1
    };
    //HLS_MAP_TO_MEMORY(piln);

    // Modular arithmetic LUTs
    const sc_dt::sc_uint<3> plus1mod5[5] = {1, 2, 3, 4, 0};
    //HLS_MAP_TO_MEMORY(plus1mod5);
    const sc_dt::sc_uint<3> plus4mod5[5] = {4, 0, 1, 2, 3};
    //HLS_MAP_TO_MEMORY(plus4mod5);
} // namespace constants

// Theta step computation
void theta_step(sc_dt::sc_uint<64> state[25], sc_dt::sc_uint<64> bc[5]) {
    for (int i = 0; i < 5; i++) {
        bc[i] = state[i] ^ state[i + 5] ^ state[i + 10]
              ^ state[i + 15] ^ state[i + 20];
    }

    for (int i = 0; i < 5; i++) {
        sc_uint<3> idx1 = constants::plus4mod5[i];
        sc_uint<3> idx2 = constants::plus1mod5[i];
        sc_dt::sc_uint<64> t = bc[idx1] ^ ((bc[idx2] << 1) | (bc[idx2] >> 63));

        for (int j = 0; j < 25; j += 5) {
            state[j + i] ^= t;
        }
    }
}

// Rho + Pi steps computation
void rho_pi_step(sc_dt::sc_uint<64> state[25]) {
    sc_dt::sc_uint<64> t = state[1];
    sc_dt::sc_uint<64> bc[1]; // Temporary storage

    for (int i = 0; i < 24; i++) {
        sc_dt::sc_uint<5> j = constants::piln[i];
        bc[0] = state[j];
        state[j] = (t << constants::rotc[i]) | (t >> (64 - constants::rotc[i]));
        t = bc[0];
    }
}

// Chi step computation
void chi_step(sc_dt::sc_uint<64> state[25]) {
    sc_dt::sc_uint<64> bc[5];

    for (int j = 0; j < 25; j += 5) {
        for (int i = 0; i < 5; i++) {
            bc[i] = state[j + i];
        }

        for (int i = 0; i < 5; i++) {
            sc_uint<3> idx1 = constants::plus1mod5[i];
            sc_uint<3> idx2 = constants::plus1mod5[idx1];
            state[j + i] ^= (~bc[idx1]) & bc[idx2];
        }
    }
}

// Main Keccak-f permutation
void keccakf(sc_dt::sc_uint<64> state[25]) {

    sc_dt::sc_uint<64> bc[5];

    for (int round = 0; round < KECCAKF_ROUNDS; round++) {

        theta_step(state, bc);
        rho_pi_step(state);
        chi_step(state);

        // Iota step (merged into chi step)
        state[0] ^= constants::rndc[round];
    }
}
} // namespace keccack

#endif // __KECCACK__H
