#ifndef SIMPLEXITY_NOISE
#define SIMPLEXITY_NOISE

#include <stdint.h>

double simplex_noise(double x, int64_t seed);

double simplex_fractal(
    long octaves, double lacunarity, double persistence, double x, int64_t seed
);

#endif
