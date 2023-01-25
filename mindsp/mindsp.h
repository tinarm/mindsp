#ifndef MIN_DSP_HEADER_H
#define MIN_DSP_HEADER_H

#include <stddef.h>
#include <stdint.h>


typedef struct {
    float mean;
    float stddev;
} mindsp_basic_stats_t;


typedef struct {
    // Running state
    size_t samples_count;
    float  samples_sum;
    float  samples_squared_sum;

    // Basic statistics calculated for each run
    mindsp_basic_stats_t stats;
} mindsp_run_stats_data_t;


/**
 * @brief Calculate the arithmetic mean of a signal
 *
 * @param[in] signal Signal array
 * @param[in] len Length of the array
 * @return Mean value of the signal
 */
float mindsp_stat_get_mean(const float signal[], size_t len);


/**
 * @brief Calculate the standard deviation of a signal
 *
 * @param[in] signal Signal array
 * @param[in] len Length of the array
 * @param[in] mean Mean value of the signal
 * @return Standard deviation of the signal
 */
float mindsp_stat_get_stddev(const float signal[], size_t len, float mean);


/**
 * @brief Calculate the signal-to-noise ratio of the signal
 *
 * @param[in] signal Signal array
 * @param[in] len Length of the array
 * @return SNR of the signal
 */
float mindsp_stat_get_snr(const float signal[], size_t len);


/**
 * @brief Calculate basic stats using running statistics
 *
 * @param[in, out] run_data Running statistics data
 * @param[in] signal Signal array
 * @param[in] len Length of the array
 */
void mindsp_stat_run_stats(mindsp_run_stats_data_t *run_data, const float signal[], size_t len);


/**
 * @brief Fast calculation of basic stats for an 8-bit dataset.
 *
 * This is suitable for large datasets since the algorithm uses a histogram
 * internally to avoid a large number of multiplications.
 *
 * @param[in] signal Signal array
 * @param[in] len Length of the array
 * @return Basic statistics
 */
mindsp_basic_stats_t mindsp_stat_get_basic_stats(const uint8_t signal[], size_t len);


#endif
