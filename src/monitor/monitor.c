/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:24:28 by achanek           #+#    #+#             */
/*   Updated: 2025/06/17 22:37:54 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	check_eat_counter(t_all_info *all_info)
{
	int	i;
	int	full_philos;

	full_philos = 0;
	i = 0;
	while (i < all_info->input->n_of_ph)
	{
		pthread_mutex_lock(&all_info->eat_is_ok_mutex);
		if (all_info->philos[i].eat_counter >= all_info->input->n_of_t_eat)
			full_philos++;
		pthread_mutex_unlock(&all_info->eat_is_ok_mutex);
		i++;
	}
	if (full_philos == all_info->input->n_of_ph)
	{
		pthread_mutex_lock(&all_info->eat_is_ok_mutex);
		all_info->n_of_e_is_ok = 1;
		pthread_mutex_unlock(&all_info->eat_is_ok_mutex);
		return (1);
	}
	return (0);
}

int	check_time_to_die(t_all_info *all_info)
{
	int			i;
	long long	time_temp;

	i = -1;
	while (++i < all_info->input->n_of_ph)
	{
		pthread_mutex_lock(&all_info->meal_mutex);
		time_temp = ft_get_current_time() - all_info->philos[i].last_meal;
		pthread_mutex_unlock(&all_info->meal_mutex);
		if (time_temp > all_info->input->t_to_die)
		{
			pthread_mutex_lock(&all_info->died_mutex);
			if (!all_info->someone_died)
			{
				all_info->someone_died = 1;
				pthread_mutex_lock(&all_info->print_mutex);
				printf("%lld %d %s\n",
					ft_get_current_time() - all_info->start_time,
					i + 1, "died");
				pthread_mutex_unlock(&all_info->print_mutex);
			}
			return ((pthread_mutex_unlock(&all_info->died_mutex)), 1);
		}
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_all_info	*all_info;

	all_info = (t_all_info *)arg;
	while (1)
	{
		if (all_info->input->n_of_t_eat > 0)
		{
			if (check_eat_counter(all_info))
				return (NULL);
		}
		if (check_time_to_die(all_info))
			return (NULL);
	}
}
