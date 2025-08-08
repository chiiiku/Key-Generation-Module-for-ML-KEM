#ifndef BENC_STRUCT_H
#define BENC_STRUCT_H

typedef struct byteEncode_in{
    sc_uint<1> start_benc;
    sc_uint<1> start_benc1;
    sc_uint<1> start_benc2;
    sc_uint<16> benc_in[3][256];
} BENC_in;

typedef struct byteEncode_out{
    sc_uint<1> done_benc;
    sc_uint<1> done_benc1;
    sc_uint<1> done_benc2;
    sc_uint<8> ekpke_benc1[1184];
    sc_uint<8> dkpke_benc2[1152];
} BENC_out;

#endif // BENC_STRUCT_H
