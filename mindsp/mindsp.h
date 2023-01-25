#ifndef MIN_DSP_HEADER_H
#define MIN_DSP_HEADER_H

#include <stddef.h>

typedef struct
{
	// Running state
	size_t samples_count;
	float  samples_sum;
	float  samples_squared_sum;

	// Mean and standard deviation calculated for each run
	float mean;
	float stddev;
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
 * @brief Calculate mean and standard deviation using running statistics
 *
 * @param[in, out] run_data Running statistics data
 * @param[in] signal Signal array
 * @param[in] len Length of the array
 */
void mindsp_stat_run_stats(mindsp_run_stats_data_t *run_data, const float signal[], size_t len);


#endif
