#ifndef SIMPLEXITY_STRUCTS
#define SIMPLEXITY_STRUCTS

#include "z_dsp.h"

typedef struct _simplexity {
    t_pxobject s_obj;

    // I/O
    double samplerate;

    // Connections
    short frequency_connected;
    short lacunarity_connected;
    short persistence_connected;

    // Simplex
    char   hashfn;
    long   seed;
    double offset;
    long   octaves;

} t_simplexity;

#endif
