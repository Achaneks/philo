/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:34:04 by achanek           #+#    #+#             */
/*   Updated: 2025/06/17 21:48:27 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# define ERROR1 "error: the input must be like this\n\
./philo  number_of_philosophers   time_to_die   time_to_eat   time_to_sleep  \
number_of_times_each_philosopher_must_eat(optional argument)\n"
# define ERROR_ARG_1 "ERROR: invalid number of number_of_philosophers\n"
# define ERROR_ARG_2 "ERROR: invalid time_to_die\n"
# define ERROR_ARG_3 "ERROR: invalid time_to_eat\n"
# define ERROR_ARG_4 "ERROR: invalid time_to_sleep\n"
# define ERROR_ARG_5 "ERROR: invalid number_of_times_each_philosopher_must_eat\n"

typedef struct s_iput
{
	int					n_of_ph;
	int					t_to_die;
	int					t_to_eat;
	int					t_to_sleep;
	int					n_of_t_eat;
}						t_input;

struct	s_all_info;

typedef struct s_philo
{
	int					id;
	int					eat_counter;
	int					left_fork;
	int					right_fork;
	long long			last_meal;
	pthread_t			thread;
	struct s_all_info	*all_info;
}						t_philo;

typedef struct s_all_info
{
	t_input				*input;
	t_philo				*philos;
	pthread_mutex_t		*fork;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		died_mutex;
	pthread_mutex_t		meal_mutex;
	pthread_mutex_t		eat_is_ok_mutex;
	pthread_t			monitor_thread;
	int					someone_died;
	int					n_of_e_is_ok;
	long long			start_time;
}						t_all_info;

int						ft_fill_input(t_input *input, int ac, char **av);
void					ft_putstr_fd(char *str, int fd);
long					ft_atoi(char *str);
void					update_last_meal(t_philo *philo);
void					ft_print_action(t_all_info *info, int id, char *msg);
void					*monitor(void *arg);
void					*routine(void *arg);
int						create_threads(t_all_info *all_info);
int						fill_philo(t_all_info *all_info);
int						ft_init_all_mutex(t_all_info *all_info);
void					ft_destroy_mutexes(t_all_info *info);
long long				ft_get_current_time(void);
void					*monitor(void *arg);
void					ft_print_action(t_all_info *info, int id, char *msg);
void					free_all(t_all_info *all_info);
void					ft_sleep(long long time_in_ms, t_all_info *all_info);

#endif