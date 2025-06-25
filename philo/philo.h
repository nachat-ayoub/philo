/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:10:59 by anachat           #+#    #+#             */
/*   Updated: 2025/06/25 18:50:39 by anachat          ###   ########.fr       */
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

// typedef struct	s_fork
// {
// 	t_mutex	mtx;
// 	int		fork_id;
// }	t_fork;

typedef struct	s_philo
{
	int			id;
	long		meals_count;
	long		last_time_eat;
	pthread_t	thread;
	t_mutex		*l_fork;
	t_mutex		*r_fork;
	t_data		*data;
}	t_philo;

struct	s_data
{
	int			num_philos;
	long		time_to_die;
	long		time_to_eat;
	long		time_sleep;
	long		start; // timestamp
	int			min_meals;
	int			simul_running; // bool: 1 | 0
	int			all_ate; // bool: 1 | 0
	t_mutex		*forks;
	t_philo		*philos;
	t_mutex		data_mtx;
	t_mutex		death_mtx;
	t_mutex		print_mtx;
	pthread_t	monitor_th;
};

int		ft_atoi(char *str);
int		parse(t_data *data, char **av);
int		data_init(t_data *data);
int		simulation_running(t_data *data);

long	get_time();
void	ft_usleep(long duration_ms);
void	print_action(t_philo *philo, char *action);
void	*start_dinner(void *arg);
void    *monitor_routine(void *arg);
int		clean(t_data *data, int status);

void	take_forks(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	died(t_philo *philo);












void	print_data(t_data *data);

#endif