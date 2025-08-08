#ifndef __KEYGEN__H
#define __KEYGEN__H

#include "cynw_p2p.h"

#include "KeyGen_input_type.h"
#include "KeyGen_output_type.h"

//#include "ntt_input_type.h"
//#include "ntt_output_type.h"
//#include "combined_input_type.h"
//#include "combined_output_type.h"
//#include "benc1_input_type.h"
//#include "benc1_output_type.h"
//#include "benc2_input_type.h"
//#include "benc2_output_type.h"
//#include "mul_input_type.h"
//#include "mul_output_type.h"


SC_MODULE(KeyGen)
{
    public:
    cynw_p2p < KeyGen_INPUT_DT  >::in     inputs;
    cynw_p2p < KeyGen_OUTPUT_DT >::out    outputs;

    // Declaration of clock and reset parameters
    sc_in_clk               clk;
    sc_in < bool >          rst;
    SC_CTOR(KeyGen):inputs("inputs"), outputs("outputs"), clk("clk"), rst("rst")
    {
        SC_CTHREAD(thread1, clk.pos());
        set_stack_size(0x200000);
        reset_signal_is(rst,0);

        // Connect the clk and rst signals to the metaports
        inputs.clk_rst(clk, rst);
        outputs.clk_rst(clk, rst);
    }
    void thread1();

    KeyGen_OUTPUT_DT my_function(KeyGen_INPUT_DT);
};

#endif
