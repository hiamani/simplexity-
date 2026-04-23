// Local imports
#include "structs.h"

void simplexity_assist(t_simplexity *s, void *b, long m, long a, char *str) {
    if (m == 1) {
        switch (a) {
        case 0:
            sprintf(str, "(signal) frequency");
            break;
        case 1:
            sprintf(str, "(signal) lacunarity");
            break;
        case 2:
            sprintf(str, "(signal) persistence");
            break;
        }
    } else {
        sprintf(str, "(signal) output");
    }
}
