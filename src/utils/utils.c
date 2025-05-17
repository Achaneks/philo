/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:26:23 by achanek           #+#    #+#             */
/*   Updated: 2025/05/16 09:27:11 by achanek          ###   ########.fr       */
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