/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:53:28 by achanek           #+#    #+#             */
/*   Updated: 2025/05/19 17:07:23 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"


int create_threads(t_all_info *all_info)
{
	int i;

	i = 0;
	while (i <= all_info->input->number_of_philosophers)
	{
		if(pthread_create(&all_info->philos[i].thread,NULL,routine,(void *)all_info))
			return (1);
		i++;
	}
}