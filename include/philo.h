/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:34:04 by achanek           #+#    #+#             */
/*   Updated: 2025/05/19 11:08:36 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define ERROR1 "error: the input must be like this\n\
./philo  number_of_philosophers   time_to_die   time_to_eat   time_to_sleep  \
number_of_times_each_philosopher_must_eat(optional argument))"

#define ERROR_ARG_1 "number of number_of_philosophers is not valid"
#define ERROR_ARG_2 "time_to_die is not valid"
#define ERROR_ARG_3 "time_to_eat  is not valid"
#define ERROR_ARG_4 "time_to_sleep is not valid"
#define ERROR_ARG_5 "number_of_times_each_philosopher_must_eat is not valid"

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


int		ft_print_errors(t_input *input, int ac);
int		ft_check_input(t_input *input,int ac,char **av);
void	ft_fill_input(t_input *input, char **av, int ac);
void	ft_putstr_fd(char *str,int fd);
int		ft_atoi(char *str);


# endif