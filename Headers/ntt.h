
#ifndef __NTT__H
#define __NTT__H

#include "cynw_p2p.h"

#include "ntt_input_type.h"
#include "ntt_output_type.h"


SC_MODULE(ntt)
{
    public:
    cynw_p2p < ntt_INPUT_DT  >::in     inputs;
    cynw_p2p < ntt_OUTPUT_DT >::out    outputs;
    
    // Declaration of clock and reset parameters
    sc_in_clk               clk;
    sc_in < bool >          rst;
    SC_CTOR(ntt):inputs("inputs"), outputs("outputs"), clk("clk"), rst("rst")
    {
        SC_CTHREAD(NTT, clk.pos());
        set_stack_size(0x200000);
        reset_signal_is(rst,0);
        
        // Connect the clk and rst signals to the metaports
        inputs.clk_rst(clk, rst);
        outputs.clk_rst(clk, rst);
    }
    void NTT();
    
    ntt_OUTPUT_DT my_function(ntt_INPUT_DT);
};

#endif

