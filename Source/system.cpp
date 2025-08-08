#include "system.h"

void TOP::initInstances()
{
    // Testbench
    m_tb = new tb("tb");
    m_tb->clk(clk);
    m_tb->rst(rst);
    m_tb->outputs(inputs_chan);  // TB drives input
    m_tb->inputs(outputs_chan);  // TB reads output

    // KeyGen FSM Wrapper (dummy placeholder)
    m_dut = new KeyGen_wrapper("KeyGen_wrapper");
    m_dut->clk(clk);
    m_dut->rst(rst);
    m_dut->inputs(to_top);
    m_dut->outputs(allinone_to_kg_out_chan);

    // Top-to-TB connector
    m_top_tb = new top_to_tb("top_to_tb");
    m_top_tb->clk(clk);
    m_top_tb->rst(rst);
    m_top_tb->in(inputs_chan);
    m_top_tb->out1(to_top);
    m_top_tb->out2(to_sub);

    // All-in-One FSM block
    m_allinone = new all_in_one("all_in_one");
    m_allinone->clk(clk);
    m_allinone->rst(rst);
    m_allinone->in1(to_sub);                  // From KeyGen FSM
    m_allinone->in10(outputs_chan);           // Output to TB

    m_allinone->out_comb(combined_in_chan);   // Combined hash input
    m_allinone->in_comb(combined_out_chan);   // Combined hash output

    m_allinone->out5(ntt_in_chan);            // NTT
    m_allinone->in5(ntt_out_chan);

    m_allinone->out6(mul_in_chan);            // MUL
    m_allinone->in6(mul_out_chan);

//    m_allinone->out7(benc1_in_chan);          // BENC1
//    m_allinone->in7(benc1_out_chan);

//    m_allinone->out8(benc2_in_chan);          // BENC2
//    m_allinone->in8(benc2_out_chan);

    // === Module Wrappers ===

    // Combined Hash Module
    m_combined = new combined_wrapper("combined_wrapper");
    m_combined->clk(clk);
    m_combined->rst(rst);
    m_combined->inputs(combined_in_chan);
    m_combined->outputs(combined_out_chan);

    // NTT
    m_ntt = new ntt_wrapper("ntt_wrapper");
    m_ntt->clk(clk);
    m_ntt->rst(rst);
    m_ntt->inputs(ntt_in_chan);
    m_ntt->outputs(ntt_out_chan);

    // MUL
    m_mul = new mul_wrapper("mul_wrapper");
    m_mul->clk(clk);
    m_mul->rst(rst);
    m_mul->inputs(mul_in_chan);
    m_mul->outputs(mul_out_chan);

//    // BENC1
//    m_benc1 = new benc1_wrapper("benc1_wrapper");
//    m_benc1->clk(clk);
//    m_benc1->rst(rst);
//    m_benc1->inputs(benc1_in_chan);
//    m_benc1->outputs(benc1_out_chan);

//    // BENC2
//    m_benc2 = new benc2_wrapper("benc2_wrapper");
//    m_benc2->clk(clk);
//    m_benc2->rst(rst);
//    m_benc2->inputs(benc2_in_chan);
//    m_benc2->outputs(benc2_out_chan);
}

void TOP::deleteInstances()
{
    delete m_tb;
    delete m_dut;
    delete m_top_tb;
    delete m_allinone;

    delete m_combined;
    delete m_ntt;
    delete m_mul;
//    delete m_benc1;
//    delete m_benc2;
}
