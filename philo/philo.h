/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:16:22 by anachat           #+#    #+#             */
/*   Updated: 2025/06/26 21:16:23 by anachat          ###   ########.fr       */
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
# include <unistd.h>


// static int n = 0;
// # define malloc(x) (n++ == 6 ? NULL : (malloc(x)))

typedef pthread_mutex_t	t_mutex;
typedef struct s_data	t_data;

typedef struct s_philo
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
	long		start;
	int			min_meals;
	int			simul_running;
	int			all_ate;
	t_mutex		*forks;
	t_philo		*philos;
	t_mutex		death_mtx;
	t_mutex		print_mtx;
	pthread_t	monitor_th;
};

int		ft_atoi(char *str);
long	get_time(void);
void	ft_sleep(long duration_ms);
void	print_action(t_philo *philo, char *action);
void	*safe_malloc(size_t size);

int		parse(t_data *data, char **av);
int		data_init(t_data *data);
int		simulation_running(t_data *data);
void	set_simulation_running(t_data *data, int val);
int		clean(t_data *data, int status);

void	*start_dinner(void *arg);
void	*monitor_routine(void *arg);

void	take_forks(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

#endif
