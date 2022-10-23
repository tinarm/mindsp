#ifndef LIB_DSP_HEADER_H
#define LIB_DSP_HEADER_H

#include <stddef.h>

/**
 * @brief Calculate the arithmetic mean of a signal
 *
 * @param signal Signal array
 * @param len Length of the array
 * @return Mean value of the signal
 */
float dsp_stat_get_mean(const float signal[], size_t len);

/**
 * @brief Calculate the standard deviation of a signal
 *
 * @param[in] signal Signal array
 * @param len Length of the array
 * @param mean Mean value of the signal
 * @return Standard deviation of the signal
 */
float dsp_stat_get_stddev(const float signal[], size_t len, float mean);


#endif
