/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:24:56 by achanek           #+#    #+#             */
/*   Updated: 2025/06/17 21:55:57 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static	int	main_helper(t_all_info *all_info)
{
	if (fill_philo(all_info))
		return (1);
	if (ft_init_all_mutex(all_info))
		return (1);
	if (create_threads(all_info))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_all_info	*all_info;

	all_info = malloc(sizeof(t_all_info));
	all_info->input = malloc(sizeof(t_input));
	all_info->start_time = ft_get_current_time();
	if (!all_info || !all_info->input)
		return (1);
	if (!(ac == 5 || ac == 6))
		return ((ft_putstr_fd(ERROR1, 2)), free(all_info->input),
			free(all_info), 1);
	if (ft_fill_input(all_info->input, ac, av))
		return (free(all_info->input), free(all_info), 1);
	if (all_info->input->n_of_ph == 1)
	{
		ft_print_action(all_info, 1, "has taken a fork");
		usleep(1000 * all_info->input->t_to_die);
		ft_print_action(all_info, 1, "died");
		return (free(all_info->input), free(all_info), 0);
	}
	if (main_helper(all_info))
		return (1);
	free_all(all_info);
	return (0);
}
