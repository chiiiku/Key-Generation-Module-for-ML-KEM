#ifndef combined_INPUT_DT_SC_WRAPPER_TYPE
#define combined_INPUT_DT_SC_WRAPPER_TYPE 1

#include "cynw_memory.h"

struct combined_INPUT_DT
{
    //
    // Member declarations.
    //
    sc_uint< 8 > din[32];
    sc_uint< 8 > ek[1184];
    sc_uint< 8 > sigma[32];
    sc_uint< 8 > rho[32];
    sc_uint< 1 > start_g;
    sc_uint< 1 > start_h;
    sc_uint< 1 > start_prf;
    sc_uint< 1 > start_sntt;
    sc_uint< 1 > start_combined;
    
    typedef sc_biguint< 10245 > raw_type;
    
    //
    // Default constructor.
    //
    combined_INPUT_DT()
    {
        CYN_FLATTEN(din);
        CYN_FLATTEN(ek);
        CYN_FLATTEN(sigma);
        CYN_FLATTEN(rho);
    }
    
    //
    // Copy constructor.
    //
    combined_INPUT_DT( const combined_INPUT_DT& other )
    {
        CYN_FLATTEN(din);
        CYN_FLATTEN(ek);
        CYN_FLATTEN(sigma);
        CYN_FLATTEN(rho);
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                din[i0] = other.din[i0];
            }
        }
        {
            for ( int i0=0; i0 < 1184; i0++ ) {
                ek[i0] = other.ek[i0];
            }
        }
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                sigma[i0] = other.sigma[i0];
            }
        }
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                rho[i0] = other.rho[i0];
            }
        }
        start_g = other.start_g;
        start_h = other.start_h;
        start_prf = other.start_prf;
        start_sntt = other.start_sntt;
        start_combined = other.start_combined;
    }
    
    //
    // Comparison operator.
    //
    inline bool operator == ( const combined_INPUT_DT& other )
    {
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                if ( !(din[i0] == other.din[i0]) )
                    return false;
            }
        }
        {
            for ( int i0=0; i0 < 1184; i0++ ) {
                if ( !(ek[i0] == other.ek[i0]) )
                    return false;
            }
        }
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                if ( !(sigma[i0] == other.sigma[i0]) )
                    return false;
            }
        }
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                if ( !(rho[i0] == other.rho[i0]) )
                    return false;
            }
        }
        if ( !(start_g == other.start_g) )
            return false;
        if ( !(start_h == other.start_h) )
            return false;
        if ( !(start_prf == other.start_prf) )
            return false;
        if ( !(start_sntt == other.start_sntt) )
            return false;
        if ( !(start_combined == other.start_combined) )
            return false;
        return true;
    }
    
    //
    // Assignment operator from combined_INPUT_DT.
    //
    inline combined_INPUT_DT& operator = ( const combined_INPUT_DT& other )
    {
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                din[i0] = other.din[i0];
            }
        }
        {
            for ( int i0=0; i0 < 1184; i0++ ) {
                ek[i0] = other.ek[i0];
            }
        }
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                sigma[i0] = other.sigma[i0];
            }
        }
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                rho[i0] = other.rho[i0];
            }
        }
        start_g = other.start_g;
        start_h = other.start_h;
        start_prf = other.start_prf;
        start_sntt = other.start_sntt;
        start_combined = other.start_combined;
        return *this;
    }
    
};
//
// sc_trace function.
//
inline void sc_trace( sc_trace_file* tf, const combined_INPUT_DT& object, const std::string& in_name )
{
    if (tf)
    {
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                std::stringstream ss_out;
                ss_out << in_name << ".din" << "(" << i0 << ")" << std::ends;
                tf->trace( object.din[i0], std::string( ss_out.str() ));
            }
        }
        {
            for ( int i0=0; i0 < 1184; i0++ ) {
                std::stringstream ss_out;
                ss_out << in_name << ".ek" << "(" << i0 << ")" << std::ends;
                tf->trace( object.ek[i0], std::string( ss_out.str() ));
            }
        }
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                std::stringstream ss_out;
                ss_out << in_name << ".sigma" << "(" << i0 << ")" << std::ends;
                tf->trace( object.sigma[i0], std::string( ss_out.str() ));
            }
        }
        {
            for ( int i0=0; i0 < 32; i0++ ) {
                std::stringstream ss_out;
                ss_out << in_name << ".rho" << "(" << i0 << ")" << std::ends;
                tf->trace( object.rho[i0], std::string( ss_out.str() ));
            }
        }
        tf->trace( object.start_g, in_name + std::string(".start_g"));
        tf->trace( object.start_h, in_name + std::string(".start_h"));
        tf->trace( object.start_prf, in_name + std::string(".start_prf"));
        tf->trace( object.start_sntt, in_name + std::string(".start_sntt"));
        tf->trace( object.start_combined, in_name + std::string(".start_combined"));
    }
}

//
// stream operator.
//
inline ostream & operator << ( ostream & os, const combined_INPUT_DT& object )
{
#ifndef STRATUS_HLS
    os << "(";
    {
        os << "(";
        for ( int i0=0; i0 < 32; i0++ ) {
            os << " " << object.din[i0];
        }
        os << ")";
    }
    {
        os << "(";
        for ( int i0=0; i0 < 1184; i0++ ) {
            os << " " << object.ek[i0];
        }
        os << ")";
    }
    {
        os << "(";
        for ( int i0=0; i0 < 32; i0++ ) {
            os << " " << object.sigma[i0];
        }
        os << ")";
    }
    {
        os << "(";
        for ( int i0=0; i0 < 32; i0++ ) {
            os << " " << object.rho[i0];
        }
        os << ")";
    }
    os <<  object.start_g;
    os << "," <<  object.start_h;
    os << "," <<  object.start_prf;
    os << "," <<  object.start_sntt;
    os << "," <<  object.start_combined;
    os << ")";
#endif
    return os;
}

//
// cynw_interpret function to generate a flat vector.
//
inline void cynw_interpret ( combined_INPUT_DT& from, combined_INPUT_DT::raw_type& to )
{
    to = (
                from.din[0],
                from.din[1],
                from.din[2],
                from.din[3],
                from.din[4],
                from.din[5],
                from.din[6],
                from.din[7],
                from.din[8],
                from.din[9],
                from.din[10],
                from.din[11],
                from.din[12],
                from.din[13],
                from.din[14],
                from.din[15],
                from.din[16],
                from.din[17],
                from.din[18],
                from.din[19],
                from.din[20],
                from.din[21],
                from.din[22],
                from.din[23],
                from.din[24],
                from.din[25],
                from.din[26],
                from.din[27],
                from.din[28],
                from.din[29],
                from.din[30],
                from.din[31],
                from.ek[0],
                from.ek[1],
                from.ek[2],
                from.ek[3],
                from.ek[4],
                from.ek[5],
                from.ek[6],
                from.ek[7],
                from.ek[8],
                from.ek[9],
                from.ek[10],
                from.ek[11],
                from.ek[12],
                from.ek[13],
                from.ek[14],
                from.ek[15],
                from.ek[16],
                from.ek[17],
                from.ek[18],
                from.ek[19],
                from.ek[20],
                from.ek[21],
                from.ek[22],
                from.ek[23],
                from.ek[24],
                from.ek[25],
                from.ek[26],
                from.ek[27],
                from.ek[28],
                from.ek[29],
                from.ek[30],
                from.ek[31],
                from.ek[32],
                from.ek[33],
                from.ek[34],
                from.ek[35],
                from.ek[36],
                from.ek[37],
                from.ek[38],
                from.ek[39],
                from.ek[40],
                from.ek[41],
                from.ek[42],
                from.ek[43],
                from.ek[44],
                from.ek[45],
                from.ek[46],
                from.ek[47],
                from.ek[48],
                from.ek[49],
                from.ek[50],
                from.ek[51],
                from.ek[52],
                from.ek[53],
                from.ek[54],
                from.ek[55],
                from.ek[56],
                from.ek[57],
                from.ek[58],
                from.ek[59],
                from.ek[60],
                from.ek[61],
                from.ek[62],
                from.ek[63],
                from.ek[64],
                from.ek[65],
                from.ek[66],
                from.ek[67],
                from.ek[68],
                from.ek[69],
                from.ek[70],
                from.ek[71],
                from.ek[72],
                from.ek[73],
                from.ek[74],
                from.ek[75],
                from.ek[76],
                from.ek[77],
                from.ek[78],
                from.ek[79],
                from.ek[80],
                from.ek[81],
                from.ek[82],
                from.ek[83],
                from.ek[84],
                from.ek[85],
                from.ek[86],
                from.ek[87],
                from.ek[88],
                from.ek[89],
                from.ek[90],
                from.ek[91],
                from.ek[92],
                from.ek[93],
                from.ek[94],
                from.ek[95],
                from.ek[96],
                from.ek[97],
                from.ek[98],
                from.ek[99],
                from.ek[100],
                from.ek[101],
                from.ek[102],
                from.ek[103],
                from.ek[104],
                from.ek[105],
                from.ek[106],
                from.ek[107],
                from.ek[108],
                from.ek[109],
                from.ek[110],
                from.ek[111],
                from.ek[112],
                from.ek[113],
                from.ek[114],
                from.ek[115],
                from.ek[116],
                from.ek[117],
                from.ek[118],
                from.ek[119],
                from.ek[120],
                from.ek[121],
                from.ek[122],
                from.ek[123],
                from.ek[124],
                from.ek[125],
                from.ek[126],
                from.ek[127],
                from.ek[128],
                from.ek[129],
                from.ek[130],
                from.ek[131],
                from.ek[132],
                from.ek[133],
                from.ek[134],
                from.ek[135],
                from.ek[136],
                from.ek[137],
                from.ek[138],
                from.ek[139],
                from.ek[140],
                from.ek[141],
                from.ek[142],
                from.ek[143],
                from.ek[144],
                from.ek[145],
                from.ek[146],
                from.ek[147],
                from.ek[148],
                from.ek[149],
                from.ek[150],
                from.ek[151],
                from.ek[152],
                from.ek[153],
                from.ek[154],
                from.ek[155],
                from.ek[156],
                from.ek[157],
                from.ek[158],
                from.ek[159],
                from.ek[160],
                from.ek[161],
                from.ek[162],
                from.ek[163],
                from.ek[164],
                from.ek[165],
                from.ek[166],
                from.ek[167],
                from.ek[168],
                from.ek[169],
                from.ek[170],
                from.ek[171],
                from.ek[172],
                from.ek[173],
                from.ek[174],
                from.ek[175],
                from.ek[176],
                from.ek[177],
                from.ek[178],
                from.ek[179],
                from.ek[180],
                from.ek[181],
                from.ek[182],
                from.ek[183],
                from.ek[184],
                from.ek[185],
                from.ek[186],
                from.ek[187],
                from.ek[188],
                from.ek[189],
                from.ek[190],
                from.ek[191],
                from.ek[192],
                from.ek[193],
                from.ek[194],
                from.ek[195],
                from.ek[196],
                from.ek[197],
                from.ek[198],
                from.ek[199],
                from.ek[200],
                from.ek[201],
                from.ek[202],
                from.ek[203],
                from.ek[204],
                from.ek[205],
                from.ek[206],
                from.ek[207],
                from.ek[208],
                from.ek[209],
                from.ek[210],
                from.ek[211],
                from.ek[212],
                from.ek[213],
                from.ek[214],
                from.ek[215],
                from.ek[216],
                from.ek[217],
                from.ek[218],
                from.ek[219],
                from.ek[220],
                from.ek[221],
                from.ek[222],
                from.ek[223],
                from.ek[224],
                from.ek[225],
                from.ek[226],
                from.ek[227],
                from.ek[228],
                from.ek[229],
                from.ek[230],
                from.ek[231],
                from.ek[232],
                from.ek[233],
                from.ek[234],
                from.ek[235],
                from.ek[236],
                from.ek[237],
                from.ek[238],
                from.ek[239],
                from.ek[240],
                from.ek[241],
                from.ek[242],
                from.ek[243],
                from.ek[244],
                from.ek[245],
                from.ek[246],
                from.ek[247],
                from.ek[248],
                from.ek[249],
                from.ek[250],
                from.ek[251],
                from.ek[252],
                from.ek[253],
                from.ek[254],
                from.ek[255],
                from.ek[256],
                from.ek[257],
                from.ek[258],
                from.ek[259],
                from.ek[260],
                from.ek[261],
                from.ek[262],
                from.ek[263],
                from.ek[264],
                from.ek[265],
                from.ek[266],
                from.ek[267],
                from.ek[268],
                from.ek[269],
                from.ek[270],
                from.ek[271],
                from.ek[272],
                from.ek[273],
                from.ek[274],
                from.ek[275],
                from.ek[276],
                from.ek[277],
                from.ek[278],
                from.ek[279],
                from.ek[280],
                from.ek[281],
                from.ek[282],
                from.ek[283],
                from.ek[284],
                from.ek[285],
                from.ek[286],
                from.ek[287],
                from.ek[288],
                from.ek[289],
                from.ek[290],
                from.ek[291],
                from.ek[292],
                from.ek[293],
                from.ek[294],
                from.ek[295],
                from.ek[296],
                from.ek[297],
                from.ek[298],
                from.ek[299],
                from.ek[300],
                from.ek[301],
                from.ek[302],
                from.ek[303],
                from.ek[304],
                from.ek[305],
                from.ek[306],
                from.ek[307],
                from.ek[308],
                from.ek[309],
                from.ek[310],
                from.ek[311],
                from.ek[312],
                from.ek[313],
                from.ek[314],
                from.ek[315],
                from.ek[316],
                from.ek[317],
                from.ek[318],
                from.ek[319],
                from.ek[320],
                from.ek[321],
                from.ek[322],
                from.ek[323],
                from.ek[324],
                from.ek[325],
                from.ek[326],
                from.ek[327],
                from.ek[328],
                from.ek[329],
                from.ek[330],
                from.ek[331],
                from.ek[332],
                from.ek[333],
                from.ek[334],
                from.ek[335],
                from.ek[336],
                from.ek[337],
                from.ek[338],
                from.ek[339],
                from.ek[340],
                from.ek[341],
                from.ek[342],
                from.ek[343],
                from.ek[344],
                from.ek[345],
                from.ek[346],
                from.ek[347],
                from.ek[348],
                from.ek[349],
                from.ek[350],
                from.ek[351],
                from.ek[352],
                from.ek[353],
                from.ek[354],
                from.ek[355],
                from.ek[356],
                from.ek[357],
                from.ek[358],
                from.ek[359],
                from.ek[360],
                from.ek[361],
                from.ek[362],
                from.ek[363],
                from.ek[364],
                from.ek[365],
                from.ek[366],
                from.ek[367],
                from.ek[368],
                from.ek[369],
                from.ek[370],
                from.ek[371],
                from.ek[372],
                from.ek[373],
                from.ek[374],
                from.ek[375],
                from.ek[376],
                from.ek[377],
                from.ek[378],
                from.ek[379],
                from.ek[380],
                from.ek[381],
                from.ek[382],
                from.ek[383],
                from.ek[384],
                from.ek[385],
                from.ek[386],
                from.ek[387],
                from.ek[388],
                from.ek[389],
                from.ek[390],
                from.ek[391],
                from.ek[392],
                from.ek[393],
                from.ek[394],
                from.ek[395],
                from.ek[396],
                from.ek[397],
                from.ek[398],
                from.ek[399],
                from.ek[400],
                from.ek[401],
                from.ek[402],
                from.ek[403],
                from.ek[404],
                from.ek[405],
                from.ek[406],
                from.ek[407],
                from.ek[408],
                from.ek[409],
                from.ek[410],
                from.ek[411],
                from.ek[412],
                from.ek[413],
                from.ek[414],
                from.ek[415],
                from.ek[416],
                from.ek[417],
                from.ek[418],
                from.ek[419],
                from.ek[420],
                from.ek[421],
                from.ek[422],
                from.ek[423],
                from.ek[424],
                from.ek[425],
                from.ek[426],
                from.ek[427],
                from.ek[428],
                from.ek[429],
                from.ek[430],
                from.ek[431],
                from.ek[432],
                from.ek[433],
                from.ek[434],
                from.ek[435],
                from.ek[436],
                from.ek[437],
                from.ek[438],
                from.ek[439],
                from.ek[440],
                from.ek[441],
                from.ek[442],
                from.ek[443],
                from.ek[444],
                from.ek[445],
                from.ek[446],
                from.ek[447],
                from.ek[448],
                from.ek[449],
                from.ek[450],
                from.ek[451],
                from.ek[452],
                from.ek[453],
                from.ek[454],
                from.ek[455],
                from.ek[456],
                from.ek[457],
                from.ek[458],
                from.ek[459],
                from.ek[460],
                from.ek[461],
                from.ek[462],
                from.ek[463],
                from.ek[464],
                from.ek[465],
                from.ek[466],
                from.ek[467],
                from.ek[468],
                from.ek[469],
                from.ek[470],
                from.ek[471],
                from.ek[472],
                from.ek[473],
                from.ek[474],
                from.ek[475],
                from.ek[476],
                from.ek[477],
                from.ek[478],
                from.ek[479],
                from.ek[480],
                from.ek[481],
                from.ek[482],
                from.ek[483],
                from.ek[484],
                from.ek[485],
                from.ek[486],
                from.ek[487],
                from.ek[488],
                from.ek[489],
                from.ek[490],
                from.ek[491],
                from.ek[492],
                from.ek[493],
                from.ek[494],
                from.ek[495],
                from.ek[496],
                from.ek[497],
                from.ek[498],
                from.ek[499],
                from.ek[500],
                from.ek[501],
                from.ek[502],
                from.ek[503],
                from.ek[504],
                from.ek[505],
                from.ek[506],
                from.ek[507],
                from.ek[508],
                from.ek[509],
                from.ek[510],
                from.ek[511],
                from.ek[512],
                from.ek[513],
                from.ek[514],
                from.ek[515],
                from.ek[516],
                from.ek[517],
                from.ek[518],
                from.ek[519],
                from.ek[520],
                from.ek[521],
                from.ek[522],
                from.ek[523],
                from.ek[524],
                from.ek[525],
                from.ek[526],
                from.ek[527],
                from.ek[528],
                from.ek[529],
                from.ek[530],
                from.ek[531],
                from.ek[532],
                from.ek[533],
                from.ek[534],
                from.ek[535],
                from.ek[536],
                from.ek[537],
                from.ek[538],
                from.ek[539],
                from.ek[540],
                from.ek[541],
                from.ek[542],
                from.ek[543],
                from.ek[544],
                from.ek[545],
                from.ek[546],
                from.ek[547],
                from.ek[548],
                from.ek[549],
                from.ek[550],
                from.ek[551],
                from.ek[552],
                from.ek[553],
                from.ek[554],
                from.ek[555],
                from.ek[556],
                from.ek[557],
                from.ek[558],
                from.ek[559],
                from.ek[560],
                from.ek[561],
                from.ek[562],
                from.ek[563],
                from.ek[564],
                from.ek[565],
                from.ek[566],
                from.ek[567],
                from.ek[568],
                from.ek[569],
                from.ek[570],
                from.ek[571],
                from.ek[572],
                from.ek[573],
                from.ek[574],
                from.ek[575],
                from.ek[576],
                from.ek[577],
                from.ek[578],
                from.ek[579],
                from.ek[580],
                from.ek[581],
                from.ek[582],
                from.ek[583],
                from.ek[584],
                from.ek[585],
                from.ek[586],
                from.ek[587],
                from.ek[588],
                from.ek[589],
                from.ek[590],
                from.ek[591],
                from.ek[592],
                from.ek[593],
                from.ek[594],
                from.ek[595],
                from.ek[596],
                from.ek[597],
                from.ek[598],
                from.ek[599],
                from.ek[600],
                from.ek[601],
                from.ek[602],
                from.ek[603],
                from.ek[604],
                from.ek[605],
                from.ek[606],
                from.ek[607],
                from.ek[608],
                from.ek[609],
                from.ek[610],
                from.ek[611],
                from.ek[612],
                from.ek[613],
                from.ek[614],
                from.ek[615],
                from.ek[616],
                from.ek[617],
                from.ek[618],
                from.ek[619],
                from.ek[620],
                from.ek[621],
                from.ek[622],
                from.ek[623],
                from.ek[624],
                from.ek[625],
                from.ek[626],
                from.ek[627],
                from.ek[628],
                from.ek[629],
                from.ek[630],
                from.ek[631],
                from.ek[632],
                from.ek[633],
                from.ek[634],
                from.ek[635],
                from.ek[636],
                from.ek[637],
                from.ek[638],
                from.ek[639],
                from.ek[640],
                from.ek[641],
                from.ek[642],
                from.ek[643],
                from.ek[644],
                from.ek[645],
                from.ek[646],
                from.ek[647],
                from.ek[648],
                from.ek[649],
                from.ek[650],
                from.ek[651],
                from.ek[652],
                from.ek[653],
                from.ek[654],
                from.ek[655],
                from.ek[656],
                from.ek[657],
                from.ek[658],
                from.ek[659],
                from.ek[660],
                from.ek[661],
                from.ek[662],
                from.ek[663],
                from.ek[664],
                from.ek[665],
                from.ek[666],
                from.ek[667],
                from.ek[668],
                from.ek[669],
                from.ek[670],
                from.ek[671],
                from.ek[672],
                from.ek[673],
                from.ek[674],
                from.ek[675],
                from.ek[676],
                from.ek[677],
                from.ek[678],
                from.ek[679],
                from.ek[680],
                from.ek[681],
                from.ek[682],
                from.ek[683],
                from.ek[684],
                from.ek[685],
                from.ek[686],
                from.ek[687],
                from.ek[688],
                from.ek[689],
                from.ek[690],
                from.ek[691],
                from.ek[692],
                from.ek[693],
                from.ek[694],
                from.ek[695],
                from.ek[696],
                from.ek[697],
                from.ek[698],
                from.ek[699],
                from.ek[700],
                from.ek[701],
                from.ek[702],
                from.ek[703],
                from.ek[704],
                from.ek[705],
                from.ek[706],
                from.ek[707],
                from.ek[708],
                from.ek[709],
                from.ek[710],
                from.ek[711],
                from.ek[712],
                from.ek[713],
                from.ek[714],
                from.ek[715],
                from.ek[716],
                from.ek[717],
                from.ek[718],
                from.ek[719],
                from.ek[720],
                from.ek[721],
                from.ek[722],
                from.ek[723],
                from.ek[724],
                from.ek[725],
                from.ek[726],
                from.ek[727],
                from.ek[728],
                from.ek[729],
                from.ek[730],
                from.ek[731],
                from.ek[732],
                from.ek[733],
                from.ek[734],
                from.ek[735],
                from.ek[736],
                from.ek[737],
                from.ek[738],
                from.ek[739],
                from.ek[740],
                from.ek[741],
                from.ek[742],
                from.ek[743],
                from.ek[744],
                from.ek[745],
                from.ek[746],
                from.ek[747],
                from.ek[748],
                from.ek[749],
                from.ek[750],
                from.ek[751],
                from.ek[752],
                from.ek[753],
                from.ek[754],
                from.ek[755],
                from.ek[756],
                from.ek[757],
                from.ek[758],
                from.ek[759],
                from.ek[760],
                from.ek[761],
                from.ek[762],
                from.ek[763],
                from.ek[764],
                from.ek[765],
                from.ek[766],
                from.ek[767],
                from.ek[768],
                from.ek[769],
                from.ek[770],
                from.ek[771],
                from.ek[772],
                from.ek[773],
                from.ek[774],
                from.ek[775],
                from.ek[776],
                from.ek[777],
                from.ek[778],
                from.ek[779],
                from.ek[780],
                from.ek[781],
                from.ek[782],
                from.ek[783],
                from.ek[784],
                from.ek[785],
                from.ek[786],
                from.ek[787],
                from.ek[788],
                from.ek[789],
                from.ek[790],
                from.ek[791],
                from.ek[792],
                from.ek[793],
                from.ek[794],
                from.ek[795],
                from.ek[796],
                from.ek[797],
                from.ek[798],
                from.ek[799],
                from.ek[800],
                from.ek[801],
                from.ek[802],
                from.ek[803],
                from.ek[804],
                from.ek[805],
                from.ek[806],
                from.ek[807],
                from.ek[808],
                from.ek[809],
                from.ek[810],
                from.ek[811],
                from.ek[812],
                from.ek[813],
                from.ek[814],
                from.ek[815],
                from.ek[816],
                from.ek[817],
                from.ek[818],
                from.ek[819],
                from.ek[820],
                from.ek[821],
                from.ek[822],
                from.ek[823],
                from.ek[824],
                from.ek[825],
                from.ek[826],
                from.ek[827],
                from.ek[828],
                from.ek[829],
                from.ek[830],
                from.ek[831],
                from.ek[832],
                from.ek[833],
                from.ek[834],
                from.ek[835],
                from.ek[836],
                from.ek[837],
                from.ek[838],
                from.ek[839],
                from.ek[840],
                from.ek[841],
                from.ek[842],
                from.ek[843],
                from.ek[844],
                from.ek[845],
                from.ek[846],
                from.ek[847],
                from.ek[848],
                from.ek[849],
                from.ek[850],
                from.ek[851],
                from.ek[852],
                from.ek[853],
                from.ek[854],
                from.ek[855],
                from.ek[856],
                from.ek[857],
                from.ek[858],
                from.ek[859],
                from.ek[860],
                from.ek[861],
                from.ek[862],
                from.ek[863],
                from.ek[864],
                from.ek[865],
                from.ek[866],
                from.ek[867],
                from.ek[868],
                from.ek[869],
                from.ek[870],
                from.ek[871],
                from.ek[872],
                from.ek[873],
                from.ek[874],
                from.ek[875],
                from.ek[876],
                from.ek[877],
                from.ek[878],
                from.ek[879],
                from.ek[880],
                from.ek[881],
                from.ek[882],
                from.ek[883],
                from.ek[884],
                from.ek[885],
                from.ek[886],
                from.ek[887],
                from.ek[888],
                from.ek[889],
                from.ek[890],
                from.ek[891],
                from.ek[892],
                from.ek[893],
                from.ek[894],
                from.ek[895],
                from.ek[896],
                from.ek[897],
                from.ek[898],
                from.ek[899],
                from.ek[900],
                from.ek[901],
                from.ek[902],
                from.ek[903],
                from.ek[904],
                from.ek[905],
                from.ek[906],
                from.ek[907],
                from.ek[908],
                from.ek[909],
                from.ek[910],
                from.ek[911],
                from.ek[912],
                from.ek[913],
                from.ek[914],
                from.ek[915],
                from.ek[916],
                from.ek[917],
                from.ek[918],
                from.ek[919],
                from.ek[920],
                from.ek[921],
                from.ek[922],
                from.ek[923],
                from.ek[924],
                from.ek[925],
                from.ek[926],
                from.ek[927],
                from.ek[928],
                from.ek[929],
                from.ek[930],
                from.ek[931],
                from.ek[932],
                from.ek[933],
                from.ek[934],
                from.ek[935],
                from.ek[936],
                from.ek[937],
                from.ek[938],
                from.ek[939],
                from.ek[940],
                from.ek[941],
                from.ek[942],
                from.ek[943],
                from.ek[944],
                from.ek[945],
                from.ek[946],
                from.ek[947],
                from.ek[948],
                from.ek[949],
                from.ek[950],
                from.ek[951],
                from.ek[952],
                from.ek[953],
                from.ek[954],
                from.ek[955],
                from.ek[956],
                from.ek[957],
                from.ek[958],
                from.ek[959],
                from.ek[960],
                from.ek[961],
                from.ek[962],
                from.ek[963],
                from.ek[964],
                from.ek[965],
                from.ek[966],
                from.ek[967],
                from.ek[968],
                from.ek[969],
                from.ek[970],
                from.ek[971],
                from.ek[972],
                from.ek[973],
                from.ek[974],
                from.ek[975],
                from.ek[976],
                from.ek[977],
                from.ek[978],
                from.ek[979],
                from.ek[980],
                from.ek[981],
                from.ek[982],
                from.ek[983],
                from.ek[984],
                from.ek[985],
                from.ek[986],
                from.ek[987],
                from.ek[988],
                from.ek[989],
                from.ek[990],
                from.ek[991],
                from.ek[992],
                from.ek[993],
                from.ek[994],
                from.ek[995],
                from.ek[996],
                from.ek[997],
                from.ek[998],
                from.ek[999],
                from.ek[1000],
                from.ek[1001],
                from.ek[1002],
                from.ek[1003],
                from.ek[1004],
                from.ek[1005],
                from.ek[1006],
                from.ek[1007],
                from.ek[1008],
                from.ek[1009],
                from.ek[1010],
                from.ek[1011],
                from.ek[1012],
                from.ek[1013],
                from.ek[1014],
                from.ek[1015],
                from.ek[1016],
                from.ek[1017],
                from.ek[1018],
                from.ek[1019],
                from.ek[1020],
                from.ek[1021],
                from.ek[1022],
                from.ek[1023],
                from.ek[1024],
                from.ek[1025],
                from.ek[1026],
                from.ek[1027],
                from.ek[1028],
                from.ek[1029],
                from.ek[1030],
                from.ek[1031],
                from.ek[1032],
                from.ek[1033],
                from.ek[1034],
                from.ek[1035],
                from.ek[1036],
                from.ek[1037],
                from.ek[1038],
                from.ek[1039],
                from.ek[1040],
                from.ek[1041],
                from.ek[1042],
                from.ek[1043],
                from.ek[1044],
                from.ek[1045],
                from.ek[1046],
                from.ek[1047],
                from.ek[1048],
                from.ek[1049],
                from.ek[1050],
                from.ek[1051],
                from.ek[1052],
                from.ek[1053],
                from.ek[1054],
                from.ek[1055],
                from.ek[1056],
                from.ek[1057],
                from.ek[1058],
                from.ek[1059],
                from.ek[1060],
                from.ek[1061],
                from.ek[1062],
                from.ek[1063],
                from.ek[1064],
                from.ek[1065],
                from.ek[1066],
                from.ek[1067],
                from.ek[1068],
                from.ek[1069],
                from.ek[1070],
                from.ek[1071],
                from.ek[1072],
                from.ek[1073],
                from.ek[1074],
                from.ek[1075],
                from.ek[1076],
                from.ek[1077],
                from.ek[1078],
                from.ek[1079],
                from.ek[1080],
                from.ek[1081],
                from.ek[1082],
                from.ek[1083],
                from.ek[1084],
                from.ek[1085],
                from.ek[1086],
                from.ek[1087],
                from.ek[1088],
                from.ek[1089],
                from.ek[1090],
                from.ek[1091],
                from.ek[1092],
                from.ek[1093],
                from.ek[1094],
                from.ek[1095],
                from.ek[1096],
                from.ek[1097],
                from.ek[1098],
                from.ek[1099],
                from.ek[1100],
                from.ek[1101],
                from.ek[1102],
                from.ek[1103],
                from.ek[1104],
                from.ek[1105],
                from.ek[1106],
                from.ek[1107],
                from.ek[1108],
                from.ek[1109],
                from.ek[1110],
                from.ek[1111],
                from.ek[1112],
                from.ek[1113],
                from.ek[1114],
                from.ek[1115],
                from.ek[1116],
                from.ek[1117],
                from.ek[1118],
                from.ek[1119],
                from.ek[1120],
                from.ek[1121],
                from.ek[1122],
                from.ek[1123],
                from.ek[1124],
                from.ek[1125],
                from.ek[1126],
                from.ek[1127],
                from.ek[1128],
                from.ek[1129],
                from.ek[1130],
                from.ek[1131],
                from.ek[1132],
                from.ek[1133],
                from.ek[1134],
                from.ek[1135],
                from.ek[1136],
                from.ek[1137],
                from.ek[1138],
                from.ek[1139],
                from.ek[1140],
                from.ek[1141],
                from.ek[1142],
                from.ek[1143],
                from.ek[1144],
                from.ek[1145],
                from.ek[1146],
                from.ek[1147],
                from.ek[1148],
                from.ek[1149],
                from.ek[1150],
                from.ek[1151],
                from.ek[1152],
                from.ek[1153],
                from.ek[1154],
                from.ek[1155],
                from.ek[1156],
                from.ek[1157],
                from.ek[1158],
                from.ek[1159],
                from.ek[1160],
                from.ek[1161],
                from.ek[1162],
                from.ek[1163],
                from.ek[1164],
                from.ek[1165],
                from.ek[1166],
                from.ek[1167],
                from.ek[1168],
                from.ek[1169],
                from.ek[1170],
                from.ek[1171],
                from.ek[1172],
                from.ek[1173],
                from.ek[1174],
                from.ek[1175],
                from.ek[1176],
                from.ek[1177],
                from.ek[1178],
                from.ek[1179],
                from.ek[1180],
                from.ek[1181],
                from.ek[1182],
                from.ek[1183],
                from.sigma[0],
                from.sigma[1],
                from.sigma[2],
                from.sigma[3],
                from.sigma[4],
                from.sigma[5],
                from.sigma[6],
                from.sigma[7],
                from.sigma[8],
                from.sigma[9],
                from.sigma[10],
                from.sigma[11],
                from.sigma[12],
                from.sigma[13],
                from.sigma[14],
                from.sigma[15],
                from.sigma[16],
                from.sigma[17],
                from.sigma[18],
                from.sigma[19],
                from.sigma[20],
                from.sigma[21],
                from.sigma[22],
                from.sigma[23],
                from.sigma[24],
                from.sigma[25],
                from.sigma[26],
                from.sigma[27],
                from.sigma[28],
                from.sigma[29],
                from.sigma[30],
                from.sigma[31],
                from.rho[0],
                from.rho[1],
                from.rho[2],
                from.rho[3],
                from.rho[4],
                from.rho[5],
                from.rho[6],
                from.rho[7],
                from.rho[8],
                from.rho[9],
                from.rho[10],
                from.rho[11],
                from.rho[12],
                from.rho[13],
                from.rho[14],
                from.rho[15],
                from.rho[16],
                from.rho[17],
                from.rho[18],
                from.rho[19],
                from.rho[20],
                from.rho[21],
                from.rho[22],
                from.rho[23],
                from.rho[24],
                from.rho[25],
                from.rho[26],
                from.rho[27],
                from.rho[28],
                from.rho[29],
                from.rho[30],
                from.rho[31],
                from.start_g,
                from.start_h,
                from.start_prf,
                from.start_sntt,
                from.start_combined
                );
}

//
// cynw_interpret function to generate a combined_INPUT_DT from a flat vector.
//
inline void cynw_interpret ( const combined_INPUT_DT::raw_type& from, combined_INPUT_DT& to )
{
    cynw_interpret( (sc_uint<8>)from.range( 10244,10237 ), to.din[0] );
    cynw_interpret( (sc_uint<8>)from.range( 10236,10229 ), to.din[1] );
    cynw_interpret( (sc_uint<8>)from.range( 10228,10221 ), to.din[2] );
    cynw_interpret( (sc_uint<8>)from.range( 10220,10213 ), to.din[3] );
    cynw_interpret( (sc_uint<8>)from.range( 10212,10205 ), to.din[4] );
    cynw_interpret( (sc_uint<8>)from.range( 10204,10197 ), to.din[5] );
    cynw_interpret( (sc_uint<8>)from.range( 10196,10189 ), to.din[6] );
    cynw_interpret( (sc_uint<8>)from.range( 10188,10181 ), to.din[7] );
    cynw_interpret( (sc_uint<8>)from.range( 10180,10173 ), to.din[8] );
    cynw_interpret( (sc_uint<8>)from.range( 10172,10165 ), to.din[9] );
    cynw_interpret( (sc_uint<8>)from.range( 10164,10157 ), to.din[10] );
    cynw_interpret( (sc_uint<8>)from.range( 10156,10149 ), to.din[11] );
    cynw_interpret( (sc_uint<8>)from.range( 10148,10141 ), to.din[12] );
    cynw_interpret( (sc_uint<8>)from.range( 10140,10133 ), to.din[13] );
    cynw_interpret( (sc_uint<8>)from.range( 10132,10125 ), to.din[14] );
    cynw_interpret( (sc_uint<8>)from.range( 10124,10117 ), to.din[15] );
    cynw_interpret( (sc_uint<8>)from.range( 10116,10109 ), to.din[16] );
    cynw_interpret( (sc_uint<8>)from.range( 10108,10101 ), to.din[17] );
    cynw_interpret( (sc_uint<8>)from.range( 10100,10093 ), to.din[18] );
    cynw_interpret( (sc_uint<8>)from.range( 10092,10085 ), to.din[19] );
    cynw_interpret( (sc_uint<8>)from.range( 10084,10077 ), to.din[20] );
    cynw_interpret( (sc_uint<8>)from.range( 10076,10069 ), to.din[21] );
    cynw_interpret( (sc_uint<8>)from.range( 10068,10061 ), to.din[22] );
    cynw_interpret( (sc_uint<8>)from.range( 10060,10053 ), to.din[23] );
    cynw_interpret( (sc_uint<8>)from.range( 10052,10045 ), to.din[24] );
    cynw_interpret( (sc_uint<8>)from.range( 10044,10037 ), to.din[25] );
    cynw_interpret( (sc_uint<8>)from.range( 10036,10029 ), to.din[26] );
    cynw_interpret( (sc_uint<8>)from.range( 10028,10021 ), to.din[27] );
    cynw_interpret( (sc_uint<8>)from.range( 10020,10013 ), to.din[28] );
    cynw_interpret( (sc_uint<8>)from.range( 10012,10005 ), to.din[29] );
    cynw_interpret( (sc_uint<8>)from.range( 10004,9997 ), to.din[30] );
    cynw_interpret( (sc_uint<8>)from.range( 9996,9989 ), to.din[31] );
    cynw_interpret( (sc_uint<8>)from.range( 9988,9981 ), to.ek[0] );
    cynw_interpret( (sc_uint<8>)from.range( 9980,9973 ), to.ek[1] );
    cynw_interpret( (sc_uint<8>)from.range( 9972,9965 ), to.ek[2] );
    cynw_interpret( (sc_uint<8>)from.range( 9964,9957 ), to.ek[3] );
    cynw_interpret( (sc_uint<8>)from.range( 9956,9949 ), to.ek[4] );
    cynw_interpret( (sc_uint<8>)from.range( 9948,9941 ), to.ek[5] );
    cynw_interpret( (sc_uint<8>)from.range( 9940,9933 ), to.ek[6] );
    cynw_interpret( (sc_uint<8>)from.range( 9932,9925 ), to.ek[7] );
    cynw_interpret( (sc_uint<8>)from.range( 9924,9917 ), to.ek[8] );
    cynw_interpret( (sc_uint<8>)from.range( 9916,9909 ), to.ek[9] );
    cynw_interpret( (sc_uint<8>)from.range( 9908,9901 ), to.ek[10] );
    cynw_interpret( (sc_uint<8>)from.range( 9900,9893 ), to.ek[11] );
    cynw_interpret( (sc_uint<8>)from.range( 9892,9885 ), to.ek[12] );
    cynw_interpret( (sc_uint<8>)from.range( 9884,9877 ), to.ek[13] );
    cynw_interpret( (sc_uint<8>)from.range( 9876,9869 ), to.ek[14] );
    cynw_interpret( (sc_uint<8>)from.range( 9868,9861 ), to.ek[15] );
    cynw_interpret( (sc_uint<8>)from.range( 9860,9853 ), to.ek[16] );
    cynw_interpret( (sc_uint<8>)from.range( 9852,9845 ), to.ek[17] );
    cynw_interpret( (sc_uint<8>)from.range( 9844,9837 ), to.ek[18] );
    cynw_interpret( (sc_uint<8>)from.range( 9836,9829 ), to.ek[19] );
    cynw_interpret( (sc_uint<8>)from.range( 9828,9821 ), to.ek[20] );
    cynw_interpret( (sc_uint<8>)from.range( 9820,9813 ), to.ek[21] );
    cynw_interpret( (sc_uint<8>)from.range( 9812,9805 ), to.ek[22] );
    cynw_interpret( (sc_uint<8>)from.range( 9804,9797 ), to.ek[23] );
    cynw_interpret( (sc_uint<8>)from.range( 9796,9789 ), to.ek[24] );
    cynw_interpret( (sc_uint<8>)from.range( 9788,9781 ), to.ek[25] );
    cynw_interpret( (sc_uint<8>)from.range( 9780,9773 ), to.ek[26] );
    cynw_interpret( (sc_uint<8>)from.range( 9772,9765 ), to.ek[27] );
    cynw_interpret( (sc_uint<8>)from.range( 9764,9757 ), to.ek[28] );
    cynw_interpret( (sc_uint<8>)from.range( 9756,9749 ), to.ek[29] );
    cynw_interpret( (sc_uint<8>)from.range( 9748,9741 ), to.ek[30] );
    cynw_interpret( (sc_uint<8>)from.range( 9740,9733 ), to.ek[31] );
    cynw_interpret( (sc_uint<8>)from.range( 9732,9725 ), to.ek[32] );
    cynw_interpret( (sc_uint<8>)from.range( 9724,9717 ), to.ek[33] );
    cynw_interpret( (sc_uint<8>)from.range( 9716,9709 ), to.ek[34] );
    cynw_interpret( (sc_uint<8>)from.range( 9708,9701 ), to.ek[35] );
    cynw_interpret( (sc_uint<8>)from.range( 9700,9693 ), to.ek[36] );
    cynw_interpret( (sc_uint<8>)from.range( 9692,9685 ), to.ek[37] );
    cynw_interpret( (sc_uint<8>)from.range( 9684,9677 ), to.ek[38] );
    cynw_interpret( (sc_uint<8>)from.range( 9676,9669 ), to.ek[39] );
    cynw_interpret( (sc_uint<8>)from.range( 9668,9661 ), to.ek[40] );
    cynw_interpret( (sc_uint<8>)from.range( 9660,9653 ), to.ek[41] );
    cynw_interpret( (sc_uint<8>)from.range( 9652,9645 ), to.ek[42] );
    cynw_interpret( (sc_uint<8>)from.range( 9644,9637 ), to.ek[43] );
    cynw_interpret( (sc_uint<8>)from.range( 9636,9629 ), to.ek[44] );
    cynw_interpret( (sc_uint<8>)from.range( 9628,9621 ), to.ek[45] );
    cynw_interpret( (sc_uint<8>)from.range( 9620,9613 ), to.ek[46] );
    cynw_interpret( (sc_uint<8>)from.range( 9612,9605 ), to.ek[47] );
    cynw_interpret( (sc_uint<8>)from.range( 9604,9597 ), to.ek[48] );
    cynw_interpret( (sc_uint<8>)from.range( 9596,9589 ), to.ek[49] );
    cynw_interpret( (sc_uint<8>)from.range( 9588,9581 ), to.ek[50] );
    cynw_interpret( (sc_uint<8>)from.range( 9580,9573 ), to.ek[51] );
    cynw_interpret( (sc_uint<8>)from.range( 9572,9565 ), to.ek[52] );
    cynw_interpret( (sc_uint<8>)from.range( 9564,9557 ), to.ek[53] );
    cynw_interpret( (sc_uint<8>)from.range( 9556,9549 ), to.ek[54] );
    cynw_interpret( (sc_uint<8>)from.range( 9548,9541 ), to.ek[55] );
    cynw_interpret( (sc_uint<8>)from.range( 9540,9533 ), to.ek[56] );
    cynw_interpret( (sc_uint<8>)from.range( 9532,9525 ), to.ek[57] );
    cynw_interpret( (sc_uint<8>)from.range( 9524,9517 ), to.ek[58] );
    cynw_interpret( (sc_uint<8>)from.range( 9516,9509 ), to.ek[59] );
    cynw_interpret( (sc_uint<8>)from.range( 9508,9501 ), to.ek[60] );
    cynw_interpret( (sc_uint<8>)from.range( 9500,9493 ), to.ek[61] );
    cynw_interpret( (sc_uint<8>)from.range( 9492,9485 ), to.ek[62] );
    cynw_interpret( (sc_uint<8>)from.range( 9484,9477 ), to.ek[63] );
    cynw_interpret( (sc_uint<8>)from.range( 9476,9469 ), to.ek[64] );
    cynw_interpret( (sc_uint<8>)from.range( 9468,9461 ), to.ek[65] );
    cynw_interpret( (sc_uint<8>)from.range( 9460,9453 ), to.ek[66] );
    cynw_interpret( (sc_uint<8>)from.range( 9452,9445 ), to.ek[67] );
    cynw_interpret( (sc_uint<8>)from.range( 9444,9437 ), to.ek[68] );
    cynw_interpret( (sc_uint<8>)from.range( 9436,9429 ), to.ek[69] );
    cynw_interpret( (sc_uint<8>)from.range( 9428,9421 ), to.ek[70] );
    cynw_interpret( (sc_uint<8>)from.range( 9420,9413 ), to.ek[71] );
    cynw_interpret( (sc_uint<8>)from.range( 9412,9405 ), to.ek[72] );
    cynw_interpret( (sc_uint<8>)from.range( 9404,9397 ), to.ek[73] );
    cynw_interpret( (sc_uint<8>)from.range( 9396,9389 ), to.ek[74] );
    cynw_interpret( (sc_uint<8>)from.range( 9388,9381 ), to.ek[75] );
    cynw_interpret( (sc_uint<8>)from.range( 9380,9373 ), to.ek[76] );
    cynw_interpret( (sc_uint<8>)from.range( 9372,9365 ), to.ek[77] );
    cynw_interpret( (sc_uint<8>)from.range( 9364,9357 ), to.ek[78] );
    cynw_interpret( (sc_uint<8>)from.range( 9356,9349 ), to.ek[79] );
    cynw_interpret( (sc_uint<8>)from.range( 9348,9341 ), to.ek[80] );
    cynw_interpret( (sc_uint<8>)from.range( 9340,9333 ), to.ek[81] );
    cynw_interpret( (sc_uint<8>)from.range( 9332,9325 ), to.ek[82] );
    cynw_interpret( (sc_uint<8>)from.range( 9324,9317 ), to.ek[83] );
    cynw_interpret( (sc_uint<8>)from.range( 9316,9309 ), to.ek[84] );
    cynw_interpret( (sc_uint<8>)from.range( 9308,9301 ), to.ek[85] );
    cynw_interpret( (sc_uint<8>)from.range( 9300,9293 ), to.ek[86] );
    cynw_interpret( (sc_uint<8>)from.range( 9292,9285 ), to.ek[87] );
    cynw_interpret( (sc_uint<8>)from.range( 9284,9277 ), to.ek[88] );
    cynw_interpret( (sc_uint<8>)from.range( 9276,9269 ), to.ek[89] );
    cynw_interpret( (sc_uint<8>)from.range( 9268,9261 ), to.ek[90] );
    cynw_interpret( (sc_uint<8>)from.range( 9260,9253 ), to.ek[91] );
    cynw_interpret( (sc_uint<8>)from.range( 9252,9245 ), to.ek[92] );
    cynw_interpret( (sc_uint<8>)from.range( 9244,9237 ), to.ek[93] );
    cynw_interpret( (sc_uint<8>)from.range( 9236,9229 ), to.ek[94] );
    cynw_interpret( (sc_uint<8>)from.range( 9228,9221 ), to.ek[95] );
    cynw_interpret( (sc_uint<8>)from.range( 9220,9213 ), to.ek[96] );
    cynw_interpret( (sc_uint<8>)from.range( 9212,9205 ), to.ek[97] );
    cynw_interpret( (sc_uint<8>)from.range( 9204,9197 ), to.ek[98] );
    cynw_interpret( (sc_uint<8>)from.range( 9196,9189 ), to.ek[99] );
    cynw_interpret( (sc_uint<8>)from.range( 9188,9181 ), to.ek[100] );
    cynw_interpret( (sc_uint<8>)from.range( 9180,9173 ), to.ek[101] );
    cynw_interpret( (sc_uint<8>)from.range( 9172,9165 ), to.ek[102] );
    cynw_interpret( (sc_uint<8>)from.range( 9164,9157 ), to.ek[103] );
    cynw_interpret( (sc_uint<8>)from.range( 9156,9149 ), to.ek[104] );
    cynw_interpret( (sc_uint<8>)from.range( 9148,9141 ), to.ek[105] );
    cynw_interpret( (sc_uint<8>)from.range( 9140,9133 ), to.ek[106] );
    cynw_interpret( (sc_uint<8>)from.range( 9132,9125 ), to.ek[107] );
    cynw_interpret( (sc_uint<8>)from.range( 9124,9117 ), to.ek[108] );
    cynw_interpret( (sc_uint<8>)from.range( 9116,9109 ), to.ek[109] );
    cynw_interpret( (sc_uint<8>)from.range( 9108,9101 ), to.ek[110] );
    cynw_interpret( (sc_uint<8>)from.range( 9100,9093 ), to.ek[111] );
    cynw_interpret( (sc_uint<8>)from.range( 9092,9085 ), to.ek[112] );
    cynw_interpret( (sc_uint<8>)from.range( 9084,9077 ), to.ek[113] );
    cynw_interpret( (sc_uint<8>)from.range( 9076,9069 ), to.ek[114] );
    cynw_interpret( (sc_uint<8>)from.range( 9068,9061 ), to.ek[115] );
    cynw_interpret( (sc_uint<8>)from.range( 9060,9053 ), to.ek[116] );
    cynw_interpret( (sc_uint<8>)from.range( 9052,9045 ), to.ek[117] );
    cynw_interpret( (sc_uint<8>)from.range( 9044,9037 ), to.ek[118] );
    cynw_interpret( (sc_uint<8>)from.range( 9036,9029 ), to.ek[119] );
    cynw_interpret( (sc_uint<8>)from.range( 9028,9021 ), to.ek[120] );
    cynw_interpret( (sc_uint<8>)from.range( 9020,9013 ), to.ek[121] );
    cynw_interpret( (sc_uint<8>)from.range( 9012,9005 ), to.ek[122] );
    cynw_interpret( (sc_uint<8>)from.range( 9004,8997 ), to.ek[123] );
    cynw_interpret( (sc_uint<8>)from.range( 8996,8989 ), to.ek[124] );
    cynw_interpret( (sc_uint<8>)from.range( 8988,8981 ), to.ek[125] );
    cynw_interpret( (sc_uint<8>)from.range( 8980,8973 ), to.ek[126] );
    cynw_interpret( (sc_uint<8>)from.range( 8972,8965 ), to.ek[127] );
    cynw_interpret( (sc_uint<8>)from.range( 8964,8957 ), to.ek[128] );
    cynw_interpret( (sc_uint<8>)from.range( 8956,8949 ), to.ek[129] );
    cynw_interpret( (sc_uint<8>)from.range( 8948,8941 ), to.ek[130] );
    cynw_interpret( (sc_uint<8>)from.range( 8940,8933 ), to.ek[131] );
    cynw_interpret( (sc_uint<8>)from.range( 8932,8925 ), to.ek[132] );
    cynw_interpret( (sc_uint<8>)from.range( 8924,8917 ), to.ek[133] );
    cynw_interpret( (sc_uint<8>)from.range( 8916,8909 ), to.ek[134] );
    cynw_interpret( (sc_uint<8>)from.range( 8908,8901 ), to.ek[135] );
    cynw_interpret( (sc_uint<8>)from.range( 8900,8893 ), to.ek[136] );
    cynw_interpret( (sc_uint<8>)from.range( 8892,8885 ), to.ek[137] );
    cynw_interpret( (sc_uint<8>)from.range( 8884,8877 ), to.ek[138] );
    cynw_interpret( (sc_uint<8>)from.range( 8876,8869 ), to.ek[139] );
    cynw_interpret( (sc_uint<8>)from.range( 8868,8861 ), to.ek[140] );
    cynw_interpret( (sc_uint<8>)from.range( 8860,8853 ), to.ek[141] );
    cynw_interpret( (sc_uint<8>)from.range( 8852,8845 ), to.ek[142] );
    cynw_interpret( (sc_uint<8>)from.range( 8844,8837 ), to.ek[143] );
    cynw_interpret( (sc_uint<8>)from.range( 8836,8829 ), to.ek[144] );
    cynw_interpret( (sc_uint<8>)from.range( 8828,8821 ), to.ek[145] );
    cynw_interpret( (sc_uint<8>)from.range( 8820,8813 ), to.ek[146] );
    cynw_interpret( (sc_uint<8>)from.range( 8812,8805 ), to.ek[147] );
    cynw_interpret( (sc_uint<8>)from.range( 8804,8797 ), to.ek[148] );
    cynw_interpret( (sc_uint<8>)from.range( 8796,8789 ), to.ek[149] );
    cynw_interpret( (sc_uint<8>)from.range( 8788,8781 ), to.ek[150] );
    cynw_interpret( (sc_uint<8>)from.range( 8780,8773 ), to.ek[151] );
    cynw_interpret( (sc_uint<8>)from.range( 8772,8765 ), to.ek[152] );
    cynw_interpret( (sc_uint<8>)from.range( 8764,8757 ), to.ek[153] );
    cynw_interpret( (sc_uint<8>)from.range( 8756,8749 ), to.ek[154] );
    cynw_interpret( (sc_uint<8>)from.range( 8748,8741 ), to.ek[155] );
    cynw_interpret( (sc_uint<8>)from.range( 8740,8733 ), to.ek[156] );
    cynw_interpret( (sc_uint<8>)from.range( 8732,8725 ), to.ek[157] );
    cynw_interpret( (sc_uint<8>)from.range( 8724,8717 ), to.ek[158] );
    cynw_interpret( (sc_uint<8>)from.range( 8716,8709 ), to.ek[159] );
    cynw_interpret( (sc_uint<8>)from.range( 8708,8701 ), to.ek[160] );
    cynw_interpret( (sc_uint<8>)from.range( 8700,8693 ), to.ek[161] );
    cynw_interpret( (sc_uint<8>)from.range( 8692,8685 ), to.ek[162] );
    cynw_interpret( (sc_uint<8>)from.range( 8684,8677 ), to.ek[163] );
    cynw_interpret( (sc_uint<8>)from.range( 8676,8669 ), to.ek[164] );
    cynw_interpret( (sc_uint<8>)from.range( 8668,8661 ), to.ek[165] );
    cynw_interpret( (sc_uint<8>)from.range( 8660,8653 ), to.ek[166] );
    cynw_interpret( (sc_uint<8>)from.range( 8652,8645 ), to.ek[167] );
    cynw_interpret( (sc_uint<8>)from.range( 8644,8637 ), to.ek[168] );
    cynw_interpret( (sc_uint<8>)from.range( 8636,8629 ), to.ek[169] );
    cynw_interpret( (sc_uint<8>)from.range( 8628,8621 ), to.ek[170] );
    cynw_interpret( (sc_uint<8>)from.range( 8620,8613 ), to.ek[171] );
    cynw_interpret( (sc_uint<8>)from.range( 8612,8605 ), to.ek[172] );
    cynw_interpret( (sc_uint<8>)from.range( 8604,8597 ), to.ek[173] );
    cynw_interpret( (sc_uint<8>)from.range( 8596,8589 ), to.ek[174] );
    cynw_interpret( (sc_uint<8>)from.range( 8588,8581 ), to.ek[175] );
    cynw_interpret( (sc_uint<8>)from.range( 8580,8573 ), to.ek[176] );
    cynw_interpret( (sc_uint<8>)from.range( 8572,8565 ), to.ek[177] );
    cynw_interpret( (sc_uint<8>)from.range( 8564,8557 ), to.ek[178] );
    cynw_interpret( (sc_uint<8>)from.range( 8556,8549 ), to.ek[179] );
    cynw_interpret( (sc_uint<8>)from.range( 8548,8541 ), to.ek[180] );
    cynw_interpret( (sc_uint<8>)from.range( 8540,8533 ), to.ek[181] );
    cynw_interpret( (sc_uint<8>)from.range( 8532,8525 ), to.ek[182] );
    cynw_interpret( (sc_uint<8>)from.range( 8524,8517 ), to.ek[183] );
    cynw_interpret( (sc_uint<8>)from.range( 8516,8509 ), to.ek[184] );
    cynw_interpret( (sc_uint<8>)from.range( 8508,8501 ), to.ek[185] );
    cynw_interpret( (sc_uint<8>)from.range( 8500,8493 ), to.ek[186] );
    cynw_interpret( (sc_uint<8>)from.range( 8492,8485 ), to.ek[187] );
    cynw_interpret( (sc_uint<8>)from.range( 8484,8477 ), to.ek[188] );
    cynw_interpret( (sc_uint<8>)from.range( 8476,8469 ), to.ek[189] );
    cynw_interpret( (sc_uint<8>)from.range( 8468,8461 ), to.ek[190] );
    cynw_interpret( (sc_uint<8>)from.range( 8460,8453 ), to.ek[191] );
    cynw_interpret( (sc_uint<8>)from.range( 8452,8445 ), to.ek[192] );
    cynw_interpret( (sc_uint<8>)from.range( 8444,8437 ), to.ek[193] );
    cynw_interpret( (sc_uint<8>)from.range( 8436,8429 ), to.ek[194] );
    cynw_interpret( (sc_uint<8>)from.range( 8428,8421 ), to.ek[195] );
    cynw_interpret( (sc_uint<8>)from.range( 8420,8413 ), to.ek[196] );
    cynw_interpret( (sc_uint<8>)from.range( 8412,8405 ), to.ek[197] );
    cynw_interpret( (sc_uint<8>)from.range( 8404,8397 ), to.ek[198] );
    cynw_interpret( (sc_uint<8>)from.range( 8396,8389 ), to.ek[199] );
    cynw_interpret( (sc_uint<8>)from.range( 8388,8381 ), to.ek[200] );
    cynw_interpret( (sc_uint<8>)from.range( 8380,8373 ), to.ek[201] );
    cynw_interpret( (sc_uint<8>)from.range( 8372,8365 ), to.ek[202] );
    cynw_interpret( (sc_uint<8>)from.range( 8364,8357 ), to.ek[203] );
    cynw_interpret( (sc_uint<8>)from.range( 8356,8349 ), to.ek[204] );
    cynw_interpret( (sc_uint<8>)from.range( 8348,8341 ), to.ek[205] );
    cynw_interpret( (sc_uint<8>)from.range( 8340,8333 ), to.ek[206] );
    cynw_interpret( (sc_uint<8>)from.range( 8332,8325 ), to.ek[207] );
    cynw_interpret( (sc_uint<8>)from.range( 8324,8317 ), to.ek[208] );
    cynw_interpret( (sc_uint<8>)from.range( 8316,8309 ), to.ek[209] );
    cynw_interpret( (sc_uint<8>)from.range( 8308,8301 ), to.ek[210] );
    cynw_interpret( (sc_uint<8>)from.range( 8300,8293 ), to.ek[211] );
    cynw_interpret( (sc_uint<8>)from.range( 8292,8285 ), to.ek[212] );
    cynw_interpret( (sc_uint<8>)from.range( 8284,8277 ), to.ek[213] );
    cynw_interpret( (sc_uint<8>)from.range( 8276,8269 ), to.ek[214] );
    cynw_interpret( (sc_uint<8>)from.range( 8268,8261 ), to.ek[215] );
    cynw_interpret( (sc_uint<8>)from.range( 8260,8253 ), to.ek[216] );
    cynw_interpret( (sc_uint<8>)from.range( 8252,8245 ), to.ek[217] );
    cynw_interpret( (sc_uint<8>)from.range( 8244,8237 ), to.ek[218] );
    cynw_interpret( (sc_uint<8>)from.range( 8236,8229 ), to.ek[219] );
    cynw_interpret( (sc_uint<8>)from.range( 8228,8221 ), to.ek[220] );
    cynw_interpret( (sc_uint<8>)from.range( 8220,8213 ), to.ek[221] );
    cynw_interpret( (sc_uint<8>)from.range( 8212,8205 ), to.ek[222] );
    cynw_interpret( (sc_uint<8>)from.range( 8204,8197 ), to.ek[223] );
    cynw_interpret( (sc_uint<8>)from.range( 8196,8189 ), to.ek[224] );
    cynw_interpret( (sc_uint<8>)from.range( 8188,8181 ), to.ek[225] );
    cynw_interpret( (sc_uint<8>)from.range( 8180,8173 ), to.ek[226] );
    cynw_interpret( (sc_uint<8>)from.range( 8172,8165 ), to.ek[227] );
    cynw_interpret( (sc_uint<8>)from.range( 8164,8157 ), to.ek[228] );
    cynw_interpret( (sc_uint<8>)from.range( 8156,8149 ), to.ek[229] );
    cynw_interpret( (sc_uint<8>)from.range( 8148,8141 ), to.ek[230] );
    cynw_interpret( (sc_uint<8>)from.range( 8140,8133 ), to.ek[231] );
    cynw_interpret( (sc_uint<8>)from.range( 8132,8125 ), to.ek[232] );
    cynw_interpret( (sc_uint<8>)from.range( 8124,8117 ), to.ek[233] );
    cynw_interpret( (sc_uint<8>)from.range( 8116,8109 ), to.ek[234] );
    cynw_interpret( (sc_uint<8>)from.range( 8108,8101 ), to.ek[235] );
    cynw_interpret( (sc_uint<8>)from.range( 8100,8093 ), to.ek[236] );
    cynw_interpret( (sc_uint<8>)from.range( 8092,8085 ), to.ek[237] );
    cynw_interpret( (sc_uint<8>)from.range( 8084,8077 ), to.ek[238] );
    cynw_interpret( (sc_uint<8>)from.range( 8076,8069 ), to.ek[239] );
    cynw_interpret( (sc_uint<8>)from.range( 8068,8061 ), to.ek[240] );
    cynw_interpret( (sc_uint<8>)from.range( 8060,8053 ), to.ek[241] );
    cynw_interpret( (sc_uint<8>)from.range( 8052,8045 ), to.ek[242] );
    cynw_interpret( (sc_uint<8>)from.range( 8044,8037 ), to.ek[243] );
    cynw_interpret( (sc_uint<8>)from.range( 8036,8029 ), to.ek[244] );
    cynw_interpret( (sc_uint<8>)from.range( 8028,8021 ), to.ek[245] );
    cynw_interpret( (sc_uint<8>)from.range( 8020,8013 ), to.ek[246] );
    cynw_interpret( (sc_uint<8>)from.range( 8012,8005 ), to.ek[247] );
    cynw_interpret( (sc_uint<8>)from.range( 8004,7997 ), to.ek[248] );
    cynw_interpret( (sc_uint<8>)from.range( 7996,7989 ), to.ek[249] );
    cynw_interpret( (sc_uint<8>)from.range( 7988,7981 ), to.ek[250] );
    cynw_interpret( (sc_uint<8>)from.range( 7980,7973 ), to.ek[251] );
    cynw_interpret( (sc_uint<8>)from.range( 7972,7965 ), to.ek[252] );
    cynw_interpret( (sc_uint<8>)from.range( 7964,7957 ), to.ek[253] );
    cynw_interpret( (sc_uint<8>)from.range( 7956,7949 ), to.ek[254] );
    cynw_interpret( (sc_uint<8>)from.range( 7948,7941 ), to.ek[255] );
    cynw_interpret( (sc_uint<8>)from.range( 7940,7933 ), to.ek[256] );
    cynw_interpret( (sc_uint<8>)from.range( 7932,7925 ), to.ek[257] );
    cynw_interpret( (sc_uint<8>)from.range( 7924,7917 ), to.ek[258] );
    cynw_interpret( (sc_uint<8>)from.range( 7916,7909 ), to.ek[259] );
    cynw_interpret( (sc_uint<8>)from.range( 7908,7901 ), to.ek[260] );
    cynw_interpret( (sc_uint<8>)from.range( 7900,7893 ), to.ek[261] );
    cynw_interpret( (sc_uint<8>)from.range( 7892,7885 ), to.ek[262] );
    cynw_interpret( (sc_uint<8>)from.range( 7884,7877 ), to.ek[263] );
    cynw_interpret( (sc_uint<8>)from.range( 7876,7869 ), to.ek[264] );
    cynw_interpret( (sc_uint<8>)from.range( 7868,7861 ), to.ek[265] );
    cynw_interpret( (sc_uint<8>)from.range( 7860,7853 ), to.ek[266] );
    cynw_interpret( (sc_uint<8>)from.range( 7852,7845 ), to.ek[267] );
    cynw_interpret( (sc_uint<8>)from.range( 7844,7837 ), to.ek[268] );
    cynw_interpret( (sc_uint<8>)from.range( 7836,7829 ), to.ek[269] );
    cynw_interpret( (sc_uint<8>)from.range( 7828,7821 ), to.ek[270] );
    cynw_interpret( (sc_uint<8>)from.range( 7820,7813 ), to.ek[271] );
    cynw_interpret( (sc_uint<8>)from.range( 7812,7805 ), to.ek[272] );
    cynw_interpret( (sc_uint<8>)from.range( 7804,7797 ), to.ek[273] );
    cynw_interpret( (sc_uint<8>)from.range( 7796,7789 ), to.ek[274] );
    cynw_interpret( (sc_uint<8>)from.range( 7788,7781 ), to.ek[275] );
    cynw_interpret( (sc_uint<8>)from.range( 7780,7773 ), to.ek[276] );
    cynw_interpret( (sc_uint<8>)from.range( 7772,7765 ), to.ek[277] );
    cynw_interpret( (sc_uint<8>)from.range( 7764,7757 ), to.ek[278] );
    cynw_interpret( (sc_uint<8>)from.range( 7756,7749 ), to.ek[279] );
    cynw_interpret( (sc_uint<8>)from.range( 7748,7741 ), to.ek[280] );
    cynw_interpret( (sc_uint<8>)from.range( 7740,7733 ), to.ek[281] );
    cynw_interpret( (sc_uint<8>)from.range( 7732,7725 ), to.ek[282] );
    cynw_interpret( (sc_uint<8>)from.range( 7724,7717 ), to.ek[283] );
    cynw_interpret( (sc_uint<8>)from.range( 7716,7709 ), to.ek[284] );
    cynw_interpret( (sc_uint<8>)from.range( 7708,7701 ), to.ek[285] );
    cynw_interpret( (sc_uint<8>)from.range( 7700,7693 ), to.ek[286] );
    cynw_interpret( (sc_uint<8>)from.range( 7692,7685 ), to.ek[287] );
    cynw_interpret( (sc_uint<8>)from.range( 7684,7677 ), to.ek[288] );
    cynw_interpret( (sc_uint<8>)from.range( 7676,7669 ), to.ek[289] );
    cynw_interpret( (sc_uint<8>)from.range( 7668,7661 ), to.ek[290] );
    cynw_interpret( (sc_uint<8>)from.range( 7660,7653 ), to.ek[291] );
    cynw_interpret( (sc_uint<8>)from.range( 7652,7645 ), to.ek[292] );
    cynw_interpret( (sc_uint<8>)from.range( 7644,7637 ), to.ek[293] );
    cynw_interpret( (sc_uint<8>)from.range( 7636,7629 ), to.ek[294] );
    cynw_interpret( (sc_uint<8>)from.range( 7628,7621 ), to.ek[295] );
    cynw_interpret( (sc_uint<8>)from.range( 7620,7613 ), to.ek[296] );
    cynw_interpret( (sc_uint<8>)from.range( 7612,7605 ), to.ek[297] );
    cynw_interpret( (sc_uint<8>)from.range( 7604,7597 ), to.ek[298] );
    cynw_interpret( (sc_uint<8>)from.range( 7596,7589 ), to.ek[299] );
    cynw_interpret( (sc_uint<8>)from.range( 7588,7581 ), to.ek[300] );
    cynw_interpret( (sc_uint<8>)from.range( 7580,7573 ), to.ek[301] );
    cynw_interpret( (sc_uint<8>)from.range( 7572,7565 ), to.ek[302] );
    cynw_interpret( (sc_uint<8>)from.range( 7564,7557 ), to.ek[303] );
    cynw_interpret( (sc_uint<8>)from.range( 7556,7549 ), to.ek[304] );
    cynw_interpret( (sc_uint<8>)from.range( 7548,7541 ), to.ek[305] );
    cynw_interpret( (sc_uint<8>)from.range( 7540,7533 ), to.ek[306] );
    cynw_interpret( (sc_uint<8>)from.range( 7532,7525 ), to.ek[307] );
    cynw_interpret( (sc_uint<8>)from.range( 7524,7517 ), to.ek[308] );
    cynw_interpret( (sc_uint<8>)from.range( 7516,7509 ), to.ek[309] );
    cynw_interpret( (sc_uint<8>)from.range( 7508,7501 ), to.ek[310] );
    cynw_interpret( (sc_uint<8>)from.range( 7500,7493 ), to.ek[311] );
    cynw_interpret( (sc_uint<8>)from.range( 7492,7485 ), to.ek[312] );
    cynw_interpret( (sc_uint<8>)from.range( 7484,7477 ), to.ek[313] );
    cynw_interpret( (sc_uint<8>)from.range( 7476,7469 ), to.ek[314] );
    cynw_interpret( (sc_uint<8>)from.range( 7468,7461 ), to.ek[315] );
    cynw_interpret( (sc_uint<8>)from.range( 7460,7453 ), to.ek[316] );
    cynw_interpret( (sc_uint<8>)from.range( 7452,7445 ), to.ek[317] );
    cynw_interpret( (sc_uint<8>)from.range( 7444,7437 ), to.ek[318] );
    cynw_interpret( (sc_uint<8>)from.range( 7436,7429 ), to.ek[319] );
    cynw_interpret( (sc_uint<8>)from.range( 7428,7421 ), to.ek[320] );
    cynw_interpret( (sc_uint<8>)from.range( 7420,7413 ), to.ek[321] );
    cynw_interpret( (sc_uint<8>)from.range( 7412,7405 ), to.ek[322] );
    cynw_interpret( (sc_uint<8>)from.range( 7404,7397 ), to.ek[323] );
    cynw_interpret( (sc_uint<8>)from.range( 7396,7389 ), to.ek[324] );
    cynw_interpret( (sc_uint<8>)from.range( 7388,7381 ), to.ek[325] );
    cynw_interpret( (sc_uint<8>)from.range( 7380,7373 ), to.ek[326] );
    cynw_interpret( (sc_uint<8>)from.range( 7372,7365 ), to.ek[327] );
    cynw_interpret( (sc_uint<8>)from.range( 7364,7357 ), to.ek[328] );
    cynw_interpret( (sc_uint<8>)from.range( 7356,7349 ), to.ek[329] );
    cynw_interpret( (sc_uint<8>)from.range( 7348,7341 ), to.ek[330] );
    cynw_interpret( (sc_uint<8>)from.range( 7340,7333 ), to.ek[331] );
    cynw_interpret( (sc_uint<8>)from.range( 7332,7325 ), to.ek[332] );
    cynw_interpret( (sc_uint<8>)from.range( 7324,7317 ), to.ek[333] );
    cynw_interpret( (sc_uint<8>)from.range( 7316,7309 ), to.ek[334] );
    cynw_interpret( (sc_uint<8>)from.range( 7308,7301 ), to.ek[335] );
    cynw_interpret( (sc_uint<8>)from.range( 7300,7293 ), to.ek[336] );
    cynw_interpret( (sc_uint<8>)from.range( 7292,7285 ), to.ek[337] );
    cynw_interpret( (sc_uint<8>)from.range( 7284,7277 ), to.ek[338] );
    cynw_interpret( (sc_uint<8>)from.range( 7276,7269 ), to.ek[339] );
    cynw_interpret( (sc_uint<8>)from.range( 7268,7261 ), to.ek[340] );
    cynw_interpret( (sc_uint<8>)from.range( 7260,7253 ), to.ek[341] );
    cynw_interpret( (sc_uint<8>)from.range( 7252,7245 ), to.ek[342] );
    cynw_interpret( (sc_uint<8>)from.range( 7244,7237 ), to.ek[343] );
    cynw_interpret( (sc_uint<8>)from.range( 7236,7229 ), to.ek[344] );
    cynw_interpret( (sc_uint<8>)from.range( 7228,7221 ), to.ek[345] );
    cynw_interpret( (sc_uint<8>)from.range( 7220,7213 ), to.ek[346] );
    cynw_interpret( (sc_uint<8>)from.range( 7212,7205 ), to.ek[347] );
    cynw_interpret( (sc_uint<8>)from.range( 7204,7197 ), to.ek[348] );
    cynw_interpret( (sc_uint<8>)from.range( 7196,7189 ), to.ek[349] );
    cynw_interpret( (sc_uint<8>)from.range( 7188,7181 ), to.ek[350] );
    cynw_interpret( (sc_uint<8>)from.range( 7180,7173 ), to.ek[351] );
    cynw_interpret( (sc_uint<8>)from.range( 7172,7165 ), to.ek[352] );
    cynw_interpret( (sc_uint<8>)from.range( 7164,7157 ), to.ek[353] );
    cynw_interpret( (sc_uint<8>)from.range( 7156,7149 ), to.ek[354] );
    cynw_interpret( (sc_uint<8>)from.range( 7148,7141 ), to.ek[355] );
    cynw_interpret( (sc_uint<8>)from.range( 7140,7133 ), to.ek[356] );
    cynw_interpret( (sc_uint<8>)from.range( 7132,7125 ), to.ek[357] );
    cynw_interpret( (sc_uint<8>)from.range( 7124,7117 ), to.ek[358] );
    cynw_interpret( (sc_uint<8>)from.range( 7116,7109 ), to.ek[359] );
    cynw_interpret( (sc_uint<8>)from.range( 7108,7101 ), to.ek[360] );
    cynw_interpret( (sc_uint<8>)from.range( 7100,7093 ), to.ek[361] );
    cynw_interpret( (sc_uint<8>)from.range( 7092,7085 ), to.ek[362] );
    cynw_interpret( (sc_uint<8>)from.range( 7084,7077 ), to.ek[363] );
    cynw_interpret( (sc_uint<8>)from.range( 7076,7069 ), to.ek[364] );
    cynw_interpret( (sc_uint<8>)from.range( 7068,7061 ), to.ek[365] );
    cynw_interpret( (sc_uint<8>)from.range( 7060,7053 ), to.ek[366] );
    cynw_interpret( (sc_uint<8>)from.range( 7052,7045 ), to.ek[367] );
    cynw_interpret( (sc_uint<8>)from.range( 7044,7037 ), to.ek[368] );
    cynw_interpret( (sc_uint<8>)from.range( 7036,7029 ), to.ek[369] );
    cynw_interpret( (sc_uint<8>)from.range( 7028,7021 ), to.ek[370] );
    cynw_interpret( (sc_uint<8>)from.range( 7020,7013 ), to.ek[371] );
    cynw_interpret( (sc_uint<8>)from.range( 7012,7005 ), to.ek[372] );
    cynw_interpret( (sc_uint<8>)from.range( 7004,6997 ), to.ek[373] );
    cynw_interpret( (sc_uint<8>)from.range( 6996,6989 ), to.ek[374] );
    cynw_interpret( (sc_uint<8>)from.range( 6988,6981 ), to.ek[375] );
    cynw_interpret( (sc_uint<8>)from.range( 6980,6973 ), to.ek[376] );
    cynw_interpret( (sc_uint<8>)from.range( 6972,6965 ), to.ek[377] );
    cynw_interpret( (sc_uint<8>)from.range( 6964,6957 ), to.ek[378] );
    cynw_interpret( (sc_uint<8>)from.range( 6956,6949 ), to.ek[379] );
    cynw_interpret( (sc_uint<8>)from.range( 6948,6941 ), to.ek[380] );
    cynw_interpret( (sc_uint<8>)from.range( 6940,6933 ), to.ek[381] );
    cynw_interpret( (sc_uint<8>)from.range( 6932,6925 ), to.ek[382] );
    cynw_interpret( (sc_uint<8>)from.range( 6924,6917 ), to.ek[383] );
    cynw_interpret( (sc_uint<8>)from.range( 6916,6909 ), to.ek[384] );
    cynw_interpret( (sc_uint<8>)from.range( 6908,6901 ), to.ek[385] );
    cynw_interpret( (sc_uint<8>)from.range( 6900,6893 ), to.ek[386] );
    cynw_interpret( (sc_uint<8>)from.range( 6892,6885 ), to.ek[387] );
    cynw_interpret( (sc_uint<8>)from.range( 6884,6877 ), to.ek[388] );
    cynw_interpret( (sc_uint<8>)from.range( 6876,6869 ), to.ek[389] );
    cynw_interpret( (sc_uint<8>)from.range( 6868,6861 ), to.ek[390] );
    cynw_interpret( (sc_uint<8>)from.range( 6860,6853 ), to.ek[391] );
    cynw_interpret( (sc_uint<8>)from.range( 6852,6845 ), to.ek[392] );
    cynw_interpret( (sc_uint<8>)from.range( 6844,6837 ), to.ek[393] );
    cynw_interpret( (sc_uint<8>)from.range( 6836,6829 ), to.ek[394] );
    cynw_interpret( (sc_uint<8>)from.range( 6828,6821 ), to.ek[395] );
    cynw_interpret( (sc_uint<8>)from.range( 6820,6813 ), to.ek[396] );
    cynw_interpret( (sc_uint<8>)from.range( 6812,6805 ), to.ek[397] );
    cynw_interpret( (sc_uint<8>)from.range( 6804,6797 ), to.ek[398] );
    cynw_interpret( (sc_uint<8>)from.range( 6796,6789 ), to.ek[399] );
    cynw_interpret( (sc_uint<8>)from.range( 6788,6781 ), to.ek[400] );
    cynw_interpret( (sc_uint<8>)from.range( 6780,6773 ), to.ek[401] );
    cynw_interpret( (sc_uint<8>)from.range( 6772,6765 ), to.ek[402] );
    cynw_interpret( (sc_uint<8>)from.range( 6764,6757 ), to.ek[403] );
    cynw_interpret( (sc_uint<8>)from.range( 6756,6749 ), to.ek[404] );
    cynw_interpret( (sc_uint<8>)from.range( 6748,6741 ), to.ek[405] );
    cynw_interpret( (sc_uint<8>)from.range( 6740,6733 ), to.ek[406] );
    cynw_interpret( (sc_uint<8>)from.range( 6732,6725 ), to.ek[407] );
    cynw_interpret( (sc_uint<8>)from.range( 6724,6717 ), to.ek[408] );
    cynw_interpret( (sc_uint<8>)from.range( 6716,6709 ), to.ek[409] );
    cynw_interpret( (sc_uint<8>)from.range( 6708,6701 ), to.ek[410] );
    cynw_interpret( (sc_uint<8>)from.range( 6700,6693 ), to.ek[411] );
    cynw_interpret( (sc_uint<8>)from.range( 6692,6685 ), to.ek[412] );
    cynw_interpret( (sc_uint<8>)from.range( 6684,6677 ), to.ek[413] );
    cynw_interpret( (sc_uint<8>)from.range( 6676,6669 ), to.ek[414] );
    cynw_interpret( (sc_uint<8>)from.range( 6668,6661 ), to.ek[415] );
    cynw_interpret( (sc_uint<8>)from.range( 6660,6653 ), to.ek[416] );
    cynw_interpret( (sc_uint<8>)from.range( 6652,6645 ), to.ek[417] );
    cynw_interpret( (sc_uint<8>)from.range( 6644,6637 ), to.ek[418] );
    cynw_interpret( (sc_uint<8>)from.range( 6636,6629 ), to.ek[419] );
    cynw_interpret( (sc_uint<8>)from.range( 6628,6621 ), to.ek[420] );
    cynw_interpret( (sc_uint<8>)from.range( 6620,6613 ), to.ek[421] );
    cynw_interpret( (sc_uint<8>)from.range( 6612,6605 ), to.ek[422] );
    cynw_interpret( (sc_uint<8>)from.range( 6604,6597 ), to.ek[423] );
    cynw_interpret( (sc_uint<8>)from.range( 6596,6589 ), to.ek[424] );
    cynw_interpret( (sc_uint<8>)from.range( 6588,6581 ), to.ek[425] );
    cynw_interpret( (sc_uint<8>)from.range( 6580,6573 ), to.ek[426] );
    cynw_interpret( (sc_uint<8>)from.range( 6572,6565 ), to.ek[427] );
    cynw_interpret( (sc_uint<8>)from.range( 6564,6557 ), to.ek[428] );
    cynw_interpret( (sc_uint<8>)from.range( 6556,6549 ), to.ek[429] );
    cynw_interpret( (sc_uint<8>)from.range( 6548,6541 ), to.ek[430] );
    cynw_interpret( (sc_uint<8>)from.range( 6540,6533 ), to.ek[431] );
    cynw_interpret( (sc_uint<8>)from.range( 6532,6525 ), to.ek[432] );
    cynw_interpret( (sc_uint<8>)from.range( 6524,6517 ), to.ek[433] );
    cynw_interpret( (sc_uint<8>)from.range( 6516,6509 ), to.ek[434] );
    cynw_interpret( (sc_uint<8>)from.range( 6508,6501 ), to.ek[435] );
    cynw_interpret( (sc_uint<8>)from.range( 6500,6493 ), to.ek[436] );
    cynw_interpret( (sc_uint<8>)from.range( 6492,6485 ), to.ek[437] );
    cynw_interpret( (sc_uint<8>)from.range( 6484,6477 ), to.ek[438] );
    cynw_interpret( (sc_uint<8>)from.range( 6476,6469 ), to.ek[439] );
    cynw_interpret( (sc_uint<8>)from.range( 6468,6461 ), to.ek[440] );
    cynw_interpret( (sc_uint<8>)from.range( 6460,6453 ), to.ek[441] );
    cynw_interpret( (sc_uint<8>)from.range( 6452,6445 ), to.ek[442] );
    cynw_interpret( (sc_uint<8>)from.range( 6444,6437 ), to.ek[443] );
    cynw_interpret( (sc_uint<8>)from.range( 6436,6429 ), to.ek[444] );
    cynw_interpret( (sc_uint<8>)from.range( 6428,6421 ), to.ek[445] );
    cynw_interpret( (sc_uint<8>)from.range( 6420,6413 ), to.ek[446] );
    cynw_interpret( (sc_uint<8>)from.range( 6412,6405 ), to.ek[447] );
    cynw_interpret( (sc_uint<8>)from.range( 6404,6397 ), to.ek[448] );
    cynw_interpret( (sc_uint<8>)from.range( 6396,6389 ), to.ek[449] );
    cynw_interpret( (sc_uint<8>)from.range( 6388,6381 ), to.ek[450] );
    cynw_interpret( (sc_uint<8>)from.range( 6380,6373 ), to.ek[451] );
    cynw_interpret( (sc_uint<8>)from.range( 6372,6365 ), to.ek[452] );
    cynw_interpret( (sc_uint<8>)from.range( 6364,6357 ), to.ek[453] );
    cynw_interpret( (sc_uint<8>)from.range( 6356,6349 ), to.ek[454] );
    cynw_interpret( (sc_uint<8>)from.range( 6348,6341 ), to.ek[455] );
    cynw_interpret( (sc_uint<8>)from.range( 6340,6333 ), to.ek[456] );
    cynw_interpret( (sc_uint<8>)from.range( 6332,6325 ), to.ek[457] );
    cynw_interpret( (sc_uint<8>)from.range( 6324,6317 ), to.ek[458] );
    cynw_interpret( (sc_uint<8>)from.range( 6316,6309 ), to.ek[459] );
    cynw_interpret( (sc_uint<8>)from.range( 6308,6301 ), to.ek[460] );
    cynw_interpret( (sc_uint<8>)from.range( 6300,6293 ), to.ek[461] );
    cynw_interpret( (sc_uint<8>)from.range( 6292,6285 ), to.ek[462] );
    cynw_interpret( (sc_uint<8>)from.range( 6284,6277 ), to.ek[463] );
    cynw_interpret( (sc_uint<8>)from.range( 6276,6269 ), to.ek[464] );
    cynw_interpret( (sc_uint<8>)from.range( 6268,6261 ), to.ek[465] );
    cynw_interpret( (sc_uint<8>)from.range( 6260,6253 ), to.ek[466] );
    cynw_interpret( (sc_uint<8>)from.range( 6252,6245 ), to.ek[467] );
    cynw_interpret( (sc_uint<8>)from.range( 6244,6237 ), to.ek[468] );
    cynw_interpret( (sc_uint<8>)from.range( 6236,6229 ), to.ek[469] );
    cynw_interpret( (sc_uint<8>)from.range( 6228,6221 ), to.ek[470] );
    cynw_interpret( (sc_uint<8>)from.range( 6220,6213 ), to.ek[471] );
    cynw_interpret( (sc_uint<8>)from.range( 6212,6205 ), to.ek[472] );
    cynw_interpret( (sc_uint<8>)from.range( 6204,6197 ), to.ek[473] );
    cynw_interpret( (sc_uint<8>)from.range( 6196,6189 ), to.ek[474] );
    cynw_interpret( (sc_uint<8>)from.range( 6188,6181 ), to.ek[475] );
    cynw_interpret( (sc_uint<8>)from.range( 6180,6173 ), to.ek[476] );
    cynw_interpret( (sc_uint<8>)from.range( 6172,6165 ), to.ek[477] );
    cynw_interpret( (sc_uint<8>)from.range( 6164,6157 ), to.ek[478] );
    cynw_interpret( (sc_uint<8>)from.range( 6156,6149 ), to.ek[479] );
    cynw_interpret( (sc_uint<8>)from.range( 6148,6141 ), to.ek[480] );
    cynw_interpret( (sc_uint<8>)from.range( 6140,6133 ), to.ek[481] );
    cynw_interpret( (sc_uint<8>)from.range( 6132,6125 ), to.ek[482] );
    cynw_interpret( (sc_uint<8>)from.range( 6124,6117 ), to.ek[483] );
    cynw_interpret( (sc_uint<8>)from.range( 6116,6109 ), to.ek[484] );
    cynw_interpret( (sc_uint<8>)from.range( 6108,6101 ), to.ek[485] );
    cynw_interpret( (sc_uint<8>)from.range( 6100,6093 ), to.ek[486] );
    cynw_interpret( (sc_uint<8>)from.range( 6092,6085 ), to.ek[487] );
    cynw_interpret( (sc_uint<8>)from.range( 6084,6077 ), to.ek[488] );
    cynw_interpret( (sc_uint<8>)from.range( 6076,6069 ), to.ek[489] );
    cynw_interpret( (sc_uint<8>)from.range( 6068,6061 ), to.ek[490] );
    cynw_interpret( (sc_uint<8>)from.range( 6060,6053 ), to.ek[491] );
    cynw_interpret( (sc_uint<8>)from.range( 6052,6045 ), to.ek[492] );
    cynw_interpret( (sc_uint<8>)from.range( 6044,6037 ), to.ek[493] );
    cynw_interpret( (sc_uint<8>)from.range( 6036,6029 ), to.ek[494] );
    cynw_interpret( (sc_uint<8>)from.range( 6028,6021 ), to.ek[495] );
    cynw_interpret( (sc_uint<8>)from.range( 6020,6013 ), to.ek[496] );
    cynw_interpret( (sc_uint<8>)from.range( 6012,6005 ), to.ek[497] );
    cynw_interpret( (sc_uint<8>)from.range( 6004,5997 ), to.ek[498] );
    cynw_interpret( (sc_uint<8>)from.range( 5996,5989 ), to.ek[499] );
    cynw_interpret( (sc_uint<8>)from.range( 5988,5981 ), to.ek[500] );
    cynw_interpret( (sc_uint<8>)from.range( 5980,5973 ), to.ek[501] );
    cynw_interpret( (sc_uint<8>)from.range( 5972,5965 ), to.ek[502] );
    cynw_interpret( (sc_uint<8>)from.range( 5964,5957 ), to.ek[503] );
    cynw_interpret( (sc_uint<8>)from.range( 5956,5949 ), to.ek[504] );
    cynw_interpret( (sc_uint<8>)from.range( 5948,5941 ), to.ek[505] );
    cynw_interpret( (sc_uint<8>)from.range( 5940,5933 ), to.ek[506] );
    cynw_interpret( (sc_uint<8>)from.range( 5932,5925 ), to.ek[507] );
    cynw_interpret( (sc_uint<8>)from.range( 5924,5917 ), to.ek[508] );
    cynw_interpret( (sc_uint<8>)from.range( 5916,5909 ), to.ek[509] );
    cynw_interpret( (sc_uint<8>)from.range( 5908,5901 ), to.ek[510] );
    cynw_interpret( (sc_uint<8>)from.range( 5900,5893 ), to.ek[511] );
    cynw_interpret( (sc_uint<8>)from.range( 5892,5885 ), to.ek[512] );
    cynw_interpret( (sc_uint<8>)from.range( 5884,5877 ), to.ek[513] );
    cynw_interpret( (sc_uint<8>)from.range( 5876,5869 ), to.ek[514] );
    cynw_interpret( (sc_uint<8>)from.range( 5868,5861 ), to.ek[515] );
    cynw_interpret( (sc_uint<8>)from.range( 5860,5853 ), to.ek[516] );
    cynw_interpret( (sc_uint<8>)from.range( 5852,5845 ), to.ek[517] );
    cynw_interpret( (sc_uint<8>)from.range( 5844,5837 ), to.ek[518] );
    cynw_interpret( (sc_uint<8>)from.range( 5836,5829 ), to.ek[519] );
    cynw_interpret( (sc_uint<8>)from.range( 5828,5821 ), to.ek[520] );
    cynw_interpret( (sc_uint<8>)from.range( 5820,5813 ), to.ek[521] );
    cynw_interpret( (sc_uint<8>)from.range( 5812,5805 ), to.ek[522] );
    cynw_interpret( (sc_uint<8>)from.range( 5804,5797 ), to.ek[523] );
    cynw_interpret( (sc_uint<8>)from.range( 5796,5789 ), to.ek[524] );
    cynw_interpret( (sc_uint<8>)from.range( 5788,5781 ), to.ek[525] );
    cynw_interpret( (sc_uint<8>)from.range( 5780,5773 ), to.ek[526] );
    cynw_interpret( (sc_uint<8>)from.range( 5772,5765 ), to.ek[527] );
    cynw_interpret( (sc_uint<8>)from.range( 5764,5757 ), to.ek[528] );
    cynw_interpret( (sc_uint<8>)from.range( 5756,5749 ), to.ek[529] );
    cynw_interpret( (sc_uint<8>)from.range( 5748,5741 ), to.ek[530] );
    cynw_interpret( (sc_uint<8>)from.range( 5740,5733 ), to.ek[531] );
    cynw_interpret( (sc_uint<8>)from.range( 5732,5725 ), to.ek[532] );
    cynw_interpret( (sc_uint<8>)from.range( 5724,5717 ), to.ek[533] );
    cynw_interpret( (sc_uint<8>)from.range( 5716,5709 ), to.ek[534] );
    cynw_interpret( (sc_uint<8>)from.range( 5708,5701 ), to.ek[535] );
    cynw_interpret( (sc_uint<8>)from.range( 5700,5693 ), to.ek[536] );
    cynw_interpret( (sc_uint<8>)from.range( 5692,5685 ), to.ek[537] );
    cynw_interpret( (sc_uint<8>)from.range( 5684,5677 ), to.ek[538] );
    cynw_interpret( (sc_uint<8>)from.range( 5676,5669 ), to.ek[539] );
    cynw_interpret( (sc_uint<8>)from.range( 5668,5661 ), to.ek[540] );
    cynw_interpret( (sc_uint<8>)from.range( 5660,5653 ), to.ek[541] );
    cynw_interpret( (sc_uint<8>)from.range( 5652,5645 ), to.ek[542] );
    cynw_interpret( (sc_uint<8>)from.range( 5644,5637 ), to.ek[543] );
    cynw_interpret( (sc_uint<8>)from.range( 5636,5629 ), to.ek[544] );
    cynw_interpret( (sc_uint<8>)from.range( 5628,5621 ), to.ek[545] );
    cynw_interpret( (sc_uint<8>)from.range( 5620,5613 ), to.ek[546] );
    cynw_interpret( (sc_uint<8>)from.range( 5612,5605 ), to.ek[547] );
    cynw_interpret( (sc_uint<8>)from.range( 5604,5597 ), to.ek[548] );
    cynw_interpret( (sc_uint<8>)from.range( 5596,5589 ), to.ek[549] );
    cynw_interpret( (sc_uint<8>)from.range( 5588,5581 ), to.ek[550] );
    cynw_interpret( (sc_uint<8>)from.range( 5580,5573 ), to.ek[551] );
    cynw_interpret( (sc_uint<8>)from.range( 5572,5565 ), to.ek[552] );
    cynw_interpret( (sc_uint<8>)from.range( 5564,5557 ), to.ek[553] );
    cynw_interpret( (sc_uint<8>)from.range( 5556,5549 ), to.ek[554] );
    cynw_interpret( (sc_uint<8>)from.range( 5548,5541 ), to.ek[555] );
    cynw_interpret( (sc_uint<8>)from.range( 5540,5533 ), to.ek[556] );
    cynw_interpret( (sc_uint<8>)from.range( 5532,5525 ), to.ek[557] );
    cynw_interpret( (sc_uint<8>)from.range( 5524,5517 ), to.ek[558] );
    cynw_interpret( (sc_uint<8>)from.range( 5516,5509 ), to.ek[559] );
    cynw_interpret( (sc_uint<8>)from.range( 5508,5501 ), to.ek[560] );
    cynw_interpret( (sc_uint<8>)from.range( 5500,5493 ), to.ek[561] );
    cynw_interpret( (sc_uint<8>)from.range( 5492,5485 ), to.ek[562] );
    cynw_interpret( (sc_uint<8>)from.range( 5484,5477 ), to.ek[563] );
    cynw_interpret( (sc_uint<8>)from.range( 5476,5469 ), to.ek[564] );
    cynw_interpret( (sc_uint<8>)from.range( 5468,5461 ), to.ek[565] );
    cynw_interpret( (sc_uint<8>)from.range( 5460,5453 ), to.ek[566] );
    cynw_interpret( (sc_uint<8>)from.range( 5452,5445 ), to.ek[567] );
    cynw_interpret( (sc_uint<8>)from.range( 5444,5437 ), to.ek[568] );
    cynw_interpret( (sc_uint<8>)from.range( 5436,5429 ), to.ek[569] );
    cynw_interpret( (sc_uint<8>)from.range( 5428,5421 ), to.ek[570] );
    cynw_interpret( (sc_uint<8>)from.range( 5420,5413 ), to.ek[571] );
    cynw_interpret( (sc_uint<8>)from.range( 5412,5405 ), to.ek[572] );
    cynw_interpret( (sc_uint<8>)from.range( 5404,5397 ), to.ek[573] );
    cynw_interpret( (sc_uint<8>)from.range( 5396,5389 ), to.ek[574] );
    cynw_interpret( (sc_uint<8>)from.range( 5388,5381 ), to.ek[575] );
    cynw_interpret( (sc_uint<8>)from.range( 5380,5373 ), to.ek[576] );
    cynw_interpret( (sc_uint<8>)from.range( 5372,5365 ), to.ek[577] );
    cynw_interpret( (sc_uint<8>)from.range( 5364,5357 ), to.ek[578] );
    cynw_interpret( (sc_uint<8>)from.range( 5356,5349 ), to.ek[579] );
    cynw_interpret( (sc_uint<8>)from.range( 5348,5341 ), to.ek[580] );
    cynw_interpret( (sc_uint<8>)from.range( 5340,5333 ), to.ek[581] );
    cynw_interpret( (sc_uint<8>)from.range( 5332,5325 ), to.ek[582] );
    cynw_interpret( (sc_uint<8>)from.range( 5324,5317 ), to.ek[583] );
    cynw_interpret( (sc_uint<8>)from.range( 5316,5309 ), to.ek[584] );
    cynw_interpret( (sc_uint<8>)from.range( 5308,5301 ), to.ek[585] );
    cynw_interpret( (sc_uint<8>)from.range( 5300,5293 ), to.ek[586] );
    cynw_interpret( (sc_uint<8>)from.range( 5292,5285 ), to.ek[587] );
    cynw_interpret( (sc_uint<8>)from.range( 5284,5277 ), to.ek[588] );
    cynw_interpret( (sc_uint<8>)from.range( 5276,5269 ), to.ek[589] );
    cynw_interpret( (sc_uint<8>)from.range( 5268,5261 ), to.ek[590] );
    cynw_interpret( (sc_uint<8>)from.range( 5260,5253 ), to.ek[591] );
    cynw_interpret( (sc_uint<8>)from.range( 5252,5245 ), to.ek[592] );
    cynw_interpret( (sc_uint<8>)from.range( 5244,5237 ), to.ek[593] );
    cynw_interpret( (sc_uint<8>)from.range( 5236,5229 ), to.ek[594] );
    cynw_interpret( (sc_uint<8>)from.range( 5228,5221 ), to.ek[595] );
    cynw_interpret( (sc_uint<8>)from.range( 5220,5213 ), to.ek[596] );
    cynw_interpret( (sc_uint<8>)from.range( 5212,5205 ), to.ek[597] );
    cynw_interpret( (sc_uint<8>)from.range( 5204,5197 ), to.ek[598] );
    cynw_interpret( (sc_uint<8>)from.range( 5196,5189 ), to.ek[599] );
    cynw_interpret( (sc_uint<8>)from.range( 5188,5181 ), to.ek[600] );
    cynw_interpret( (sc_uint<8>)from.range( 5180,5173 ), to.ek[601] );
    cynw_interpret( (sc_uint<8>)from.range( 5172,5165 ), to.ek[602] );
    cynw_interpret( (sc_uint<8>)from.range( 5164,5157 ), to.ek[603] );
    cynw_interpret( (sc_uint<8>)from.range( 5156,5149 ), to.ek[604] );
    cynw_interpret( (sc_uint<8>)from.range( 5148,5141 ), to.ek[605] );
    cynw_interpret( (sc_uint<8>)from.range( 5140,5133 ), to.ek[606] );
    cynw_interpret( (sc_uint<8>)from.range( 5132,5125 ), to.ek[607] );
    cynw_interpret( (sc_uint<8>)from.range( 5124,5117 ), to.ek[608] );
    cynw_interpret( (sc_uint<8>)from.range( 5116,5109 ), to.ek[609] );
    cynw_interpret( (sc_uint<8>)from.range( 5108,5101 ), to.ek[610] );
    cynw_interpret( (sc_uint<8>)from.range( 5100,5093 ), to.ek[611] );
    cynw_interpret( (sc_uint<8>)from.range( 5092,5085 ), to.ek[612] );
    cynw_interpret( (sc_uint<8>)from.range( 5084,5077 ), to.ek[613] );
    cynw_interpret( (sc_uint<8>)from.range( 5076,5069 ), to.ek[614] );
    cynw_interpret( (sc_uint<8>)from.range( 5068,5061 ), to.ek[615] );
    cynw_interpret( (sc_uint<8>)from.range( 5060,5053 ), to.ek[616] );
    cynw_interpret( (sc_uint<8>)from.range( 5052,5045 ), to.ek[617] );
    cynw_interpret( (sc_uint<8>)from.range( 5044,5037 ), to.ek[618] );
    cynw_interpret( (sc_uint<8>)from.range( 5036,5029 ), to.ek[619] );
    cynw_interpret( (sc_uint<8>)from.range( 5028,5021 ), to.ek[620] );
    cynw_interpret( (sc_uint<8>)from.range( 5020,5013 ), to.ek[621] );
    cynw_interpret( (sc_uint<8>)from.range( 5012,5005 ), to.ek[622] );
    cynw_interpret( (sc_uint<8>)from.range( 5004,4997 ), to.ek[623] );
    cynw_interpret( (sc_uint<8>)from.range( 4996,4989 ), to.ek[624] );
    cynw_interpret( (sc_uint<8>)from.range( 4988,4981 ), to.ek[625] );
    cynw_interpret( (sc_uint<8>)from.range( 4980,4973 ), to.ek[626] );
    cynw_interpret( (sc_uint<8>)from.range( 4972,4965 ), to.ek[627] );
    cynw_interpret( (sc_uint<8>)from.range( 4964,4957 ), to.ek[628] );
    cynw_interpret( (sc_uint<8>)from.range( 4956,4949 ), to.ek[629] );
    cynw_interpret( (sc_uint<8>)from.range( 4948,4941 ), to.ek[630] );
    cynw_interpret( (sc_uint<8>)from.range( 4940,4933 ), to.ek[631] );
    cynw_interpret( (sc_uint<8>)from.range( 4932,4925 ), to.ek[632] );
    cynw_interpret( (sc_uint<8>)from.range( 4924,4917 ), to.ek[633] );
    cynw_interpret( (sc_uint<8>)from.range( 4916,4909 ), to.ek[634] );
    cynw_interpret( (sc_uint<8>)from.range( 4908,4901 ), to.ek[635] );
    cynw_interpret( (sc_uint<8>)from.range( 4900,4893 ), to.ek[636] );
    cynw_interpret( (sc_uint<8>)from.range( 4892,4885 ), to.ek[637] );
    cynw_interpret( (sc_uint<8>)from.range( 4884,4877 ), to.ek[638] );
    cynw_interpret( (sc_uint<8>)from.range( 4876,4869 ), to.ek[639] );
    cynw_interpret( (sc_uint<8>)from.range( 4868,4861 ), to.ek[640] );
    cynw_interpret( (sc_uint<8>)from.range( 4860,4853 ), to.ek[641] );
    cynw_interpret( (sc_uint<8>)from.range( 4852,4845 ), to.ek[642] );
    cynw_interpret( (sc_uint<8>)from.range( 4844,4837 ), to.ek[643] );
    cynw_interpret( (sc_uint<8>)from.range( 4836,4829 ), to.ek[644] );
    cynw_interpret( (sc_uint<8>)from.range( 4828,4821 ), to.ek[645] );
    cynw_interpret( (sc_uint<8>)from.range( 4820,4813 ), to.ek[646] );
    cynw_interpret( (sc_uint<8>)from.range( 4812,4805 ), to.ek[647] );
    cynw_interpret( (sc_uint<8>)from.range( 4804,4797 ), to.ek[648] );
    cynw_interpret( (sc_uint<8>)from.range( 4796,4789 ), to.ek[649] );
    cynw_interpret( (sc_uint<8>)from.range( 4788,4781 ), to.ek[650] );
    cynw_interpret( (sc_uint<8>)from.range( 4780,4773 ), to.ek[651] );
    cynw_interpret( (sc_uint<8>)from.range( 4772,4765 ), to.ek[652] );
    cynw_interpret( (sc_uint<8>)from.range( 4764,4757 ), to.ek[653] );
    cynw_interpret( (sc_uint<8>)from.range( 4756,4749 ), to.ek[654] );
    cynw_interpret( (sc_uint<8>)from.range( 4748,4741 ), to.ek[655] );
    cynw_interpret( (sc_uint<8>)from.range( 4740,4733 ), to.ek[656] );
    cynw_interpret( (sc_uint<8>)from.range( 4732,4725 ), to.ek[657] );
    cynw_interpret( (sc_uint<8>)from.range( 4724,4717 ), to.ek[658] );
    cynw_interpret( (sc_uint<8>)from.range( 4716,4709 ), to.ek[659] );
    cynw_interpret( (sc_uint<8>)from.range( 4708,4701 ), to.ek[660] );
    cynw_interpret( (sc_uint<8>)from.range( 4700,4693 ), to.ek[661] );
    cynw_interpret( (sc_uint<8>)from.range( 4692,4685 ), to.ek[662] );
    cynw_interpret( (sc_uint<8>)from.range( 4684,4677 ), to.ek[663] );
    cynw_interpret( (sc_uint<8>)from.range( 4676,4669 ), to.ek[664] );
    cynw_interpret( (sc_uint<8>)from.range( 4668,4661 ), to.ek[665] );
    cynw_interpret( (sc_uint<8>)from.range( 4660,4653 ), to.ek[666] );
    cynw_interpret( (sc_uint<8>)from.range( 4652,4645 ), to.ek[667] );
    cynw_interpret( (sc_uint<8>)from.range( 4644,4637 ), to.ek[668] );
    cynw_interpret( (sc_uint<8>)from.range( 4636,4629 ), to.ek[669] );
    cynw_interpret( (sc_uint<8>)from.range( 4628,4621 ), to.ek[670] );
    cynw_interpret( (sc_uint<8>)from.range( 4620,4613 ), to.ek[671] );
    cynw_interpret( (sc_uint<8>)from.range( 4612,4605 ), to.ek[672] );
    cynw_interpret( (sc_uint<8>)from.range( 4604,4597 ), to.ek[673] );
    cynw_interpret( (sc_uint<8>)from.range( 4596,4589 ), to.ek[674] );
    cynw_interpret( (sc_uint<8>)from.range( 4588,4581 ), to.ek[675] );
    cynw_interpret( (sc_uint<8>)from.range( 4580,4573 ), to.ek[676] );
    cynw_interpret( (sc_uint<8>)from.range( 4572,4565 ), to.ek[677] );
    cynw_interpret( (sc_uint<8>)from.range( 4564,4557 ), to.ek[678] );
    cynw_interpret( (sc_uint<8>)from.range( 4556,4549 ), to.ek[679] );
    cynw_interpret( (sc_uint<8>)from.range( 4548,4541 ), to.ek[680] );
    cynw_interpret( (sc_uint<8>)from.range( 4540,4533 ), to.ek[681] );
    cynw_interpret( (sc_uint<8>)from.range( 4532,4525 ), to.ek[682] );
    cynw_interpret( (sc_uint<8>)from.range( 4524,4517 ), to.ek[683] );
    cynw_interpret( (sc_uint<8>)from.range( 4516,4509 ), to.ek[684] );
    cynw_interpret( (sc_uint<8>)from.range( 4508,4501 ), to.ek[685] );
    cynw_interpret( (sc_uint<8>)from.range( 4500,4493 ), to.ek[686] );
    cynw_interpret( (sc_uint<8>)from.range( 4492,4485 ), to.ek[687] );
    cynw_interpret( (sc_uint<8>)from.range( 4484,4477 ), to.ek[688] );
    cynw_interpret( (sc_uint<8>)from.range( 4476,4469 ), to.ek[689] );
    cynw_interpret( (sc_uint<8>)from.range( 4468,4461 ), to.ek[690] );
    cynw_interpret( (sc_uint<8>)from.range( 4460,4453 ), to.ek[691] );
    cynw_interpret( (sc_uint<8>)from.range( 4452,4445 ), to.ek[692] );
    cynw_interpret( (sc_uint<8>)from.range( 4444,4437 ), to.ek[693] );
    cynw_interpret( (sc_uint<8>)from.range( 4436,4429 ), to.ek[694] );
    cynw_interpret( (sc_uint<8>)from.range( 4428,4421 ), to.ek[695] );
    cynw_interpret( (sc_uint<8>)from.range( 4420,4413 ), to.ek[696] );
    cynw_interpret( (sc_uint<8>)from.range( 4412,4405 ), to.ek[697] );
    cynw_interpret( (sc_uint<8>)from.range( 4404,4397 ), to.ek[698] );
    cynw_interpret( (sc_uint<8>)from.range( 4396,4389 ), to.ek[699] );
    cynw_interpret( (sc_uint<8>)from.range( 4388,4381 ), to.ek[700] );
    cynw_interpret( (sc_uint<8>)from.range( 4380,4373 ), to.ek[701] );
    cynw_interpret( (sc_uint<8>)from.range( 4372,4365 ), to.ek[702] );
    cynw_interpret( (sc_uint<8>)from.range( 4364,4357 ), to.ek[703] );
    cynw_interpret( (sc_uint<8>)from.range( 4356,4349 ), to.ek[704] );
    cynw_interpret( (sc_uint<8>)from.range( 4348,4341 ), to.ek[705] );
    cynw_interpret( (sc_uint<8>)from.range( 4340,4333 ), to.ek[706] );
    cynw_interpret( (sc_uint<8>)from.range( 4332,4325 ), to.ek[707] );
    cynw_interpret( (sc_uint<8>)from.range( 4324,4317 ), to.ek[708] );
    cynw_interpret( (sc_uint<8>)from.range( 4316,4309 ), to.ek[709] );
    cynw_interpret( (sc_uint<8>)from.range( 4308,4301 ), to.ek[710] );
    cynw_interpret( (sc_uint<8>)from.range( 4300,4293 ), to.ek[711] );
    cynw_interpret( (sc_uint<8>)from.range( 4292,4285 ), to.ek[712] );
    cynw_interpret( (sc_uint<8>)from.range( 4284,4277 ), to.ek[713] );
    cynw_interpret( (sc_uint<8>)from.range( 4276,4269 ), to.ek[714] );
    cynw_interpret( (sc_uint<8>)from.range( 4268,4261 ), to.ek[715] );
    cynw_interpret( (sc_uint<8>)from.range( 4260,4253 ), to.ek[716] );
    cynw_interpret( (sc_uint<8>)from.range( 4252,4245 ), to.ek[717] );
    cynw_interpret( (sc_uint<8>)from.range( 4244,4237 ), to.ek[718] );
    cynw_interpret( (sc_uint<8>)from.range( 4236,4229 ), to.ek[719] );
    cynw_interpret( (sc_uint<8>)from.range( 4228,4221 ), to.ek[720] );
    cynw_interpret( (sc_uint<8>)from.range( 4220,4213 ), to.ek[721] );
    cynw_interpret( (sc_uint<8>)from.range( 4212,4205 ), to.ek[722] );
    cynw_interpret( (sc_uint<8>)from.range( 4204,4197 ), to.ek[723] );
    cynw_interpret( (sc_uint<8>)from.range( 4196,4189 ), to.ek[724] );
    cynw_interpret( (sc_uint<8>)from.range( 4188,4181 ), to.ek[725] );
    cynw_interpret( (sc_uint<8>)from.range( 4180,4173 ), to.ek[726] );
    cynw_interpret( (sc_uint<8>)from.range( 4172,4165 ), to.ek[727] );
    cynw_interpret( (sc_uint<8>)from.range( 4164,4157 ), to.ek[728] );
    cynw_interpret( (sc_uint<8>)from.range( 4156,4149 ), to.ek[729] );
    cynw_interpret( (sc_uint<8>)from.range( 4148,4141 ), to.ek[730] );
    cynw_interpret( (sc_uint<8>)from.range( 4140,4133 ), to.ek[731] );
    cynw_interpret( (sc_uint<8>)from.range( 4132,4125 ), to.ek[732] );
    cynw_interpret( (sc_uint<8>)from.range( 4124,4117 ), to.ek[733] );
    cynw_interpret( (sc_uint<8>)from.range( 4116,4109 ), to.ek[734] );
    cynw_interpret( (sc_uint<8>)from.range( 4108,4101 ), to.ek[735] );
    cynw_interpret( (sc_uint<8>)from.range( 4100,4093 ), to.ek[736] );
    cynw_interpret( (sc_uint<8>)from.range( 4092,4085 ), to.ek[737] );
    cynw_interpret( (sc_uint<8>)from.range( 4084,4077 ), to.ek[738] );
    cynw_interpret( (sc_uint<8>)from.range( 4076,4069 ), to.ek[739] );
    cynw_interpret( (sc_uint<8>)from.range( 4068,4061 ), to.ek[740] );
    cynw_interpret( (sc_uint<8>)from.range( 4060,4053 ), to.ek[741] );
    cynw_interpret( (sc_uint<8>)from.range( 4052,4045 ), to.ek[742] );
    cynw_interpret( (sc_uint<8>)from.range( 4044,4037 ), to.ek[743] );
    cynw_interpret( (sc_uint<8>)from.range( 4036,4029 ), to.ek[744] );
    cynw_interpret( (sc_uint<8>)from.range( 4028,4021 ), to.ek[745] );
    cynw_interpret( (sc_uint<8>)from.range( 4020,4013 ), to.ek[746] );
    cynw_interpret( (sc_uint<8>)from.range( 4012,4005 ), to.ek[747] );
    cynw_interpret( (sc_uint<8>)from.range( 4004,3997 ), to.ek[748] );
    cynw_interpret( (sc_uint<8>)from.range( 3996,3989 ), to.ek[749] );
    cynw_interpret( (sc_uint<8>)from.range( 3988,3981 ), to.ek[750] );
    cynw_interpret( (sc_uint<8>)from.range( 3980,3973 ), to.ek[751] );
    cynw_interpret( (sc_uint<8>)from.range( 3972,3965 ), to.ek[752] );
    cynw_interpret( (sc_uint<8>)from.range( 3964,3957 ), to.ek[753] );
    cynw_interpret( (sc_uint<8>)from.range( 3956,3949 ), to.ek[754] );
    cynw_interpret( (sc_uint<8>)from.range( 3948,3941 ), to.ek[755] );
    cynw_interpret( (sc_uint<8>)from.range( 3940,3933 ), to.ek[756] );
    cynw_interpret( (sc_uint<8>)from.range( 3932,3925 ), to.ek[757] );
    cynw_interpret( (sc_uint<8>)from.range( 3924,3917 ), to.ek[758] );
    cynw_interpret( (sc_uint<8>)from.range( 3916,3909 ), to.ek[759] );
    cynw_interpret( (sc_uint<8>)from.range( 3908,3901 ), to.ek[760] );
    cynw_interpret( (sc_uint<8>)from.range( 3900,3893 ), to.ek[761] );
    cynw_interpret( (sc_uint<8>)from.range( 3892,3885 ), to.ek[762] );
    cynw_interpret( (sc_uint<8>)from.range( 3884,3877 ), to.ek[763] );
    cynw_interpret( (sc_uint<8>)from.range( 3876,3869 ), to.ek[764] );
    cynw_interpret( (sc_uint<8>)from.range( 3868,3861 ), to.ek[765] );
    cynw_interpret( (sc_uint<8>)from.range( 3860,3853 ), to.ek[766] );
    cynw_interpret( (sc_uint<8>)from.range( 3852,3845 ), to.ek[767] );
    cynw_interpret( (sc_uint<8>)from.range( 3844,3837 ), to.ek[768] );
    cynw_interpret( (sc_uint<8>)from.range( 3836,3829 ), to.ek[769] );
    cynw_interpret( (sc_uint<8>)from.range( 3828,3821 ), to.ek[770] );
    cynw_interpret( (sc_uint<8>)from.range( 3820,3813 ), to.ek[771] );
    cynw_interpret( (sc_uint<8>)from.range( 3812,3805 ), to.ek[772] );
    cynw_interpret( (sc_uint<8>)from.range( 3804,3797 ), to.ek[773] );
    cynw_interpret( (sc_uint<8>)from.range( 3796,3789 ), to.ek[774] );
    cynw_interpret( (sc_uint<8>)from.range( 3788,3781 ), to.ek[775] );
    cynw_interpret( (sc_uint<8>)from.range( 3780,3773 ), to.ek[776] );
    cynw_interpret( (sc_uint<8>)from.range( 3772,3765 ), to.ek[777] );
    cynw_interpret( (sc_uint<8>)from.range( 3764,3757 ), to.ek[778] );
    cynw_interpret( (sc_uint<8>)from.range( 3756,3749 ), to.ek[779] );
    cynw_interpret( (sc_uint<8>)from.range( 3748,3741 ), to.ek[780] );
    cynw_interpret( (sc_uint<8>)from.range( 3740,3733 ), to.ek[781] );
    cynw_interpret( (sc_uint<8>)from.range( 3732,3725 ), to.ek[782] );
    cynw_interpret( (sc_uint<8>)from.range( 3724,3717 ), to.ek[783] );
    cynw_interpret( (sc_uint<8>)from.range( 3716,3709 ), to.ek[784] );
    cynw_interpret( (sc_uint<8>)from.range( 3708,3701 ), to.ek[785] );
    cynw_interpret( (sc_uint<8>)from.range( 3700,3693 ), to.ek[786] );
    cynw_interpret( (sc_uint<8>)from.range( 3692,3685 ), to.ek[787] );
    cynw_interpret( (sc_uint<8>)from.range( 3684,3677 ), to.ek[788] );
    cynw_interpret( (sc_uint<8>)from.range( 3676,3669 ), to.ek[789] );
    cynw_interpret( (sc_uint<8>)from.range( 3668,3661 ), to.ek[790] );
    cynw_interpret( (sc_uint<8>)from.range( 3660,3653 ), to.ek[791] );
    cynw_interpret( (sc_uint<8>)from.range( 3652,3645 ), to.ek[792] );
    cynw_interpret( (sc_uint<8>)from.range( 3644,3637 ), to.ek[793] );
    cynw_interpret( (sc_uint<8>)from.range( 3636,3629 ), to.ek[794] );
    cynw_interpret( (sc_uint<8>)from.range( 3628,3621 ), to.ek[795] );
    cynw_interpret( (sc_uint<8>)from.range( 3620,3613 ), to.ek[796] );
    cynw_interpret( (sc_uint<8>)from.range( 3612,3605 ), to.ek[797] );
    cynw_interpret( (sc_uint<8>)from.range( 3604,3597 ), to.ek[798] );
    cynw_interpret( (sc_uint<8>)from.range( 3596,3589 ), to.ek[799] );
    cynw_interpret( (sc_uint<8>)from.range( 3588,3581 ), to.ek[800] );
    cynw_interpret( (sc_uint<8>)from.range( 3580,3573 ), to.ek[801] );
    cynw_interpret( (sc_uint<8>)from.range( 3572,3565 ), to.ek[802] );
    cynw_interpret( (sc_uint<8>)from.range( 3564,3557 ), to.ek[803] );
    cynw_interpret( (sc_uint<8>)from.range( 3556,3549 ), to.ek[804] );
    cynw_interpret( (sc_uint<8>)from.range( 3548,3541 ), to.ek[805] );
    cynw_interpret( (sc_uint<8>)from.range( 3540,3533 ), to.ek[806] );
    cynw_interpret( (sc_uint<8>)from.range( 3532,3525 ), to.ek[807] );
    cynw_interpret( (sc_uint<8>)from.range( 3524,3517 ), to.ek[808] );
    cynw_interpret( (sc_uint<8>)from.range( 3516,3509 ), to.ek[809] );
    cynw_interpret( (sc_uint<8>)from.range( 3508,3501 ), to.ek[810] );
    cynw_interpret( (sc_uint<8>)from.range( 3500,3493 ), to.ek[811] );
    cynw_interpret( (sc_uint<8>)from.range( 3492,3485 ), to.ek[812] );
    cynw_interpret( (sc_uint<8>)from.range( 3484,3477 ), to.ek[813] );
    cynw_interpret( (sc_uint<8>)from.range( 3476,3469 ), to.ek[814] );
    cynw_interpret( (sc_uint<8>)from.range( 3468,3461 ), to.ek[815] );
    cynw_interpret( (sc_uint<8>)from.range( 3460,3453 ), to.ek[816] );
    cynw_interpret( (sc_uint<8>)from.range( 3452,3445 ), to.ek[817] );
    cynw_interpret( (sc_uint<8>)from.range( 3444,3437 ), to.ek[818] );
    cynw_interpret( (sc_uint<8>)from.range( 3436,3429 ), to.ek[819] );
    cynw_interpret( (sc_uint<8>)from.range( 3428,3421 ), to.ek[820] );
    cynw_interpret( (sc_uint<8>)from.range( 3420,3413 ), to.ek[821] );
    cynw_interpret( (sc_uint<8>)from.range( 3412,3405 ), to.ek[822] );
    cynw_interpret( (sc_uint<8>)from.range( 3404,3397 ), to.ek[823] );
    cynw_interpret( (sc_uint<8>)from.range( 3396,3389 ), to.ek[824] );
    cynw_interpret( (sc_uint<8>)from.range( 3388,3381 ), to.ek[825] );
    cynw_interpret( (sc_uint<8>)from.range( 3380,3373 ), to.ek[826] );
    cynw_interpret( (sc_uint<8>)from.range( 3372,3365 ), to.ek[827] );
    cynw_interpret( (sc_uint<8>)from.range( 3364,3357 ), to.ek[828] );
    cynw_interpret( (sc_uint<8>)from.range( 3356,3349 ), to.ek[829] );
    cynw_interpret( (sc_uint<8>)from.range( 3348,3341 ), to.ek[830] );
    cynw_interpret( (sc_uint<8>)from.range( 3340,3333 ), to.ek[831] );
    cynw_interpret( (sc_uint<8>)from.range( 3332,3325 ), to.ek[832] );
    cynw_interpret( (sc_uint<8>)from.range( 3324,3317 ), to.ek[833] );
    cynw_interpret( (sc_uint<8>)from.range( 3316,3309 ), to.ek[834] );
    cynw_interpret( (sc_uint<8>)from.range( 3308,3301 ), to.ek[835] );
    cynw_interpret( (sc_uint<8>)from.range( 3300,3293 ), to.ek[836] );
    cynw_interpret( (sc_uint<8>)from.range( 3292,3285 ), to.ek[837] );
    cynw_interpret( (sc_uint<8>)from.range( 3284,3277 ), to.ek[838] );
    cynw_interpret( (sc_uint<8>)from.range( 3276,3269 ), to.ek[839] );
    cynw_interpret( (sc_uint<8>)from.range( 3268,3261 ), to.ek[840] );
    cynw_interpret( (sc_uint<8>)from.range( 3260,3253 ), to.ek[841] );
    cynw_interpret( (sc_uint<8>)from.range( 3252,3245 ), to.ek[842] );
    cynw_interpret( (sc_uint<8>)from.range( 3244,3237 ), to.ek[843] );
    cynw_interpret( (sc_uint<8>)from.range( 3236,3229 ), to.ek[844] );
    cynw_interpret( (sc_uint<8>)from.range( 3228,3221 ), to.ek[845] );
    cynw_interpret( (sc_uint<8>)from.range( 3220,3213 ), to.ek[846] );
    cynw_interpret( (sc_uint<8>)from.range( 3212,3205 ), to.ek[847] );
    cynw_interpret( (sc_uint<8>)from.range( 3204,3197 ), to.ek[848] );
    cynw_interpret( (sc_uint<8>)from.range( 3196,3189 ), to.ek[849] );
    cynw_interpret( (sc_uint<8>)from.range( 3188,3181 ), to.ek[850] );
    cynw_interpret( (sc_uint<8>)from.range( 3180,3173 ), to.ek[851] );
    cynw_interpret( (sc_uint<8>)from.range( 3172,3165 ), to.ek[852] );
    cynw_interpret( (sc_uint<8>)from.range( 3164,3157 ), to.ek[853] );
    cynw_interpret( (sc_uint<8>)from.range( 3156,3149 ), to.ek[854] );
    cynw_interpret( (sc_uint<8>)from.range( 3148,3141 ), to.ek[855] );
    cynw_interpret( (sc_uint<8>)from.range( 3140,3133 ), to.ek[856] );
    cynw_interpret( (sc_uint<8>)from.range( 3132,3125 ), to.ek[857] );
    cynw_interpret( (sc_uint<8>)from.range( 3124,3117 ), to.ek[858] );
    cynw_interpret( (sc_uint<8>)from.range( 3116,3109 ), to.ek[859] );
    cynw_interpret( (sc_uint<8>)from.range( 3108,3101 ), to.ek[860] );
    cynw_interpret( (sc_uint<8>)from.range( 3100,3093 ), to.ek[861] );
    cynw_interpret( (sc_uint<8>)from.range( 3092,3085 ), to.ek[862] );
    cynw_interpret( (sc_uint<8>)from.range( 3084,3077 ), to.ek[863] );
    cynw_interpret( (sc_uint<8>)from.range( 3076,3069 ), to.ek[864] );
    cynw_interpret( (sc_uint<8>)from.range( 3068,3061 ), to.ek[865] );
    cynw_interpret( (sc_uint<8>)from.range( 3060,3053 ), to.ek[866] );
    cynw_interpret( (sc_uint<8>)from.range( 3052,3045 ), to.ek[867] );
    cynw_interpret( (sc_uint<8>)from.range( 3044,3037 ), to.ek[868] );
    cynw_interpret( (sc_uint<8>)from.range( 3036,3029 ), to.ek[869] );
    cynw_interpret( (sc_uint<8>)from.range( 3028,3021 ), to.ek[870] );
    cynw_interpret( (sc_uint<8>)from.range( 3020,3013 ), to.ek[871] );
    cynw_interpret( (sc_uint<8>)from.range( 3012,3005 ), to.ek[872] );
    cynw_interpret( (sc_uint<8>)from.range( 3004,2997 ), to.ek[873] );
    cynw_interpret( (sc_uint<8>)from.range( 2996,2989 ), to.ek[874] );
    cynw_interpret( (sc_uint<8>)from.range( 2988,2981 ), to.ek[875] );
    cynw_interpret( (sc_uint<8>)from.range( 2980,2973 ), to.ek[876] );
    cynw_interpret( (sc_uint<8>)from.range( 2972,2965 ), to.ek[877] );
    cynw_interpret( (sc_uint<8>)from.range( 2964,2957 ), to.ek[878] );
    cynw_interpret( (sc_uint<8>)from.range( 2956,2949 ), to.ek[879] );
    cynw_interpret( (sc_uint<8>)from.range( 2948,2941 ), to.ek[880] );
    cynw_interpret( (sc_uint<8>)from.range( 2940,2933 ), to.ek[881] );
    cynw_interpret( (sc_uint<8>)from.range( 2932,2925 ), to.ek[882] );
    cynw_interpret( (sc_uint<8>)from.range( 2924,2917 ), to.ek[883] );
    cynw_interpret( (sc_uint<8>)from.range( 2916,2909 ), to.ek[884] );
    cynw_interpret( (sc_uint<8>)from.range( 2908,2901 ), to.ek[885] );
    cynw_interpret( (sc_uint<8>)from.range( 2900,2893 ), to.ek[886] );
    cynw_interpret( (sc_uint<8>)from.range( 2892,2885 ), to.ek[887] );
    cynw_interpret( (sc_uint<8>)from.range( 2884,2877 ), to.ek[888] );
    cynw_interpret( (sc_uint<8>)from.range( 2876,2869 ), to.ek[889] );
    cynw_interpret( (sc_uint<8>)from.range( 2868,2861 ), to.ek[890] );
    cynw_interpret( (sc_uint<8>)from.range( 2860,2853 ), to.ek[891] );
    cynw_interpret( (sc_uint<8>)from.range( 2852,2845 ), to.ek[892] );
    cynw_interpret( (sc_uint<8>)from.range( 2844,2837 ), to.ek[893] );
    cynw_interpret( (sc_uint<8>)from.range( 2836,2829 ), to.ek[894] );
    cynw_interpret( (sc_uint<8>)from.range( 2828,2821 ), to.ek[895] );
    cynw_interpret( (sc_uint<8>)from.range( 2820,2813 ), to.ek[896] );
    cynw_interpret( (sc_uint<8>)from.range( 2812,2805 ), to.ek[897] );
    cynw_interpret( (sc_uint<8>)from.range( 2804,2797 ), to.ek[898] );
    cynw_interpret( (sc_uint<8>)from.range( 2796,2789 ), to.ek[899] );
    cynw_interpret( (sc_uint<8>)from.range( 2788,2781 ), to.ek[900] );
    cynw_interpret( (sc_uint<8>)from.range( 2780,2773 ), to.ek[901] );
    cynw_interpret( (sc_uint<8>)from.range( 2772,2765 ), to.ek[902] );
    cynw_interpret( (sc_uint<8>)from.range( 2764,2757 ), to.ek[903] );
    cynw_interpret( (sc_uint<8>)from.range( 2756,2749 ), to.ek[904] );
    cynw_interpret( (sc_uint<8>)from.range( 2748,2741 ), to.ek[905] );
    cynw_interpret( (sc_uint<8>)from.range( 2740,2733 ), to.ek[906] );
    cynw_interpret( (sc_uint<8>)from.range( 2732,2725 ), to.ek[907] );
    cynw_interpret( (sc_uint<8>)from.range( 2724,2717 ), to.ek[908] );
    cynw_interpret( (sc_uint<8>)from.range( 2716,2709 ), to.ek[909] );
    cynw_interpret( (sc_uint<8>)from.range( 2708,2701 ), to.ek[910] );
    cynw_interpret( (sc_uint<8>)from.range( 2700,2693 ), to.ek[911] );
    cynw_interpret( (sc_uint<8>)from.range( 2692,2685 ), to.ek[912] );
    cynw_interpret( (sc_uint<8>)from.range( 2684,2677 ), to.ek[913] );
    cynw_interpret( (sc_uint<8>)from.range( 2676,2669 ), to.ek[914] );
    cynw_interpret( (sc_uint<8>)from.range( 2668,2661 ), to.ek[915] );
    cynw_interpret( (sc_uint<8>)from.range( 2660,2653 ), to.ek[916] );
    cynw_interpret( (sc_uint<8>)from.range( 2652,2645 ), to.ek[917] );
    cynw_interpret( (sc_uint<8>)from.range( 2644,2637 ), to.ek[918] );
    cynw_interpret( (sc_uint<8>)from.range( 2636,2629 ), to.ek[919] );
    cynw_interpret( (sc_uint<8>)from.range( 2628,2621 ), to.ek[920] );
    cynw_interpret( (sc_uint<8>)from.range( 2620,2613 ), to.ek[921] );
    cynw_interpret( (sc_uint<8>)from.range( 2612,2605 ), to.ek[922] );
    cynw_interpret( (sc_uint<8>)from.range( 2604,2597 ), to.ek[923] );
    cynw_interpret( (sc_uint<8>)from.range( 2596,2589 ), to.ek[924] );
    cynw_interpret( (sc_uint<8>)from.range( 2588,2581 ), to.ek[925] );
    cynw_interpret( (sc_uint<8>)from.range( 2580,2573 ), to.ek[926] );
    cynw_interpret( (sc_uint<8>)from.range( 2572,2565 ), to.ek[927] );
    cynw_interpret( (sc_uint<8>)from.range( 2564,2557 ), to.ek[928] );
    cynw_interpret( (sc_uint<8>)from.range( 2556,2549 ), to.ek[929] );
    cynw_interpret( (sc_uint<8>)from.range( 2548,2541 ), to.ek[930] );
    cynw_interpret( (sc_uint<8>)from.range( 2540,2533 ), to.ek[931] );
    cynw_interpret( (sc_uint<8>)from.range( 2532,2525 ), to.ek[932] );
    cynw_interpret( (sc_uint<8>)from.range( 2524,2517 ), to.ek[933] );
    cynw_interpret( (sc_uint<8>)from.range( 2516,2509 ), to.ek[934] );
    cynw_interpret( (sc_uint<8>)from.range( 2508,2501 ), to.ek[935] );
    cynw_interpret( (sc_uint<8>)from.range( 2500,2493 ), to.ek[936] );
    cynw_interpret( (sc_uint<8>)from.range( 2492,2485 ), to.ek[937] );
    cynw_interpret( (sc_uint<8>)from.range( 2484,2477 ), to.ek[938] );
    cynw_interpret( (sc_uint<8>)from.range( 2476,2469 ), to.ek[939] );
    cynw_interpret( (sc_uint<8>)from.range( 2468,2461 ), to.ek[940] );
    cynw_interpret( (sc_uint<8>)from.range( 2460,2453 ), to.ek[941] );
    cynw_interpret( (sc_uint<8>)from.range( 2452,2445 ), to.ek[942] );
    cynw_interpret( (sc_uint<8>)from.range( 2444,2437 ), to.ek[943] );
    cynw_interpret( (sc_uint<8>)from.range( 2436,2429 ), to.ek[944] );
    cynw_interpret( (sc_uint<8>)from.range( 2428,2421 ), to.ek[945] );
    cynw_interpret( (sc_uint<8>)from.range( 2420,2413 ), to.ek[946] );
    cynw_interpret( (sc_uint<8>)from.range( 2412,2405 ), to.ek[947] );
    cynw_interpret( (sc_uint<8>)from.range( 2404,2397 ), to.ek[948] );
    cynw_interpret( (sc_uint<8>)from.range( 2396,2389 ), to.ek[949] );
    cynw_interpret( (sc_uint<8>)from.range( 2388,2381 ), to.ek[950] );
    cynw_interpret( (sc_uint<8>)from.range( 2380,2373 ), to.ek[951] );
    cynw_interpret( (sc_uint<8>)from.range( 2372,2365 ), to.ek[952] );
    cynw_interpret( (sc_uint<8>)from.range( 2364,2357 ), to.ek[953] );
    cynw_interpret( (sc_uint<8>)from.range( 2356,2349 ), to.ek[954] );
    cynw_interpret( (sc_uint<8>)from.range( 2348,2341 ), to.ek[955] );
    cynw_interpret( (sc_uint<8>)from.range( 2340,2333 ), to.ek[956] );
    cynw_interpret( (sc_uint<8>)from.range( 2332,2325 ), to.ek[957] );
    cynw_interpret( (sc_uint<8>)from.range( 2324,2317 ), to.ek[958] );
    cynw_interpret( (sc_uint<8>)from.range( 2316,2309 ), to.ek[959] );
    cynw_interpret( (sc_uint<8>)from.range( 2308,2301 ), to.ek[960] );
    cynw_interpret( (sc_uint<8>)from.range( 2300,2293 ), to.ek[961] );
    cynw_interpret( (sc_uint<8>)from.range( 2292,2285 ), to.ek[962] );
    cynw_interpret( (sc_uint<8>)from.range( 2284,2277 ), to.ek[963] );
    cynw_interpret( (sc_uint<8>)from.range( 2276,2269 ), to.ek[964] );
    cynw_interpret( (sc_uint<8>)from.range( 2268,2261 ), to.ek[965] );
    cynw_interpret( (sc_uint<8>)from.range( 2260,2253 ), to.ek[966] );
    cynw_interpret( (sc_uint<8>)from.range( 2252,2245 ), to.ek[967] );
    cynw_interpret( (sc_uint<8>)from.range( 2244,2237 ), to.ek[968] );
    cynw_interpret( (sc_uint<8>)from.range( 2236,2229 ), to.ek[969] );
    cynw_interpret( (sc_uint<8>)from.range( 2228,2221 ), to.ek[970] );
    cynw_interpret( (sc_uint<8>)from.range( 2220,2213 ), to.ek[971] );
    cynw_interpret( (sc_uint<8>)from.range( 2212,2205 ), to.ek[972] );
    cynw_interpret( (sc_uint<8>)from.range( 2204,2197 ), to.ek[973] );
    cynw_interpret( (sc_uint<8>)from.range( 2196,2189 ), to.ek[974] );
    cynw_interpret( (sc_uint<8>)from.range( 2188,2181 ), to.ek[975] );
    cynw_interpret( (sc_uint<8>)from.range( 2180,2173 ), to.ek[976] );
    cynw_interpret( (sc_uint<8>)from.range( 2172,2165 ), to.ek[977] );
    cynw_interpret( (sc_uint<8>)from.range( 2164,2157 ), to.ek[978] );
    cynw_interpret( (sc_uint<8>)from.range( 2156,2149 ), to.ek[979] );
    cynw_interpret( (sc_uint<8>)from.range( 2148,2141 ), to.ek[980] );
    cynw_interpret( (sc_uint<8>)from.range( 2140,2133 ), to.ek[981] );
    cynw_interpret( (sc_uint<8>)from.range( 2132,2125 ), to.ek[982] );
    cynw_interpret( (sc_uint<8>)from.range( 2124,2117 ), to.ek[983] );
    cynw_interpret( (sc_uint<8>)from.range( 2116,2109 ), to.ek[984] );
    cynw_interpret( (sc_uint<8>)from.range( 2108,2101 ), to.ek[985] );
    cynw_interpret( (sc_uint<8>)from.range( 2100,2093 ), to.ek[986] );
    cynw_interpret( (sc_uint<8>)from.range( 2092,2085 ), to.ek[987] );
    cynw_interpret( (sc_uint<8>)from.range( 2084,2077 ), to.ek[988] );
    cynw_interpret( (sc_uint<8>)from.range( 2076,2069 ), to.ek[989] );
    cynw_interpret( (sc_uint<8>)from.range( 2068,2061 ), to.ek[990] );
    cynw_interpret( (sc_uint<8>)from.range( 2060,2053 ), to.ek[991] );
    cynw_interpret( (sc_uint<8>)from.range( 2052,2045 ), to.ek[992] );
    cynw_interpret( (sc_uint<8>)from.range( 2044,2037 ), to.ek[993] );
    cynw_interpret( (sc_uint<8>)from.range( 2036,2029 ), to.ek[994] );
    cynw_interpret( (sc_uint<8>)from.range( 2028,2021 ), to.ek[995] );
    cynw_interpret( (sc_uint<8>)from.range( 2020,2013 ), to.ek[996] );
    cynw_interpret( (sc_uint<8>)from.range( 2012,2005 ), to.ek[997] );
    cynw_interpret( (sc_uint<8>)from.range( 2004,1997 ), to.ek[998] );
    cynw_interpret( (sc_uint<8>)from.range( 1996,1989 ), to.ek[999] );
    cynw_interpret( (sc_uint<8>)from.range( 1988,1981 ), to.ek[1000] );
    cynw_interpret( (sc_uint<8>)from.range( 1980,1973 ), to.ek[1001] );
    cynw_interpret( (sc_uint<8>)from.range( 1972,1965 ), to.ek[1002] );
    cynw_interpret( (sc_uint<8>)from.range( 1964,1957 ), to.ek[1003] );
    cynw_interpret( (sc_uint<8>)from.range( 1956,1949 ), to.ek[1004] );
    cynw_interpret( (sc_uint<8>)from.range( 1948,1941 ), to.ek[1005] );
    cynw_interpret( (sc_uint<8>)from.range( 1940,1933 ), to.ek[1006] );
    cynw_interpret( (sc_uint<8>)from.range( 1932,1925 ), to.ek[1007] );
    cynw_interpret( (sc_uint<8>)from.range( 1924,1917 ), to.ek[1008] );
    cynw_interpret( (sc_uint<8>)from.range( 1916,1909 ), to.ek[1009] );
    cynw_interpret( (sc_uint<8>)from.range( 1908,1901 ), to.ek[1010] );
    cynw_interpret( (sc_uint<8>)from.range( 1900,1893 ), to.ek[1011] );
    cynw_interpret( (sc_uint<8>)from.range( 1892,1885 ), to.ek[1012] );
    cynw_interpret( (sc_uint<8>)from.range( 1884,1877 ), to.ek[1013] );
    cynw_interpret( (sc_uint<8>)from.range( 1876,1869 ), to.ek[1014] );
    cynw_interpret( (sc_uint<8>)from.range( 1868,1861 ), to.ek[1015] );
    cynw_interpret( (sc_uint<8>)from.range( 1860,1853 ), to.ek[1016] );
    cynw_interpret( (sc_uint<8>)from.range( 1852,1845 ), to.ek[1017] );
    cynw_interpret( (sc_uint<8>)from.range( 1844,1837 ), to.ek[1018] );
    cynw_interpret( (sc_uint<8>)from.range( 1836,1829 ), to.ek[1019] );
    cynw_interpret( (sc_uint<8>)from.range( 1828,1821 ), to.ek[1020] );
    cynw_interpret( (sc_uint<8>)from.range( 1820,1813 ), to.ek[1021] );
    cynw_interpret( (sc_uint<8>)from.range( 1812,1805 ), to.ek[1022] );
    cynw_interpret( (sc_uint<8>)from.range( 1804,1797 ), to.ek[1023] );
    cynw_interpret( (sc_uint<8>)from.range( 1796,1789 ), to.ek[1024] );
    cynw_interpret( (sc_uint<8>)from.range( 1788,1781 ), to.ek[1025] );
    cynw_interpret( (sc_uint<8>)from.range( 1780,1773 ), to.ek[1026] );
    cynw_interpret( (sc_uint<8>)from.range( 1772,1765 ), to.ek[1027] );
    cynw_interpret( (sc_uint<8>)from.range( 1764,1757 ), to.ek[1028] );
    cynw_interpret( (sc_uint<8>)from.range( 1756,1749 ), to.ek[1029] );
    cynw_interpret( (sc_uint<8>)from.range( 1748,1741 ), to.ek[1030] );
    cynw_interpret( (sc_uint<8>)from.range( 1740,1733 ), to.ek[1031] );
    cynw_interpret( (sc_uint<8>)from.range( 1732,1725 ), to.ek[1032] );
    cynw_interpret( (sc_uint<8>)from.range( 1724,1717 ), to.ek[1033] );
    cynw_interpret( (sc_uint<8>)from.range( 1716,1709 ), to.ek[1034] );
    cynw_interpret( (sc_uint<8>)from.range( 1708,1701 ), to.ek[1035] );
    cynw_interpret( (sc_uint<8>)from.range( 1700,1693 ), to.ek[1036] );
    cynw_interpret( (sc_uint<8>)from.range( 1692,1685 ), to.ek[1037] );
    cynw_interpret( (sc_uint<8>)from.range( 1684,1677 ), to.ek[1038] );
    cynw_interpret( (sc_uint<8>)from.range( 1676,1669 ), to.ek[1039] );
    cynw_interpret( (sc_uint<8>)from.range( 1668,1661 ), to.ek[1040] );
    cynw_interpret( (sc_uint<8>)from.range( 1660,1653 ), to.ek[1041] );
    cynw_interpret( (sc_uint<8>)from.range( 1652,1645 ), to.ek[1042] );
    cynw_interpret( (sc_uint<8>)from.range( 1644,1637 ), to.ek[1043] );
    cynw_interpret( (sc_uint<8>)from.range( 1636,1629 ), to.ek[1044] );
    cynw_interpret( (sc_uint<8>)from.range( 1628,1621 ), to.ek[1045] );
    cynw_interpret( (sc_uint<8>)from.range( 1620,1613 ), to.ek[1046] );
    cynw_interpret( (sc_uint<8>)from.range( 1612,1605 ), to.ek[1047] );
    cynw_interpret( (sc_uint<8>)from.range( 1604,1597 ), to.ek[1048] );
    cynw_interpret( (sc_uint<8>)from.range( 1596,1589 ), to.ek[1049] );
    cynw_interpret( (sc_uint<8>)from.range( 1588,1581 ), to.ek[1050] );
    cynw_interpret( (sc_uint<8>)from.range( 1580,1573 ), to.ek[1051] );
    cynw_interpret( (sc_uint<8>)from.range( 1572,1565 ), to.ek[1052] );
    cynw_interpret( (sc_uint<8>)from.range( 1564,1557 ), to.ek[1053] );
    cynw_interpret( (sc_uint<8>)from.range( 1556,1549 ), to.ek[1054] );
    cynw_interpret( (sc_uint<8>)from.range( 1548,1541 ), to.ek[1055] );
    cynw_interpret( (sc_uint<8>)from.range( 1540,1533 ), to.ek[1056] );
    cynw_interpret( (sc_uint<8>)from.range( 1532,1525 ), to.ek[1057] );
    cynw_interpret( (sc_uint<8>)from.range( 1524,1517 ), to.ek[1058] );
    cynw_interpret( (sc_uint<8>)from.range( 1516,1509 ), to.ek[1059] );
    cynw_interpret( (sc_uint<8>)from.range( 1508,1501 ), to.ek[1060] );
    cynw_interpret( (sc_uint<8>)from.range( 1500,1493 ), to.ek[1061] );
    cynw_interpret( (sc_uint<8>)from.range( 1492,1485 ), to.ek[1062] );
    cynw_interpret( (sc_uint<8>)from.range( 1484,1477 ), to.ek[1063] );
    cynw_interpret( (sc_uint<8>)from.range( 1476,1469 ), to.ek[1064] );
    cynw_interpret( (sc_uint<8>)from.range( 1468,1461 ), to.ek[1065] );
    cynw_interpret( (sc_uint<8>)from.range( 1460,1453 ), to.ek[1066] );
    cynw_interpret( (sc_uint<8>)from.range( 1452,1445 ), to.ek[1067] );
    cynw_interpret( (sc_uint<8>)from.range( 1444,1437 ), to.ek[1068] );
    cynw_interpret( (sc_uint<8>)from.range( 1436,1429 ), to.ek[1069] );
    cynw_interpret( (sc_uint<8>)from.range( 1428,1421 ), to.ek[1070] );
    cynw_interpret( (sc_uint<8>)from.range( 1420,1413 ), to.ek[1071] );
    cynw_interpret( (sc_uint<8>)from.range( 1412,1405 ), to.ek[1072] );
    cynw_interpret( (sc_uint<8>)from.range( 1404,1397 ), to.ek[1073] );
    cynw_interpret( (sc_uint<8>)from.range( 1396,1389 ), to.ek[1074] );
    cynw_interpret( (sc_uint<8>)from.range( 1388,1381 ), to.ek[1075] );
    cynw_interpret( (sc_uint<8>)from.range( 1380,1373 ), to.ek[1076] );
    cynw_interpret( (sc_uint<8>)from.range( 1372,1365 ), to.ek[1077] );
    cynw_interpret( (sc_uint<8>)from.range( 1364,1357 ), to.ek[1078] );
    cynw_interpret( (sc_uint<8>)from.range( 1356,1349 ), to.ek[1079] );
    cynw_interpret( (sc_uint<8>)from.range( 1348,1341 ), to.ek[1080] );
    cynw_interpret( (sc_uint<8>)from.range( 1340,1333 ), to.ek[1081] );
    cynw_interpret( (sc_uint<8>)from.range( 1332,1325 ), to.ek[1082] );
    cynw_interpret( (sc_uint<8>)from.range( 1324,1317 ), to.ek[1083] );
    cynw_interpret( (sc_uint<8>)from.range( 1316,1309 ), to.ek[1084] );
    cynw_interpret( (sc_uint<8>)from.range( 1308,1301 ), to.ek[1085] );
    cynw_interpret( (sc_uint<8>)from.range( 1300,1293 ), to.ek[1086] );
    cynw_interpret( (sc_uint<8>)from.range( 1292,1285 ), to.ek[1087] );
    cynw_interpret( (sc_uint<8>)from.range( 1284,1277 ), to.ek[1088] );
    cynw_interpret( (sc_uint<8>)from.range( 1276,1269 ), to.ek[1089] );
    cynw_interpret( (sc_uint<8>)from.range( 1268,1261 ), to.ek[1090] );
    cynw_interpret( (sc_uint<8>)from.range( 1260,1253 ), to.ek[1091] );
    cynw_interpret( (sc_uint<8>)from.range( 1252,1245 ), to.ek[1092] );
    cynw_interpret( (sc_uint<8>)from.range( 1244,1237 ), to.ek[1093] );
    cynw_interpret( (sc_uint<8>)from.range( 1236,1229 ), to.ek[1094] );
    cynw_interpret( (sc_uint<8>)from.range( 1228,1221 ), to.ek[1095] );
    cynw_interpret( (sc_uint<8>)from.range( 1220,1213 ), to.ek[1096] );
    cynw_interpret( (sc_uint<8>)from.range( 1212,1205 ), to.ek[1097] );
    cynw_interpret( (sc_uint<8>)from.range( 1204,1197 ), to.ek[1098] );
    cynw_interpret( (sc_uint<8>)from.range( 1196,1189 ), to.ek[1099] );
    cynw_interpret( (sc_uint<8>)from.range( 1188,1181 ), to.ek[1100] );
    cynw_interpret( (sc_uint<8>)from.range( 1180,1173 ), to.ek[1101] );
    cynw_interpret( (sc_uint<8>)from.range( 1172,1165 ), to.ek[1102] );
    cynw_interpret( (sc_uint<8>)from.range( 1164,1157 ), to.ek[1103] );
    cynw_interpret( (sc_uint<8>)from.range( 1156,1149 ), to.ek[1104] );
    cynw_interpret( (sc_uint<8>)from.range( 1148,1141 ), to.ek[1105] );
    cynw_interpret( (sc_uint<8>)from.range( 1140,1133 ), to.ek[1106] );
    cynw_interpret( (sc_uint<8>)from.range( 1132,1125 ), to.ek[1107] );
    cynw_interpret( (sc_uint<8>)from.range( 1124,1117 ), to.ek[1108] );
    cynw_interpret( (sc_uint<8>)from.range( 1116,1109 ), to.ek[1109] );
    cynw_interpret( (sc_uint<8>)from.range( 1108,1101 ), to.ek[1110] );
    cynw_interpret( (sc_uint<8>)from.range( 1100,1093 ), to.ek[1111] );
    cynw_interpret( (sc_uint<8>)from.range( 1092,1085 ), to.ek[1112] );
    cynw_interpret( (sc_uint<8>)from.range( 1084,1077 ), to.ek[1113] );
    cynw_interpret( (sc_uint<8>)from.range( 1076,1069 ), to.ek[1114] );
    cynw_interpret( (sc_uint<8>)from.range( 1068,1061 ), to.ek[1115] );
    cynw_interpret( (sc_uint<8>)from.range( 1060,1053 ), to.ek[1116] );
    cynw_interpret( (sc_uint<8>)from.range( 1052,1045 ), to.ek[1117] );
    cynw_interpret( (sc_uint<8>)from.range( 1044,1037 ), to.ek[1118] );
    cynw_interpret( (sc_uint<8>)from.range( 1036,1029 ), to.ek[1119] );
    cynw_interpret( (sc_uint<8>)from.range( 1028,1021 ), to.ek[1120] );
    cynw_interpret( (sc_uint<8>)from.range( 1020,1013 ), to.ek[1121] );
    cynw_interpret( (sc_uint<8>)from.range( 1012,1005 ), to.ek[1122] );
    cynw_interpret( (sc_uint<8>)from.range( 1004,997 ), to.ek[1123] );
    cynw_interpret( (sc_uint<8>)from.range( 996,989 ), to.ek[1124] );
    cynw_interpret( (sc_uint<8>)from.range( 988,981 ), to.ek[1125] );
    cynw_interpret( (sc_uint<8>)from.range( 980,973 ), to.ek[1126] );
    cynw_interpret( (sc_uint<8>)from.range( 972,965 ), to.ek[1127] );
    cynw_interpret( (sc_uint<8>)from.range( 964,957 ), to.ek[1128] );
    cynw_interpret( (sc_uint<8>)from.range( 956,949 ), to.ek[1129] );
    cynw_interpret( (sc_uint<8>)from.range( 948,941 ), to.ek[1130] );
    cynw_interpret( (sc_uint<8>)from.range( 940,933 ), to.ek[1131] );
    cynw_interpret( (sc_uint<8>)from.range( 932,925 ), to.ek[1132] );
    cynw_interpret( (sc_uint<8>)from.range( 924,917 ), to.ek[1133] );
    cynw_interpret( (sc_uint<8>)from.range( 916,909 ), to.ek[1134] );
    cynw_interpret( (sc_uint<8>)from.range( 908,901 ), to.ek[1135] );
    cynw_interpret( (sc_uint<8>)from.range( 900,893 ), to.ek[1136] );
    cynw_interpret( (sc_uint<8>)from.range( 892,885 ), to.ek[1137] );
    cynw_interpret( (sc_uint<8>)from.range( 884,877 ), to.ek[1138] );
    cynw_interpret( (sc_uint<8>)from.range( 876,869 ), to.ek[1139] );
    cynw_interpret( (sc_uint<8>)from.range( 868,861 ), to.ek[1140] );
    cynw_interpret( (sc_uint<8>)from.range( 860,853 ), to.ek[1141] );
    cynw_interpret( (sc_uint<8>)from.range( 852,845 ), to.ek[1142] );
    cynw_interpret( (sc_uint<8>)from.range( 844,837 ), to.ek[1143] );
    cynw_interpret( (sc_uint<8>)from.range( 836,829 ), to.ek[1144] );
    cynw_interpret( (sc_uint<8>)from.range( 828,821 ), to.ek[1145] );
    cynw_interpret( (sc_uint<8>)from.range( 820,813 ), to.ek[1146] );
    cynw_interpret( (sc_uint<8>)from.range( 812,805 ), to.ek[1147] );
    cynw_interpret( (sc_uint<8>)from.range( 804,797 ), to.ek[1148] );
    cynw_interpret( (sc_uint<8>)from.range( 796,789 ), to.ek[1149] );
    cynw_interpret( (sc_uint<8>)from.range( 788,781 ), to.ek[1150] );
    cynw_interpret( (sc_uint<8>)from.range( 780,773 ), to.ek[1151] );
    cynw_interpret( (sc_uint<8>)from.range( 772,765 ), to.ek[1152] );
    cynw_interpret( (sc_uint<8>)from.range( 764,757 ), to.ek[1153] );
    cynw_interpret( (sc_uint<8>)from.range( 756,749 ), to.ek[1154] );
    cynw_interpret( (sc_uint<8>)from.range( 748,741 ), to.ek[1155] );
    cynw_interpret( (sc_uint<8>)from.range( 740,733 ), to.ek[1156] );
    cynw_interpret( (sc_uint<8>)from.range( 732,725 ), to.ek[1157] );
    cynw_interpret( (sc_uint<8>)from.range( 724,717 ), to.ek[1158] );
    cynw_interpret( (sc_uint<8>)from.range( 716,709 ), to.ek[1159] );
    cynw_interpret( (sc_uint<8>)from.range( 708,701 ), to.ek[1160] );
    cynw_interpret( (sc_uint<8>)from.range( 700,693 ), to.ek[1161] );
    cynw_interpret( (sc_uint<8>)from.range( 692,685 ), to.ek[1162] );
    cynw_interpret( (sc_uint<8>)from.range( 684,677 ), to.ek[1163] );
    cynw_interpret( (sc_uint<8>)from.range( 676,669 ), to.ek[1164] );
    cynw_interpret( (sc_uint<8>)from.range( 668,661 ), to.ek[1165] );
    cynw_interpret( (sc_uint<8>)from.range( 660,653 ), to.ek[1166] );
    cynw_interpret( (sc_uint<8>)from.range( 652,645 ), to.ek[1167] );
    cynw_interpret( (sc_uint<8>)from.range( 644,637 ), to.ek[1168] );
    cynw_interpret( (sc_uint<8>)from.range( 636,629 ), to.ek[1169] );
    cynw_interpret( (sc_uint<8>)from.range( 628,621 ), to.ek[1170] );
    cynw_interpret( (sc_uint<8>)from.range( 620,613 ), to.ek[1171] );
    cynw_interpret( (sc_uint<8>)from.range( 612,605 ), to.ek[1172] );
    cynw_interpret( (sc_uint<8>)from.range( 604,597 ), to.ek[1173] );
    cynw_interpret( (sc_uint<8>)from.range( 596,589 ), to.ek[1174] );
    cynw_interpret( (sc_uint<8>)from.range( 588,581 ), to.ek[1175] );
    cynw_interpret( (sc_uint<8>)from.range( 580,573 ), to.ek[1176] );
    cynw_interpret( (sc_uint<8>)from.range( 572,565 ), to.ek[1177] );
    cynw_interpret( (sc_uint<8>)from.range( 564,557 ), to.ek[1178] );
    cynw_interpret( (sc_uint<8>)from.range( 556,549 ), to.ek[1179] );
    cynw_interpret( (sc_uint<8>)from.range( 548,541 ), to.ek[1180] );
    cynw_interpret( (sc_uint<8>)from.range( 540,533 ), to.ek[1181] );
    cynw_interpret( (sc_uint<8>)from.range( 532,525 ), to.ek[1182] );
    cynw_interpret( (sc_uint<8>)from.range( 524,517 ), to.ek[1183] );
    cynw_interpret( (sc_uint<8>)from.range( 516,509 ), to.sigma[0] );
    cynw_interpret( (sc_uint<8>)from.range( 508,501 ), to.sigma[1] );
    cynw_interpret( (sc_uint<8>)from.range( 500,493 ), to.sigma[2] );
    cynw_interpret( (sc_uint<8>)from.range( 492,485 ), to.sigma[3] );
    cynw_interpret( (sc_uint<8>)from.range( 484,477 ), to.sigma[4] );
    cynw_interpret( (sc_uint<8>)from.range( 476,469 ), to.sigma[5] );
    cynw_interpret( (sc_uint<8>)from.range( 468,461 ), to.sigma[6] );
    cynw_interpret( (sc_uint<8>)from.range( 460,453 ), to.sigma[7] );
    cynw_interpret( (sc_uint<8>)from.range( 452,445 ), to.sigma[8] );
    cynw_interpret( (sc_uint<8>)from.range( 444,437 ), to.sigma[9] );
    cynw_interpret( (sc_uint<8>)from.range( 436,429 ), to.sigma[10] );
    cynw_interpret( (sc_uint<8>)from.range( 428,421 ), to.sigma[11] );
    cynw_interpret( (sc_uint<8>)from.range( 420,413 ), to.sigma[12] );
    cynw_interpret( (sc_uint<8>)from.range( 412,405 ), to.sigma[13] );
    cynw_interpret( (sc_uint<8>)from.range( 404,397 ), to.sigma[14] );
    cynw_interpret( (sc_uint<8>)from.range( 396,389 ), to.sigma[15] );
    cynw_interpret( (sc_uint<8>)from.range( 388,381 ), to.sigma[16] );
    cynw_interpret( (sc_uint<8>)from.range( 380,373 ), to.sigma[17] );
    cynw_interpret( (sc_uint<8>)from.range( 372,365 ), to.sigma[18] );
    cynw_interpret( (sc_uint<8>)from.range( 364,357 ), to.sigma[19] );
    cynw_interpret( (sc_uint<8>)from.range( 356,349 ), to.sigma[20] );
    cynw_interpret( (sc_uint<8>)from.range( 348,341 ), to.sigma[21] );
    cynw_interpret( (sc_uint<8>)from.range( 340,333 ), to.sigma[22] );
    cynw_interpret( (sc_uint<8>)from.range( 332,325 ), to.sigma[23] );
    cynw_interpret( (sc_uint<8>)from.range( 324,317 ), to.sigma[24] );
    cynw_interpret( (sc_uint<8>)from.range( 316,309 ), to.sigma[25] );
    cynw_interpret( (sc_uint<8>)from.range( 308,301 ), to.sigma[26] );
    cynw_interpret( (sc_uint<8>)from.range( 300,293 ), to.sigma[27] );
    cynw_interpret( (sc_uint<8>)from.range( 292,285 ), to.sigma[28] );
    cynw_interpret( (sc_uint<8>)from.range( 284,277 ), to.sigma[29] );
    cynw_interpret( (sc_uint<8>)from.range( 276,269 ), to.sigma[30] );
    cynw_interpret( (sc_uint<8>)from.range( 268,261 ), to.sigma[31] );
    cynw_interpret( (sc_uint<8>)from.range( 260,253 ), to.rho[0] );
    cynw_interpret( (sc_uint<8>)from.range( 252,245 ), to.rho[1] );
    cynw_interpret( (sc_uint<8>)from.range( 244,237 ), to.rho[2] );
    cynw_interpret( (sc_uint<8>)from.range( 236,229 ), to.rho[3] );
    cynw_interpret( (sc_uint<8>)from.range( 228,221 ), to.rho[4] );
    cynw_interpret( (sc_uint<8>)from.range( 220,213 ), to.rho[5] );
    cynw_interpret( (sc_uint<8>)from.range( 212,205 ), to.rho[6] );
    cynw_interpret( (sc_uint<8>)from.range( 204,197 ), to.rho[7] );
    cynw_interpret( (sc_uint<8>)from.range( 196,189 ), to.rho[8] );
    cynw_interpret( (sc_uint<8>)from.range( 188,181 ), to.rho[9] );
    cynw_interpret( (sc_uint<8>)from.range( 180,173 ), to.rho[10] );
    cynw_interpret( (sc_uint<8>)from.range( 172,165 ), to.rho[11] );
    cynw_interpret( (sc_uint<8>)from.range( 164,157 ), to.rho[12] );
    cynw_interpret( (sc_uint<8>)from.range( 156,149 ), to.rho[13] );
    cynw_interpret( (sc_uint<8>)from.range( 148,141 ), to.rho[14] );
    cynw_interpret( (sc_uint<8>)from.range( 140,133 ), to.rho[15] );
    cynw_interpret( (sc_uint<8>)from.range( 132,125 ), to.rho[16] );
    cynw_interpret( (sc_uint<8>)from.range( 124,117 ), to.rho[17] );
    cynw_interpret( (sc_uint<8>)from.range( 116,109 ), to.rho[18] );
    cynw_interpret( (sc_uint<8>)from.range( 108,101 ), to.rho[19] );
    cynw_interpret( (sc_uint<8>)from.range( 100,93 ), to.rho[20] );
    cynw_interpret( (sc_uint<8>)from.range( 92,85 ), to.rho[21] );
    cynw_interpret( (sc_uint<8>)from.range( 84,77 ), to.rho[22] );
    cynw_interpret( (sc_uint<8>)from.range( 76,69 ), to.rho[23] );
    cynw_interpret( (sc_uint<8>)from.range( 68,61 ), to.rho[24] );
    cynw_interpret( (sc_uint<8>)from.range( 60,53 ), to.rho[25] );
    cynw_interpret( (sc_uint<8>)from.range( 52,45 ), to.rho[26] );
    cynw_interpret( (sc_uint<8>)from.range( 44,37 ), to.rho[27] );
    cynw_interpret( (sc_uint<8>)from.range( 36,29 ), to.rho[28] );
    cynw_interpret( (sc_uint<8>)from.range( 28,21 ), to.rho[29] );
    cynw_interpret( (sc_uint<8>)from.range( 20,13 ), to.rho[30] );
    cynw_interpret( (sc_uint<8>)from.range( 12,5 ), to.rho[31] );
    cynw_interpret( (sc_uint<1>)from.range( 4,4 ), to.start_g );
    cynw_interpret( (sc_uint<1>)from.range( 3,3 ), to.start_h );
    cynw_interpret( (sc_uint<1>)from.range( 2,2 ), to.start_prf );
    cynw_interpret( (sc_uint<1>)from.range( 1,1 ), to.start_sntt );
    cynw_interpret( (sc_uint<1>)from.range( 0,0 ), to.start_combined );
}


template <>
struct cynw_sc_wrap< combined_INPUT_DT >
{
    typedef combined_INPUT_DT spec;
    typedef combined_INPUT_DT sc;
};
#endif


