/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <anas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:34:04 by achanek           #+#    #+#             */
/*   Updated: 2025/05/24 16:11:24 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

#define ERROR1 "error: the input must be like this\n\
./philo  number_of_philosophers   time_to_die   time_to_eat   time_to_sleep  \
number_of_times_each_philosopher_must_eat(optional argument)\n"

#define ERROR_ARG_1 "ERROR: invalid number of number_of_philosophers\n"
#define ERROR_ARG_2 "ERROR: invalid time_to_die\n"
#define ERROR_ARG_3 "ERROR: invalid time_to_eat\n"
#define ERROR_ARG_4 "ERROR: invalid time_to_sleep\n"
#define ERROR_ARG_5 "ERROR: invalid number_of_times_each_philosopher_must_eat\n"

typedef struct s_iput
{
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
} t_input;

struct s_all_info;

typedef struct s_philo
{
	int id;
	int number_of_eat;
	int left_fork;
	int right_fork;
	long long last_meal;
	pthread_t thread;
	struct s_all_info *info;
} t_philo;


typedef struct s_all_info
{
	t_input				*input;
	t_philo				*philos;
	pthread_mutex_t		*fork;
	pthread_mutex_t 	print_mutex;
	pthread_mutex_t		meal_mutex;
	pthread_t			monitor_thread;
	int					someone_died;
	long long			start_time;
} t_all_info;



int			ft_print_errors(t_input *input, int ac);
int			ft_check_input(t_input *input,int ac,char **av);
void		ft_fill_input(t_input *input, int ac, char **av);
void		ft_putstr_fd(char *str,int fd);
int			ft_atoi(char *str);

void		*routine(void *arg);

int			fill_philo(t_all_info *all_info);
int			create_threads(t_all_info *all_info);
void		ft_join_threads(t_all_info *all_info);
int			ft_init_forks(t_all_info *all_info);

long long	ft_get_current_time(void);
void		ft_sleep(long long time_in_ms);

# endif