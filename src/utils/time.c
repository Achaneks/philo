/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:13:38 by achanek           #+#    #+#             */
/*   Updated: 2025/06/17 10:39:25 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

long long	ft_get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_sleep(long long time_in_ms, t_all_info *all_info)
{
	long long	start;

	start = ft_get_current_time();
	while (ft_get_current_time() - start < time_in_ms)
	{
		pthread_mutex_lock(&all_info->died_mutex);
		if (all_info->someone_died)
		{
			pthread_mutex_unlock(&all_info->died_mutex);
			break ;
		}
		pthread_mutex_unlock(&all_info->died_mutex);
		usleep(1000);
	}
}
