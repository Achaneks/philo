/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:33:53 by achanek           #+#    #+#             */
/*   Updated: 2025/07/12 15:55:46 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_check_errors(t_input *input, int ac)
{
	if (input->n_of_ph == 0)
		return (ft_putstr_fd(ERROR_ARG_1, 2), 1);
	if (input->t_to_die == 0)
		return (ft_putstr_fd(ERROR_ARG_2, 2), 1);
	if (input->t_to_eat == 0)
		return (ft_putstr_fd(ERROR_ARG_3, 2), 1);
	if (input->t_to_sleep == 0)
		return (ft_putstr_fd(ERROR_ARG_4, 2), 1);
	if (ac == 6)
	{
		if (input->n_of_t_eat == 0)
			return (ft_putstr_fd(ERROR_ARG_5, 2), 1);
	}
	return (0);
}

int	ft_fill_input(t_input *input, int ac, char **av)
{
	input->n_of_ph = ft_atoi(av[1]);
	input->t_to_die = ft_atoi(av[2]);
	input->t_to_eat = ft_atoi(av[3]);
	input->t_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		input->n_of_t_eat = ft_atoi(av[5]);
	}
	else
		input->n_of_t_eat = 0;
	if (ft_check_errors(input, ac))
		return (1);
	return (0);
}
