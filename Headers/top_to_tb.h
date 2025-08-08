#ifndef TOP_TO_TB_H
#define TOP_TO_TB_H

#include <systemc.h>
#include <cynw_p2p.h>

#include "KeyGen_input_type.h"

SC_MODULE(top_to_tb) {
    cynw_p2p_in<KeyGen_INPUT_DT> in;
    cynw_p2p_out<KeyGen_INPUT_DT> out1;
    cynw_p2p_out<KeyGen_INPUT_DT> out2;

    sc_in_clk clk;
    sc_in<bool> rst;

    SC_CTOR(top_to_tb) {
        SC_CTHREAD(process, clk.pos());
        set_stack_size(0x200000);
        reset_signal_is(rst, 0);

        in.clk_rst(clk, rst);
        out1.clk_rst(clk, rst);
        out2.clk_rst(clk, rst);
    }

    void process() {
        {
            HLS_DEFINE_PROTOCOL("reset");
            in.reset();
            out1.reset();
            out2.reset();
            wait();
        }

        while (true) {
            KeyGen_INPUT_DT val = in.get();
            out1.put(val);
            out2.put(val);
        }
    }
};

#endif // TOP_TO_TB_H
