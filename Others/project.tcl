######################################################################
# Technology library used for gate-level timing estimation.
######################################################################
use_tech_lib    "/home/vlsilab/saed90nm_typ.lib"

######################################################################
# C++ compiler options
######################################################################
set CLOCK_PERIOD 100
set_attr cc_options " -DCLOCK_PERIOD=$CLOCK_PERIOD"
set_attr hls_cc_options " -DCLOCK_PERIOD=$CLOCK_PERIOD"

######################################################################
# Stratus options for all hls_configs
######################################################################
set_attr clock_period           $CLOCK_PERIOD
set_attr message_detail         2
set_attr cycle_slack            [expr $CLOCK_PERIOD * 0.1]
set_attr path_delay_limit       110
set_attr rtl_annotation         op,stack
set_attr flatten_arrays         none
set_attr dpopt_auto             op
set_attr lsb_trimming           on
set_attr inline_partial_constants on
set_attr relax_timing on
#set_attr default_input_delay 0.3
set_attr unroll_loops off
######################################################################
# System Level (testbench) Modules
######################################################################
define_system_module main.cpp
define_system_module system.cpp
define_system_module tb.cpp

######################################################################
# Modules to be synthesized
######################################################################
define_hls_module KeyGen KeyGen.cpp
define_hls_module ntt ntt.cpp
define_hls_module mul mul.cpp
define_hls_module combined combined.cpp

######################################################################
# HLS configurations
######################################################################
define_hls_config KeyGen BASIC
define_hls_config KeyGen GATING --power_clock_gating=on
define_hls_config ntt BASIC
define_hls_config mul BASIC
define_hls_config combined GATING --power_clock_gating=off

######################################################################
# post_elab_tcl: apply default_output_delay globally
######################################################################
#proc post_elab_tcl {} {
#    set_attr default_output_delay 0.3
#}

######################################################################
# Genus Logic Synthesis Configurations
######################################################################
define_logic_synthesis_config G {KeyGen -all}
#define_logic_synthesis_config comb1 {combined -all}

######################################################################
# Simulation Settings
######################################################################
use_verilog_simulator xcelium
enable_waveform_logging -vcd
set_attr end_of_sim_command "make cmp_result"

######################################################################
# Define a behavioral simulation configuration for each hls_config
######################################################################
foreach config [find -hls_config *] {
  set cname [get_attr name $config]
  set mod   [get_attr hls_module $config]
  define_sim_config ${mod}_${cname}_B "$mod BEH $cname"
}

######################################################################
# Define an RTL simulation configuration for each hls_config
# and a power analysis config for each RTL simulation config
######################################################################
foreach config [find -hls_config *] {
  set cname [get_attr name $config]
  set mod   [get_attr hls_module $config]
  define_sim_config ${mod}_${cname}_V "$mod RTL_V $cname"
  define_power_config P_${mod}_${cname} ${mod}_${cname}_V -module $mod -command bdw_runsjoules
}

