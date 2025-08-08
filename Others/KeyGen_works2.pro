#################################################
# Stratus IDE project file generated;
#################################################
QT       += core

QT       -= gui

CONFIG   += console
CONFIG   -= app_bundle

STRATUSHOME = $$(STRATUS_HOME)
SYSTEMCHOME = $$(SYSTEMC)

TEMPLATE = app
INCLUDEPATH += $${SYSTEMCHOME}/include
INCLUDEPATH += $${SYSTEMCHOME}/include/tlm
INCLUDEPATH += $${STRATUSHOME}/share/stratus/include
INCLUDEPATH += ./bdw_work/wrappers
INCLUDEPATH += ./

SOURCES += \ 
		combined.cpp \ 
		KeyGen.cpp \ 
		main.cpp \ 
		mul.cpp \ 
		ntt.cpp \ 
		system.cpp \ 
		tb.cpp \ 

HEADERS += \ 
		all_in_one.h \ 
		benc_struct.h \ 
		byenc.h \ 
		combined.h \ 
		combined_input_type.h \ 
		combined_output_type.h \ 
		keccack.h \ 
		KeyGen.h \ 
		KeyGen_input_type.h \ 
		KeyGen_output_type.h \ 
		mul.h \ 
		mul_input_type.h \ 
		mul_output_type.h \ 
		ntt.h \ 
		ntt_input_type.h \ 
		ntt_output_type.h \ 
		system.h \ 
		tb.h \ 
		top_to_tb.h \ 
		zeta.h \ 

OTHER_FILES += \ 
		Makefile \ 
		project.tcl \ 

