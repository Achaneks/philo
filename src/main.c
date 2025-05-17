/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:24:56 by achanek           #+#    #+#             */
/*   Updated: 2025/05/17 17:13:04 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int ft_check_input(char **input)
{
	int i;
	int j;

	i = 1;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if(!ft_isdigit(input[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_input *input;

	if (ft_check_input(av))
		return (1);
	ft_fill_struct(input, av, ac);
	// printf("fist is : %d\nsecand %d\nterth : %d\nforth : %d\nfifth : %d\n",input->number_of_philosophers,input->number_of_times_each_philosopher_must_eat,input->time_to_die,input->time_to_eat,input->time_to_sleep);
}