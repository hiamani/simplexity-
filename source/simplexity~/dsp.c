#include "ext_mess.h"
#include "ext_obex.h"
#include "ext_post.h"
#include "ext_proto.h"

// Local includes
#include "noise.h"
#include "structs.h"
#include <stdint.h>

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
) {
    double  sr      = s->samplerate;
    int64_t seed    = (int64_t)s->seed;
    double  offset  = s->offset;
    char    hashfn  = s->hashfn;
    long    octaves = s->octaves;

    // DSP I/O
    double *frequency   = ins[0];
    double *lacunarity  = ins[1];
    double *persistence = ins[2];

    double *out = outs[0];

    for (int i = 0; i < sampleframes; i++) {
        double fr = s->frequency_connected ? frequency[i] : 1.0;
        double la = s->lacunarity_connected ? lacunarity[i] : 2.0;
        double pe = s->persistence_connected ? persistence[i] : 0.5;

        offset += fr / sr;

        if (hashfn) {
            out[i] = simplex_fractal_moremur(octaves, la, pe, offset, seed);
        } else {
            out[i] = simplex_fractal_pearson(octaves, la, pe, offset, seed);
        }
    }

    s->offset = offset;
}

void simplexity_dsp64(
    t_simplexity *s,
    t_object     *dsp64,
    short        *count,
    double        samplerate,
    long          maxvectorsize,
    long          flags
) {
    s->frequency_connected   = count[0];
    s->lacunarity_connected  = count[1];
    s->persistence_connected = count[2];

    s->samplerate = samplerate;

    object_method(dsp64, gensym("dsp_add64"), s, simplexity_perform64, 0, NULL);
}
