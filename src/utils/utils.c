/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:26:23 by achanek           #+#    #+#             */
/*   Updated: 2025/07/12 18:21:27 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

long	ft_atoi(char *str)
{
	unsigned long	n;
	int				i;

	i = 0;
	n = 0;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9')))
	{
		n *= 10;
		n += str[i] - '0';
		if (n > LONG_MAX)
			return (0);
		i++;
	}
	if (str[i] != '\0' && ((str[i] < '0' || str[i] > '9')))
		return (0);
	return ((long)n);
}

void	update_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->all_info->meal_mutex);
	philo->last_meal = ft_get_current_time();
	pthread_mutex_unlock(&philo->all_info->meal_mutex);
}

void	ft_print_action(t_all_info *all_info, int id, char *msg)
{
	pthread_mutex_lock(&all_info->died_mutex);
	if (all_info->someone_died)
	{
		pthread_mutex_unlock(&all_info->died_mutex);
		return ;
	}
	pthread_mutex_lock(&all_info->print_mutex);
	printf("%lld %d %s\n",
		ft_get_current_time() - all_info->start_time, id, msg);
	pthread_mutex_unlock(&all_info->print_mutex);
	pthread_mutex_unlock(&all_info->died_mutex);
}

void	free_all(t_all_info *all_info)
{
	ft_destroy_mutexes(all_info);
	free(all_info->input);
	free(all_info->philos);
	free(all_info);
}
