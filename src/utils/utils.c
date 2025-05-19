/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:26:23 by achanek           #+#    #+#             */
/*   Updated: 2025/05/19 10:36:12 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../../include/philo.h"

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
	long n;
	int signe;
	int i;

	i = 0;
	n = 0;
	signe = 1;
	while (str[i])
	{
		n *= 10;
		n += str[i] - '0';
		i++;
	}
	if ((str[i] < '0' || str[i] > '9') || n > 2147483647)
		return (0);
	return (n * signe);
}