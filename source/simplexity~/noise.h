#ifndef SIMPLEXITY_NOISE
#define SIMPLEXITY_NOISE

#include <stdint.h>

double simplex_noise_pearson(double x, int64_t seed);

double simplex_fractal_pearson(
    long octaves, double lacunarity, double persistence, double x, int64_t seed
);

double simplex_noise_moremur(double x, int64_t seed);

double simplex_fractal_moremur(
    long octaves, double lacunarity, double persistence, double x, int64_t seed
);

#endif
