/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:24:56 by achanek           #+#    #+#             */
/*   Updated: 2025/05/16 16:03:06 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>

void	*function_call(void *arg)
{
	return NULL;
}



int main(int ac, char **av)
{
	t_philo	*philo_info;
	pthread_t threads[philo_info->number_of_philosophers];
	int i;

	i = 0;
	if(!(ac == 5 || ac == 6))
		return (1);
	if (ft_check_is_numbers(av))
		return (1);
	ft_fill_struct(philo_info, av, ac);
	if (philo_info->number_of_philosophers <= 0 || philo_info->number_of_philosophers > 200)
		return ( (ft_putstr_fd("Error: invalid number of philosophers\n", 2)), 1);
	while (i < philo_info->number_of_philosophers)
	{
		if (pthread_create(&threads[i], NULL, function_call,NULL));
			return 1;
		i++;
	}
	i = 0;
	while (i < philo_info->number_of_philosophers)
	{
		pthread_join();
	}
}