#include "../../include/philo.h"

int ft_init_forks(t_all_info *all_info)
{
    int i;

    i = 0;
    all_info->fork = malloc(sizeof(pthread_mutex_t)*all_info->input->number_of_philosophers);
    if (!all_info->fork)
        return (1);
    while (i < all_info->input->number_of_philosophers)
    {
        if(pthread_mutex_init(&all_info->fork[i], NULL))
            return (1);
        i++;
    }
    pthread_mutex_init(&all_info->meal_mutex, NULL);
    pthread_mutex_init(&all_info->print_mutex, NULL);
    return (0);
}
