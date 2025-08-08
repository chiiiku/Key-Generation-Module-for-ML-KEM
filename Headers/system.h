#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <systemc.h>
#include <esc.h>
#include <cynw_p2p.h>

// Data types
#include "tb.h"
#include "top_to_tb.h"
#include "KeyGen_input_type.h"
#include "KeyGen_output_type.h"
#include "ntt_input_type.h"
#include "ntt_output_type.h"
//#include "benc1_input_type.h"
//#include "benc1_output_type.h"
//#include "benc2_input_type.h"
//#include "benc2_output_type.h"
#include "mul_input_type.h"
#include "mul_output_type.h"
#include "combined_input_type.h"
#include "combined_output_type.h"

// Wrappers
#include "KeyGen_wrap.h"
#include "ntt_wrap.h"
//#include "benc1_wrap.h"
//#include "benc2_wrap.h"
#include "mul_wrap.h"
#include "combined_wrap.h"

// FSM Controller
#include "all_in_one.h"

SC_MODULE(TOP)
{
public:
    // Clock and reset
    sc_clock clk;
    sc_signal<bool> rst;

    // Top-level input/output
    cynw_p2p<KeyGen_INPUT_DT> inputs_chan;
    cynw_p2p<KeyGen_OUTPUT_DT> outputs_chan;

    // All-in-One <-> Submodule channels
    cynw_p2p<KeyGen_INPUT_DT> to_top;
    cynw_p2p<KeyGen_INPUT_DT> to_sub;
    cynw_p2p<KeyGen_OUTPUT_DT> allinone_to_kg_out_chan;

    cynw_p2p<combined_INPUT_DT> combined_in_chan;
    cynw_p2p<combined_OUTPUT_DT> combined_out_chan;

    cynw_p2p<ntt_INPUT_DT> ntt_in_chan;
    cynw_p2p<ntt_OUTPUT_DT> ntt_out_chan;

    cynw_p2p<mul_INPUT_DT> mul_in_chan;
    cynw_p2p<mul_OUTPUT_DT> mul_out_chan;

//    cynw_p2p<benc1_INPUT_DT> benc1_in_chan;
//    cynw_p2p<benc1_OUTPUT_DT> benc1_out_chan;

//    cynw_p2p<benc2_INPUT_DT> benc2_in_chan;
//    cynw_p2p<benc2_OUTPUT_DT> benc2_out_chan;

    // Modules
    tb*              m_tb;
    top_to_tb*       m_top_tb;
    KeyGen_wrapper*  m_dut;
    all_in_one*      m_allinone;

    combined_wrapper* m_combined;
    ntt_wrapper*      m_ntt;
    mul_wrapper*      m_mul;
//    benc1_wrapper*    m_benc1;
//    benc2_wrapper*    m_benc2;

    void initInstances();
    void deleteInstances();

    SC_CTOR(TOP)
        : clk("clk", CLOCK_PERIOD, SC_NS, 0.5, 0, SC_NS, true),
          rst("rst"),

          inputs_chan("inputs_chan"),
          outputs_chan("outputs_chan"),
          to_top("to_top"),
          to_sub("to_sub"),
          allinone_to_kg_out_chan("allinone_to_kg_out_chan"),

          combined_in_chan("combined_in_chan"),
          combined_out_chan("combined_out_chan"),

          ntt_in_chan("ntt_in_chan"),
          ntt_out_chan("ntt_out_chan"),

          mul_in_chan("mul_in_chan"),
          mul_out_chan("mul_out_chan")

//          benc1_in_chan("benc1_in_chan"),
//          benc1_out_chan("benc1_out_chan"),

//          benc2_in_chan("benc2_in_chan"),
//          benc2_out_chan("benc2_out_chan")
    {
        initInstances();
    }

    ~TOP() {
        deleteInstances();
    }
};

#endif // SYSTEM_H_INCLUDED
