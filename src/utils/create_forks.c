/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:48:17 by achanek           #+#    #+#             */
/*   Updated: 2025/06/17 10:42:01 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_init_all_mutex(t_all_info *all_info)
{
	int	i;

	i = 0;
	all_info->fork = malloc(sizeof(pthread_mutex_t)
			* all_info->input->n_of_ph);
	if (!all_info->fork)
		return (1);
	while (i < all_info->input->n_of_ph)
	{
		if (pthread_mutex_init(&all_info->fork[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&all_info->print_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&all_info->died_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&all_info->meal_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&all_info->eat_is_ok_mutex, NULL))
		return (1);
	return (0);
}

void	ft_destroy_mutexes(t_all_info *info)
{
	int	i;

	i = 0;
	while (i < info->input->n_of_ph)
	{
		pthread_mutex_destroy(&info->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->died_mutex);
	pthread_mutex_destroy(&info->meal_mutex);
	pthread_mutex_destroy(&info->eat_is_ok_mutex);
	free(info->fork);
}
