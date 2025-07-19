/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:07:00 by achanek           #+#    #+#             */
/*   Updated: 2025/07/17 10:51:50 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	pick_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->all_info->fork[philo->left_fork]);
		ft_print_action(philo->all_info, philo->id, "has taken a fork");
		pthread_mutex_lock(&philo->all_info->fork[philo->right_fork]);
		ft_print_action(philo->all_info, philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->all_info->fork[philo->right_fork]);
		ft_print_action(philo->all_info, philo->id, "has taken a fork");
		pthread_mutex_lock(&philo->all_info->fork[philo->left_fork]);
		ft_print_action(philo->all_info, philo->id, "has taken a fork");
	}
}

static void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->all_info->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->all_info->fork[philo->right_fork]);
}

static void	ft_think(t_philo *philo)
{
	if (philo->all_info->input->n_of_ph % 2)
	{
		ft_print_action(philo->all_info, philo->id, "is thinking");
		if (philo->id % 2)
		{
			if (philo->all_info->input->t_to_eat
				- philo->all_info->input->t_to_sleep >= 0)
				ft_sleep((philo->all_info->input->t_to_eat
						- philo->all_info->input->t_to_sleep + 10),
					philo->all_info);
		}
	}
	else
		ft_print_action(philo->all_info, philo->id, "is thinking");
}

static void	routine_helper(t_all_info *all_info, t_philo *philo)
{
	if (philo->all_info->input->n_of_ph == 1)
	{
		ft_print_action(philo->all_info, philo->id, "has taken a fork");
		usleep((philo->all_info->input->t_to_die + 3) * 1000);
		return ;
	}
	pick_forks(philo);
	update_last_meal(philo);
	ft_print_action(all_info, philo->id, "is eating");
	ft_sleep(all_info->input->t_to_eat, all_info);
	release_forks(philo);
	pthread_mutex_lock(&all_info->eat_is_ok_mutex);
	philo->eat_counter += 1;
	pthread_mutex_unlock(&all_info->eat_is_ok_mutex);
	ft_print_action(all_info, philo->id, "is sleeping");
	ft_sleep(all_info->input->t_to_sleep, all_info);
	ft_think(philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&philo->all_info->died_mutex);
		if (philo->all_info->someone_died)
		{
			pthread_mutex_unlock(&philo->all_info->died_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->all_info->died_mutex);
		pthread_mutex_lock(&philo->all_info->eat_is_ok_mutex);
		if (philo->all_info->n_of_e_is_ok)
		{
			pthread_mutex_unlock(&philo->all_info->eat_is_ok_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->all_info->eat_is_ok_mutex);
		routine_helper(philo->all_info, philo);
	}
	return (NULL);
}
