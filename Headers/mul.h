
#ifndef __MUL__H
#define __MUL__H

#include "cynw_p2p.h"


#include "mul_input_type.h"
#include "mul_output_type.h"

SC_MODULE(mul)
{
    public:
    cynw_p2p < mul_INPUT_DT  >::in     inputs;
    cynw_p2p < mul_OUTPUT_DT >::out    outputs;
    
    // Declaration of clock and reset parameters
    sc_in_clk               clk;
    sc_in < bool >          rst;
    SC_CTOR(mul):inputs("inputs"), outputs("outputs"), clk("clk"), rst("rst")
    {
        SC_CTHREAD(Mul, clk.pos());
        set_stack_size(0x200000);
        reset_signal_is(rst,0);
        
        // Connect the clk and rst signals to the metaports
        inputs.clk_rst(clk, rst);
        outputs.clk_rst(clk, rst);
    }
    void Mul();
    
    mul_OUTPUT_DT my_function(mul_INPUT_DT);
};

#endif

