/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:33:53 by achanek           #+#    #+#             */
/*   Updated: 2025/05/19 10:39:34 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"



void	ft_fill_input(t_input *input, char **av, int ac)
{
	input->number_of_philosophers = ft_atoi(av[1]);
	input->time_to_die = ft_atoi(av[2]);
	input->time_to_eat = ft_atoi(av[3]);
	input->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		input->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		input->number_of_times_each_philosopher_must_eat = -1;

}
