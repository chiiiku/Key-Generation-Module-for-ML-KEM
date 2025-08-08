#ifndef KeyGen_INPUT_DT_SC_WRAPPER_TYPE
#define KeyGen_INPUT_DT_SC_WRAPPER_TYPE 1

#include "cynw_memory.h"

struct KeyGen_INPUT_DT
{
    //
    // Member declarations.
    //
    sc_uint< 8 > d[32];
    sc_uint< 8 > z[32];
    sc_uint< 1 > start_kg;
    
    typedef sc_biguint< 513 > raw_type;
    
    //
    // Default constructor.
    //
    KeyGen_INPUT_DT()
    {
        CYN_FLATTEN(d);
        CYN_FLATTEN(z);
    }
    
    //
    // Copy constructor.
    //
    KeyGen_INPUT_DT( const KeyGen_INPUT_DT& other )
    {
        CYN_FLATTEN(d);
        CYN_FLATTEN(z);
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                d[i0] = other.d[i0];
            }
        }
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                z[i0] = other.z[i0];
            }
        }
        start_kg = other.start_kg;
    }
    
    //
    // Comparison operator.
    //
    inline bool operator == ( const KeyGen_INPUT_DT& other )
    {
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                if ( !(d[i0] == other.d[i0]) )
                    return false;
            }
        }
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                if ( !(z[i0] == other.z[i0]) )
                    return false;
            }
        }
        if ( !(start_kg == other.start_kg) )
            return false;
        return true;
    }
    
    //
    // Assignment operator from KeyGen_INPUT_DT.
    //
    inline KeyGen_INPUT_DT& operator = ( const KeyGen_INPUT_DT& other )
    {
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                d[i0] = other.d[i0];
            }
        }
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                z[i0] = other.z[i0];
            }
        }
        start_kg = other.start_kg;
        return *this;
    }
    
};
//
// sc_trace function.
//
inline void sc_trace( sc_trace_file* tf, const KeyGen_INPUT_DT& object, const std::string& in_name )
{
    if (tf)
    {
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                std::stringstream ss_out;
                ss_out << in_name << ".d" << "(" << i0 << ")" << std::ends;
                tf->trace( object.d[i0], std::string( ss_out.str() ));
            }
        }
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                std::stringstream ss_out;
                ss_out << in_name << ".z" << "(" << i0 << ")" << std::ends;
                tf->trace( object.z[i0], std::string( ss_out.str() ));
            }
        }
        tf->trace( object.start_kg, in_name + std::string(".start_kg"));
    }
}

//
// stream operator.
//
inline ostream & operator << ( ostream & os, const KeyGen_INPUT_DT& object )
{
#ifndef STRATUS_HLS
    os << "(";
    {
        os << "(";
        for ( int i0=0; i0 < 32; i0++ ) {
            os << " " << object.d[i0];
        }
        os << ")";
    }
    {
        os << "(";
        for ( int i0=0; i0 < 32; i0++ ) {
            os << " " << object.z[i0];
        }
        os << ")";
    }
    os <<  object.start_kg;
    os << ")";
#endif
    return os;
}

//
// cynw_interpret function to generate a flat vector.
//
inline void cynw_interpret ( KeyGen_INPUT_DT& from, KeyGen_INPUT_DT::raw_type& to )
{
    to = (
                from.d[0],
                from.d[1],
                from.d[2],
                from.d[3],
                from.d[4],
                from.d[5],
                from.d[6],
                from.d[7],
                from.d[8],
                from.d[9],
                from.d[10],
                from.d[11],
                from.d[12],
                from.d[13],
                from.d[14],
                from.d[15],
                from.d[16],
                from.d[17],
                from.d[18],
                from.d[19],
                from.d[20],
                from.d[21],
                from.d[22],
                from.d[23],
                from.d[24],
                from.d[25],
                from.d[26],
                from.d[27],
                from.d[28],
                from.d[29],
                from.d[30],
                from.d[31],
                from.z[0],
                from.z[1],
                from.z[2],
                from.z[3],
                from.z[4],
                from.z[5],
                from.z[6],
                from.z[7],
                from.z[8],
                from.z[9],
                from.z[10],
                from.z[11],
                from.z[12],
                from.z[13],
                from.z[14],
                from.z[15],
                from.z[16],
                from.z[17],
                from.z[18],
                from.z[19],
                from.z[20],
                from.z[21],
                from.z[22],
                from.z[23],
                from.z[24],
                from.z[25],
                from.z[26],
                from.z[27],
                from.z[28],
                from.z[29],
                from.z[30],
                from.z[31],
                from.start_kg
                );
}

//
// cynw_interpret function to generate a KeyGen_INPUT_DT from a flat vector.
//
inline void cynw_interpret ( const KeyGen_INPUT_DT::raw_type& from, KeyGen_INPUT_DT& to )
{
    cynw_interpret( (sc_uint<8>)from.range( 512,505 ), to.d[0] );
    cynw_interpret( (sc_uint<8>)from.range( 504,497 ), to.d[1] );
    cynw_interpret( (sc_uint<8>)from.range( 496,489 ), to.d[2] );
    cynw_interpret( (sc_uint<8>)from.range( 488,481 ), to.d[3] );
    cynw_interpret( (sc_uint<8>)from.range( 480,473 ), to.d[4] );
    cynw_interpret( (sc_uint<8>)from.range( 472,465 ), to.d[5] );
    cynw_interpret( (sc_uint<8>)from.range( 464,457 ), to.d[6] );
    cynw_interpret( (sc_uint<8>)from.range( 456,449 ), to.d[7] );
    cynw_interpret( (sc_uint<8>)from.range( 448,441 ), to.d[8] );
    cynw_interpret( (sc_uint<8>)from.range( 440,433 ), to.d[9] );
    cynw_interpret( (sc_uint<8>)from.range( 432,425 ), to.d[10] );
    cynw_interpret( (sc_uint<8>)from.range( 424,417 ), to.d[11] );
    cynw_interpret( (sc_uint<8>)from.range( 416,409 ), to.d[12] );
    cynw_interpret( (sc_uint<8>)from.range( 408,401 ), to.d[13] );
    cynw_interpret( (sc_uint<8>)from.range( 400,393 ), to.d[14] );
    cynw_interpret( (sc_uint<8>)from.range( 392,385 ), to.d[15] );
    cynw_interpret( (sc_uint<8>)from.range( 384,377 ), to.d[16] );
    cynw_interpret( (sc_uint<8>)from.range( 376,369 ), to.d[17] );
    cynw_interpret( (sc_uint<8>)from.range( 368,361 ), to.d[18] );
    cynw_interpret( (sc_uint<8>)from.range( 360,353 ), to.d[19] );
    cynw_interpret( (sc_uint<8>)from.range( 352,345 ), to.d[20] );
    cynw_interpret( (sc_uint<8>)from.range( 344,337 ), to.d[21] );
    cynw_interpret( (sc_uint<8>)from.range( 336,329 ), to.d[22] );
    cynw_interpret( (sc_uint<8>)from.range( 328,321 ), to.d[23] );
    cynw_interpret( (sc_uint<8>)from.range( 320,313 ), to.d[24] );
    cynw_interpret( (sc_uint<8>)from.range( 312,305 ), to.d[25] );
    cynw_interpret( (sc_uint<8>)from.range( 304,297 ), to.d[26] );
    cynw_interpret( (sc_uint<8>)from.range( 296,289 ), to.d[27] );
    cynw_interpret( (sc_uint<8>)from.range( 288,281 ), to.d[28] );
    cynw_interpret( (sc_uint<8>)from.range( 280,273 ), to.d[29] );
    cynw_interpret( (sc_uint<8>)from.range( 272,265 ), to.d[30] );
    cynw_interpret( (sc_uint<8>)from.range( 264,257 ), to.d[31] );
    cynw_interpret( (sc_uint<8>)from.range( 256,249 ), to.z[0] );
    cynw_interpret( (sc_uint<8>)from.range( 248,241 ), to.z[1] );
    cynw_interpret( (sc_uint<8>)from.range( 240,233 ), to.z[2] );
    cynw_interpret( (sc_uint<8>)from.range( 232,225 ), to.z[3] );
    cynw_interpret( (sc_uint<8>)from.range( 224,217 ), to.z[4] );
    cynw_interpret( (sc_uint<8>)from.range( 216,209 ), to.z[5] );
    cynw_interpret( (sc_uint<8>)from.range( 208,201 ), to.z[6] );
    cynw_interpret( (sc_uint<8>)from.range( 200,193 ), to.z[7] );
    cynw_interpret( (sc_uint<8>)from.range( 192,185 ), to.z[8] );
    cynw_interpret( (sc_uint<8>)from.range( 184,177 ), to.z[9] );
    cynw_interpret( (sc_uint<8>)from.range( 176,169 ), to.z[10] );
    cynw_interpret( (sc_uint<8>)from.range( 168,161 ), to.z[11] );
    cynw_interpret( (sc_uint<8>)from.range( 160,153 ), to.z[12] );
    cynw_interpret( (sc_uint<8>)from.range( 152,145 ), to.z[13] );
    cynw_interpret( (sc_uint<8>)from.range( 144,137 ), to.z[14] );
    cynw_interpret( (sc_uint<8>)from.range( 136,129 ), to.z[15] );
    cynw_interpret( (sc_uint<8>)from.range( 128,121 ), to.z[16] );
    cynw_interpret( (sc_uint<8>)from.range( 120,113 ), to.z[17] );
    cynw_interpret( (sc_uint<8>)from.range( 112,105 ), to.z[18] );
    cynw_interpret( (sc_uint<8>)from.range( 104,97 ), to.z[19] );
    cynw_interpret( (sc_uint<8>)from.range( 96,89 ), to.z[20] );
    cynw_interpret( (sc_uint<8>)from.range( 88,81 ), to.z[21] );
    cynw_interpret( (sc_uint<8>)from.range( 80,73 ), to.z[22] );
    cynw_interpret( (sc_uint<8>)from.range( 72,65 ), to.z[23] );
    cynw_interpret( (sc_uint<8>)from.range( 64,57 ), to.z[24] );
    cynw_interpret( (sc_uint<8>)from.range( 56,49 ), to.z[25] );
    cynw_interpret( (sc_uint<8>)from.range( 48,41 ), to.z[26] );
    cynw_interpret( (sc_uint<8>)from.range( 40,33 ), to.z[27] );
    cynw_interpret( (sc_uint<8>)from.range( 32,25 ), to.z[28] );
    cynw_interpret( (sc_uint<8>)from.range( 24,17 ), to.z[29] );
    cynw_interpret( (sc_uint<8>)from.range( 16,9 ), to.z[30] );
    cynw_interpret( (sc_uint<8>)from.range( 8,1 ), to.z[31] );
    cynw_interpret( (sc_uint<1>)from.range( 0,0 ), to.start_kg );
}


template <>
struct cynw_sc_wrap< KeyGen_INPUT_DT >
{
    typedef KeyGen_INPUT_DT spec;
    typedef KeyGen_INPUT_DT sc;
};
#endif


