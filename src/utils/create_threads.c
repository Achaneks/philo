/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:53:28 by achanek           #+#    #+#             */
/*   Updated: 2025/06/20 10:23:34 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	fill_philo(t_all_info *all_info)
{
	int	i;

	all_info->philos = malloc(sizeof(t_philo) * (all_info->input->n_of_ph));
	if (!all_info->philos)
		return (1);
	all_info->monitor_thread = 0;
	all_info->someone_died = 0;
	all_info->n_of_e_is_ok = 0;
	i = 0;
	while (i < all_info->input->n_of_ph)
	{
		all_info->philos[i].id = i + 1;
		all_info->philos[i].left_fork = i;
		all_info->philos[i].right_fork = (i + 1) % all_info->input->n_of_ph;
		all_info->philos[i].eat_counter = 0;
		all_info->philos[i].thread = 0;
		all_info->philos[i].last_meal = all_info->start_time;
		all_info->philos[i].all_info = all_info;
		i++;
	}
	return (0);
}

void	ft_join_threads(t_all_info *all_info)
{
	int	i;
	int	k;

	i = 0;
	k = all_info->input->n_of_ph;
	while (i < k)
	{
		pthread_join(all_info->philos[i].thread, NULL);
		i++;
	}
	pthread_join(all_info->monitor_thread, NULL);
}

int	create_threads(t_all_info *all_info)
{
	int	i;

	i = 0;
	while (i < all_info->input->n_of_ph)
	{
		if (pthread_create(&all_info->philos[i].thread, NULL, routine,
				(void *)(all_info->philos + i)))
			return (1);
		i++;
	}
	if (pthread_create(&all_info->monitor_thread, NULL, monitor, all_info))
		return (1);
	ft_join_threads(all_info);
	return (0);
}
