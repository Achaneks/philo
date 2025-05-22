/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:07:00 by achanek           #+#    #+#             */
/*   Updated: 2025/05/19 17:07:27 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void *routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	printf("id : %d\n",philo->id);
	return (NULL);
}