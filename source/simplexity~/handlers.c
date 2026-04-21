// Local imports
#include "structs.h"

void simplexity_assist(t_simplexity *s, void *b, long m, long a, char *str) {
    if (m == 1) {
        sprintf(str, "I am inlet %ld", a);
    } else {
        sprintf(str, "I am outlet %ld", a);
    }
}
