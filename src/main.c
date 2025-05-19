/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:24:56 by achanek           #+#    #+#             */
/*   Updated: 2025/05/19 11:06:30 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
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
	if(input->number_of_times_each_philosopher_must_eat == -1 && (i = 1))
		ft_putstr_fd(ERROR_ARG_5, 2);
	return (i);
}

int ft_check_input(t_input *input,int ac,char **av)
{
	ft_fill_input(input, ac, av);
	if (ft_print_errors(input,ac))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_input *input;

	if (!(ac == 5 || ac == 6))
		return ((ft_putstr_fd(ERROR1,2)), 1);
	if (ft_check_input(input, ac, av))
		return (1);
}