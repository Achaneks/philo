/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:24:28 by achanek           #+#    #+#             */
/*   Updated: 2025/05/26 16:05:12 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	log_death(t_all_info *info, int philo_id)
{
	long long	timestamp;

	timestamp = ft_get_current_time() - info->start_time;
	pthread_mutex_lock(&info->print_mutex);
	if (!info->someone_died)
	{
		printf("%lld %d died\n", timestamp, philo_id);
		fflush(stdout);
	}
	pthread_mutex_unlock(&info->print_mutex);
}

void	*monitor_routine(void *arg)
{
	t_all_info	*info;
	long long	time_since_meal;

	info = (t_all_info *)arg;
	while (1)
	{
		for (int i = 0; i < info->input->number_of_philosophers; i++)
		{
			pthread_mutex_lock(&info->meal_mutex);
			time_since_meal = ft_get_current_time() - info->philos[i].last_meal;
			pthread_mutex_unlock(&info->meal_mutex);
			if (time_since_meal > info->input->time_to_die)
			{
				log_death(info, i + 1);
				pthread_mutex_lock(&info->death_mutex);
				info->someone_died = 1;
				pthread_mutex_unlock(&info->death_mutex);
				return (NULL);
			}
		}
		usleep(1000);
	}
}
