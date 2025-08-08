#ifndef BYENC_H
#define BYENC_H

#include "benc_struct.h"
#include <systemc.h>

#define D 12
#define size 256
#define sizexd 3072

inline void ByteEncode(const sc_uint<16> *F, sc_uint<8> *b) {
    // Clear the output bit array
    for (int k = 0; k < sizexd; k++) {
        b[k] = 0;
    }

    for (int i = 0; i < size; i++) {
        sc_uint<16> a = F[i];
        for (int j = 0; j < D; j++) {
            b[i * D + j] = a[0];  // Extract LSB directly
            a = a >> 1;           // Logical shift right
        }
    }
}

// Convert bits into packed bytes
inline void BitsToBytes(const sc_uint<8> *b, sc_uint<8> *B) {
    int byteLen = sizexd >> 3;

    // Clear output byte array
    for (int k = 0; k < byteLen; k++) {
        B[k] = 0;
    }

    for (int i = 0; i < sizexd; i++) {
        sc_uint<8> temp = b[i];
        B[i >> 3] = B[i >> 3] | (temp << (i & 0x7));
    }
}

const sc_uint<16> idx_offset[3] = {0, 384, 768};

namespace byenc{
 inline void my_function(BENC_in var, BENC_out &my_outputs)
{
    //BENC_out my_outputs;
    std::cout << "hello beeeeeeeee: " << std::endl;
    my_outputs.done_benc = 0;
    my_outputs.done_benc1 = 0;
    my_outputs.done_benc2 = 0;
    // Computation
            sc_uint<8> b[3072];
            sc_uint<16> F[256];
            sc_uint<8> B[384];
if(var.start_benc){

    for (int j = 0; j < 256; j++) {
                F[j] = 0;
            }

            for (int i = 0; i < 3; i++) {
                // Load 256 values into F
                for (int j = 0; j < 256; j++) {
                    F[j] = var.benc_in[i][j];
                }

                // Encode F into b, then pack b into B
                ByteEncode(F, b);
                BitsToBytes(b, B);

                if(var.start_benc1){
                    for (int k = 0; k < 384; k++) {
                        my_outputs.ekpke_benc1[idx_offset[i] + k] = B[k];
                    }
                    my_outputs.done_benc1 = 1;
                }
                else if(var.start_benc2){
                    for (int k = 0; k < 384; k++) {
                        my_outputs.dkpke_benc2[idx_offset[i] + k] = B[k];
                    }
                    my_outputs.done_benc2 = 1;
                }

            }
    my_outputs.done_benc = 1;

}
}
} // namespace byenc

#endif // BYENC_H
