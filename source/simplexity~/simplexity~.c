#include "ext_obex.h"
#include "ext_obex_util.h"
#include "ext_proto.h"

// Local imports
#include "dsp.h"
#include "handlers.h"
#include "structs.h"

void *simplexity_new(t_symbol *s, long argc, t_atom *argv);
void  simplexity_free(t_simplexity *f);

static t_class *simplexity_class = NULL;

void ext_main(void *r) {
    t_class *c = class_new(
        "simplexity~",
        (method)simplexity_new,
        (method)simplexity_free,
        (long)sizeof(t_simplexity),
        0L,
        A_GIMME,
        0
    );

    class_addmethod(c, (method)simplexity_assist, "assist", A_CANT, 0);
    class_addmethod(c, (method)simplexity_dsp64, "dsp64", A_CANT, 0);

    CLASS_ATTR_LONG(c, "octaves", 0, t_simplexity, octaves);
    CLASS_ATTR_FILTER_CLIP(c, "octaves", 1, 16);
    CLASS_ATTR_LABEL(c, "octaves", 0, "Octaves");

    CLASS_ATTR_LONG(c, "seed", 0, t_simplexity, seed);
    CLASS_ATTR_LABEL(c, "seed", 0, "Seed");

    class_dspinit(c);
    class_register(CLASS_BOX, c);
    simplexity_class = c;
}

void *simplexity_new(t_symbol *sym, long argc, t_atom *argv) {
    t_simplexity *s = (t_simplexity *)object_alloc(simplexity_class);

    if (s) {
        dsp_setup((t_pxobject *)s, 3);
        outlet_new(s, "signal");

        s->samplerate = 48000.0;

        s->frequency_connected   = 0;
        s->lacunarity_connected  = 0;
        s->persistence_connected = 0;

        s->seed    = 0;
        s->offset  = 0;
        s->octaves = 1;

        attr_args_process(s, argc, argv);
    }

    return s;
}

void simplexity_free(t_simplexity *s) {
    dsp_free((t_pxobject *)s);
}
