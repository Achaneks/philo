#include "../../include/philo.h"

long long ft_get_current_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void ft_sleep(long long time_in_ms)
{
    long long start;

    start = ft_get_current_time();
    while (ft_get_current_time() - start < time_in_ms)
        usleep(1000);
}
