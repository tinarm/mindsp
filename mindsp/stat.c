#include <math.h>
#include <stdio.h>
#include <stdint.h>

#include "mindsp.h"


float mindsp_stat_get_mean(const float signal[], size_t len)
{
    float mean = 0.0f;

    if (!signal || len == 0U) {
        return mean;
    }

    for (size_t i = 0U; i < len; i++) {
        mean += signal[i];
    }

    return mean / len;
}


float mindsp_stat_get_stddev(const float signal[], size_t len, float mean)
{
    float variance = 0.0f;

    if (!signal || len < 2U) {
        return variance;
    }

    for (size_t i = 0U; i < len; i++) {
        float deviation = signal[i] - mean;
        variance += (deviation * deviation);
    }

    variance /= (len - 1U);

    return sqrtf(variance);
}


/**
 * @brief Calculate the signal-to-noise ratio of the signal
 *
 * @param[in] signal Signal array
 * @param[in] len Length of the array
 * @return SNR of the signal
 */
float mindsp_stat_get_snr(const float signal[], size_t len)
{
    float snr = 0.0f;

    float mean   = mindsp_stat_get_mean(signal, len);
    float stddev = mindsp_stat_get_stddev(signal, len, mean);

    if (stddev > 1e-6f) {
        snr = mean / stddev;
    }

    return snr;
}


/**
 * @brief Calculate mean and standard deviation using running statistics
 *
 * @param[in, out] run_data Running statistics data
 * @param[in] signal Signal array
 * @param[in] len Length of the array
 */
void mindsp_stat_run_stats(mindsp_run_stats_data_t *run_data, const float signal[], size_t len)
{
    if (!run_data || !signal) {
        return;
    }

    for (size_t i = 0U; i < len; i++) {
        // Update running state.
        run_data->samples_count++;
        run_data->samples_sum         += signal[i];
        run_data->samples_squared_sum += (signal[i] * signal[i]);

        run_data->mean = run_data->samples_sum / run_data->samples_count;

        if (run_data->samples_count == 1U) {
            run_data->stddev = 0.0f;
        } else {
            float squared_mean =
                (run_data->samples_sum * run_data->samples_sum) /
                run_data->samples_count;

            run_data->stddev =
                sqrtf(
                    (run_data->samples_squared_sum - squared_mean) /
                    (run_data->samples_count - 1U)
                );
        }
    }
}
