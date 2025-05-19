/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:24:56 by achanek           #+#    #+#             */
/*   Updated: 2025/05/19 17:15:50 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	fill_philo(t_all_info *all_info)
{
	int i;

	all_info->philos = malloc(sizeof(all_info->philos)
			* (all_info->input->number_of_philosophers));
	i = 0;
	while (i < all_info->input->number_of_philosophers)
	{
		all_info->philos[i].id = i + 1;
		all_info->philos[i].left_fork = i + 1;
		all_info->philos[i].rigth_fork = i + 2;
		all_info->philos[i].number_of_eat = 0;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_all_info *all_info;

	all_info = malloc(sizeof(t_all_info));
	all_info->input = malloc(sizeof(t_input));
	if (!(ac == 5 || ac == 6))
		return ((ft_putstr_fd(ERROR1, 2)), 1);
	if (ft_check_input(all_info->input, ac, av))
		return (1);
	fill_philo(all_info);
}