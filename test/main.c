#include <stdio.h>

#include "mindsp.h"

#define ALEN(a) (sizeof(a) / sizeof((a)[0]))

void test_run_stats(const float signal_1[], size_t len)
{
    mindsp_run_stats_data_t run_stats_data = {0};
    const float             signal_2[]     = {1.0f, 2.0f, 1.0f, 3.0f, 1.0f};

    mindsp_stat_run_stats(&run_stats_data, signal_1, len);

    printf("\nRunning state: count=%zu, sum=%.2f, squared_sum=%.2f\n",
        run_stats_data.samples_count, run_stats_data.samples_sum, run_stats_data.samples_squared_sum);
    printf("\tmean: %.2f, stddev: %.2f\n", run_stats_data.mean, run_stats_data.stddev);

    mindsp_stat_run_stats(&run_stats_data, signal_2, ALEN(signal_2));

    printf("Updated running state: count=%zu, sum=%.2f, squared_sum=%.2f\n",
        run_stats_data.samples_count, run_stats_data.samples_sum, run_stats_data.samples_squared_sum);
    printf("\tmean: %.2f, stddev: %.2f\n", run_stats_data.mean, run_stats_data.stddev);
}

int main(void)
{
    printf("Hello, Test!\n\n");

    const float signal[] = {10.0f, 12.0f, 14.0f, 16.0f, 18.0f, 20.0f};

    float mean = mindsp_stat_get_mean(signal, ALEN(signal));
    
    printf("Signal mean: %.2f\n", mean);
    printf("Signal stddev: %.2f\n", mindsp_stat_get_stddev(signal, ALEN(signal), mean));
    printf("Signal SNR: %.2f\n", mindsp_stat_get_snr(signal, ALEN(signal)));

    test_run_stats(signal, ALEN(signal));

    return 0;
}

