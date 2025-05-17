/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:34:04 by achanek           #+#    #+#             */
/*   Updated: 2025/05/17 16:30:35 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_iput
{
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
} t_input;

typedef struct s_philo
{
	pthread_mutex_t left_fork;
	pthread_mutex_t regth_fork;
	int id;
	int time_to_die;
	int time_to_eat;
	int time_to_steep;

}	t_philo;

typedef struct s_all_info
{
	pthread_mutex_t	*fork;
	t_philo			*philos;

} t_all_info;


int		ft_check_input(char **input);
int		ft_isdigit(int c);
void	ft_fill_struct(t_input *input, char **av, int ac);
void	ft_putstr_fd(char *str,int fd);
int		ft_atoi(char *str);


# endif