/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:33:53 by achanek           #+#    #+#             */
/*   Updated: 2025/05/19 16:26:48 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"


void	ft_fill_input(t_input *input, int ac, char **av)
{
	input->number_of_philosophers = ft_atoi(av[1]);
	input->time_to_die = ft_atoi(av[2]);
	input->time_to_eat = ft_atoi(av[3]);
	input->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		input->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
		if (!input->number_of_times_each_philosopher_must_eat)
			input->number_of_times_each_philosopher_must_eat = -1;
	}
}

int ft_print_errors(t_input *input, int ac)
{
	int i;

	i = 0;
	if(input->number_of_philosophers == 0 && (i = 1))
		ft_putstr_fd(ERROR_ARG_1, 2);
	if(input->time_to_die == 0 && (i = 1))
		ft_putstr_fd(ERROR_ARG_2, 2);
	if(input->time_to_eat == 0 && (i = 1))
		ft_putstr_fd(ERROR_ARG_3, 2);
	if(input->time_to_sleep == 0 && (i = 1))
		ft_putstr_fd(ERROR_ARG_4, 2);
	if (ac == 6)
	{
		if(input->number_of_times_each_philosopher_must_eat == -1 && (i = 1))
			ft_putstr_fd(ERROR_ARG_5, 2);
	}
	return (i);
}

int ft_check_input(t_input *input,int ac,char **av)
{
	ft_fill_input(input, ac, av);
	if (ft_print_errors(input,ac))
		return (1);
	return (0);
}
