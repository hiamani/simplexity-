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
    long   seed;
    double offset;
    long   octaves;

} t_simplexity;

#endif
