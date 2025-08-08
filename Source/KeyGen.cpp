#include "KeyGen.h"

void KeyGen::thread1()
{

    KeyGen_INPUT_DT input_val;
    KeyGen_OUTPUT_DT output_val;


    {
        HLS_DEFINE_PROTOCOL("reset");
        inputs.reset();
        outputs.reset();
        wait();
    }

    while (1)
    {
        input_val = inputs.get();  // from testbench
        if(input_val.start_kg){
            output_val.done_kg = 0;
        }

        //output_val = my_function(input_val);
        outputs.put(output_val);


        wait();  // advance time every loop
    }
}
