#include <stdio.h>

#include "mindsp.h"

#define ALEN(a) (sizeof(a) / sizeof((a)[0]))

int main(void)
{
    printf("Hello, Test!\n");

    const float signal[] = {10.0f, 12.0f, 14.0f, 16.0f, 18.0f, 20.0f};

    float mean = mindsp_stat_get_mean(signal, ALEN(signal));
    
    printf("Signal mean: %.2f\n", mean);
    printf("Signal stddev: %.2f\n", mindsp_stat_get_stddev(signal, ALEN(signal), mean));

    return 0;
}

