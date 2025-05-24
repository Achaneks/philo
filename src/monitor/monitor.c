/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:24:28 by achanek           #+#    #+#             */
/*   Updated: 2025/05/24 17:48:50 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void *monitor_routine(void *arg)
{
    int i;
    long long time_since_meal;
    t_all_info *info = (t_all_info *)arg;

    while (!info->someone_died)
    {
        i = -1;
        while (++i < info->input->number_of_philosophers)
        {
            pthread_mutex_lock(&info->meal_mutex);
            time_since_meal = get_current_time() - info->philos[i].last_meal;
            pthread_mutex_unlock(&info->meal_mutex);
    
            if (time_since_meal > info->input->time_to_die)
            {
                log_death(info, i + 1);
                info->someone_died = 1;
                return NULL;
            }
        }
        usleep(1000);
    }
    return NULL;
}



