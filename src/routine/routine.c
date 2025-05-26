/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:07:00 by achanek           #+#    #+#             */
/*   Updated: 2025/05/26 16:02:41 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
void	*routine(void *arg)
{
	t_philo		*philo;
	t_all_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	while (1)
	{
		pthread_mutex_lock(&info->death_mutex);
		if (info->someone_died)
		{
			pthread_mutex_unlock(&info->death_mutex);
			break;
		}
		pthread_mutex_unlock(&info->death_mutex);
		ft_log_action(info, philo->id, "is thinking");
		pick_forks(philo);
		update_last_meal(philo);
		ft_log_action(info, philo->id, "is eating");
		ft_sleep(info->input->time_to_eat);
		release_forks(philo);
		ft_log_action(info, philo->id, "is sleeping");
		ft_sleep(info->input->time_to_sleep);
	}
	return (NULL);
}

void	ft_log_action(t_all_info *info, int id, char *msg)
{
	pthread_mutex_lock(&info->print_mutex);
	if (!info->someone_died)
		printf("%lld %d %s\n", ft_get_current_time() - info->start_time, id,msg);
	pthread_mutex_unlock(&info->print_mutex);
}
void	pick_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->info->fork[philo->left_fork]);
		pthread_mutex_lock(&philo->info->fork[philo->right_fork]);
		ft_log_action(philo->info, philo->id, "has taken a fork");
	}
	else
	{
		usleep(100);
		pthread_mutex_lock(&philo->info->fork[philo->right_fork]);
		pthread_mutex_lock(&philo->info->fork[philo->left_fork]);
		ft_log_action(philo->info, philo->id, "has taken a fork");
	}
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->fork[philo->right_fork]);
	pthread_mutex_unlock(&philo->info->fork[philo->left_fork]);
}

void	update_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->meal_mutex);
	philo->last_meal = ft_get_current_time();
	printf("philo %d is update last mael\n",philo->id);
	pthread_mutex_unlock(&philo->info->meal_mutex);
}
