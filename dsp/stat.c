#include <math.h>
#include <stdio.h>
#include <stdint.h>

#include "dsp.h"


float dsp_stat_get_mean(const float signal[], size_t len)
{
    float mean = 0.0f;

    for (size_t i = 0; i < len; i++) {
        mean += signal[i];
    }

    return mean / len;
}


float dsp_stat_get_stddev(const float signal[], size_t len, float mean)
{
    float variance = 0.0f;

    for (size_t i = 0; i < len; i++) {
        variance = variance + pow((signal[i] - mean), 2);
    }

    variance = variance / (len - 1);

    return sqrtf(variance);
}
