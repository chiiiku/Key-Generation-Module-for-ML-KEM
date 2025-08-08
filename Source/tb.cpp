#include "tb.h"

// Source thread
void tb::source()
{
    KeyGen_INPUT_DT var1;

    // Reset the output metaport and cycle the design's reset
    outputs.reset();
    rst = 0;
    var1.start_kg = 0;
    wait(2);
    rst = 1;
    wait();

        sc_uint<8> values[32] = {
            0xf6, 0x88, 0x56, 0x3f, 0x7c, 0x66, 0xa5, 0xda,
            0x2d, 0x8b, 0xdb, 0x5a, 0x5f, 0x3e, 0x07, 0xbd,
            0x8d, 0xce, 0x6f, 0x7e, 0xfc, 0xec, 0x7f, 0x41,
            0x29, 0x8d, 0x79, 0x86, 0x34, 0x59, 0xf7, 0xcd
        };

        sc_uint<8> z[32] = {
            0xd1, 0xd4, 0x9a, 0x51, 0x52, 0x50, 0xdb, 0xce,
            0xb9, 0xf6, 0xe3, 0xfc, 0xc1, 0xc7, 0xd5, 0x30,
            0x69, 0x18, 0x96, 0x4b, 0x21, 0xdd, 0xb2, 0x22,
            0x07, 0xe0, 0x3e, 0x57, 0xf0, 0x60, 0x0d, 0xa8
        };

        for(int i = 0; i < 32; i++){
                var1.d[i] = values[i];
                var1.z[i] = z[i];
        }

        var1.start_kg = 1;

        std::cout << "d:" << std::endl;
            for (int i = 0; i < 32; ++i) {
                 std::cout << std::hex << var1.d[i] << " ";
            }
            std::cout << std::endl;

            std::cout << "z:" << std::endl;
                for (int i = 0; i < 32; ++i) {
                     std::cout << std::hex << var1.z[i] << " ";
                }
                std::cout << std::endl;

                outputs.put(var1);
}

// Read all the expected values from the design
void tb::sink()
{
    inputs.reset();
    wait();                     // to synchronize with reset


    KeyGen_OUTPUT_DT mat;
           mat = inputs.get();
           std::cout << "ek:" << std::endl;
               for (int i = 0; i < 1184; ++i) {
                    std::cout << std::hex << mat.ek[i] << " ";
               }
               std::cout << std::endl;

               std::cout << "dk:" << std::endl;
                   for (int i = 0; i < 2400; ++i) {
                        std::cout << std::hex << mat.dk[i] << " ";
                   }
                   std::cout << std::endl;

    printf("NOTE: You need to add code to the tb.cpp file in order to get a working simulation.\n");

    esc_stop();
}
