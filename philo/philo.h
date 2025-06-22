/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:10:59 by anachat           #+#    #+#             */
/*   Updated: 2025/06/22 20:37:29 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
#include <unistd.h>

# define MUTEX_LOCK     1
# define MUTEX_UNLOCK   2
# define MUTEX_INIT     3
# define MUTEX_DESTROY  4

# define THREAD_CREATE   1
# define THREAD_JOIN     2
# define THREAD_DETACH   3

typedef pthread_mutex_t t_mutex;
typedef struct s_data t_data;

typedef struct	s_fork
{
	t_mutex	fork;
	int		fork_id;
}	t_fork;

typedef struct	s_philo
{
	int			id;
	int			is_full;
	long		meals_count;
	long		last_time_eat;
	pthread_t	thread;
	t_fork		*l_fork;
	t_fork		*r_fork;
	t_data		*data;
}	t_philo;

struct	s_data
{
	int		num_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_sleep;
	long	start; // timestamp
	int		min_meals;
	int		end_sim; // bool: 1 | 0
	t_fork	*forks;
	t_philo	*philos;
	t_mutex	data_mtx;
	t_mutex	print_mtx;
};

int		ft_atoi(char *str);
int		parse(t_data *data, char **av);
int		data_init(t_data *data);
int		mutex_handle(t_mutex *mutex, int code);
int		thread_handle(pthread_t *thread, void *(*fn)(void *), void *arg, int code);
int		simulation_end(t_data *data);
int		get_int(t_mutex *mutex, int *val);
void	set_int(t_mutex *mutex, int *dest, int val);
long	get_time();
void	ft_usleep(long duration_ms);
void	print_action(t_philo *philo, char *action);
void	*start_dinner(void *arg);
void    *monitor_routine(void *arg);
int		simulation_ended(t_data *data);


#endif