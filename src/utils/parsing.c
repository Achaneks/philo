/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:33:53 by achanek           #+#    #+#             */
/*   Updated: 2025/05/16 09:35:49 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_check_is_numbers(char **str)
{
	int i;
	int j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!(str[i][j] <= '9' && str[i][j] >= '0'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_fill_struct(t_philo *philo_info, char **av, int ac)
{
	philo_info->number_of_philosophers = ft_atoi(av[1]);
	philo_info->time_to_die = ft_atoi(av[2]);
	philo_info->time_to_eat = ft_atoi(av[3]);
	philo_info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo_info->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
}
