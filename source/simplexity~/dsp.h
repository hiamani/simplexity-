#ifndef SIMPLEXITY_DSP
#define SIMPLEXITY_DSP

#include "ext_mess.h"

// Local includes
#include "structs.h"

void simplexity_perform64(
    t_simplexity *s,
    t_object     *dsp64,
    double      **ins,
    long          numins,
    double      **outs,
    long          numouts,
    long          sampleframes,
    long          flags,
    void         *userparam
);

void simplexity_dsp64(
    t_simplexity *s,
    t_object     *dsp64,
    short        *count,
    double        samplerate,
    long          maxvectorsize,
    long          flags
);

#endif
