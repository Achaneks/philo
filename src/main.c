/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:24:56 by achanek           #+#    #+#             */
/*   Updated: 2025/05/26 16:00:22 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"



int	main(int ac, char **av)
{
	t_all_info *all_info;


	all_info = malloc(sizeof(t_all_info));
	all_info->input = malloc(sizeof(t_input));
	all_info->start_time = ft_get_current_time();
	if (!(ac == 5 || ac == 6))
		return ((ft_putstr_fd(ERROR1, 2)), 1);
	if (ft_check_input(all_info->input, ac, av))
		return (1);
	if(fill_philo(all_info))
		return 1;
	if(ft_init_all_mutex(all_info))
		return 1;
	if (create_threads(all_info))
		return 1;
}