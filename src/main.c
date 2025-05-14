/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:24:56 by achanek           #+#    #+#             */
/*   Updated: 2025/04/23 11:17:05 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void ft_putstr_fd(char *str,int fd)
{
	int i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		write (fd, &str[i],1);
		i++;
	}
}

int ft_atoi(char *str)
{
	int n;
	int signe;
	int i;

	i = 0;
	n = 0;
	signe = 1;
	if(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i])
	{
		n *= 10;
		n += str[i] - '0';
		i++;
	}
	return (n * signe);
}

int	ft_check_is_numbers(char **str)
{
	int i;
	int j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!(str[i][j] <= '9' && str[i][j] >= '0'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_fill_struct(t_philo *philo_info, char **av, int ac)
{
	philo_info->number_of_philosophers = ft_atoi(av[1]);
	philo_info->time_to_die = ft_atoi(av[2]);
	philo_info->time_to_eat = ft_atoi(av[3]);
	philo_info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo_info->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
}

int main(int ac, char **av)
{
	t_philo	*philo_info;

	if(!(ac == 5 || ac == 6))
		return (1);
	if (ft_check_is_numbers(av))
		return (1);
	ft_fill_struct(philo_info, av, ac);
	if (philo_info->number_of_philosophers <= 0 || philo_info->number_of_philosophers > 200)
		return ((ft_putstr_fd("Error: invalid number of philosophers\n", 2)), 1);

}