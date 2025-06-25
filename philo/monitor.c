/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 10:20:08 by anachat           #+#    #+#             */
/*   Updated: 2025/06/25 22:09:01 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulation_running(t_data *data)
{
	int	run;

	run = 1;
	pthread_mutex_lock(&data->death_mtx);
	run = data->simul_running;
	pthread_mutex_unlock(&data->death_mtx);
	return (run);
}

static void	check_philos_death(t_data *data)
{
	t_philo	*philo;
	long	curr_time;
	int		i;

	i = -1;
	while (++i < data->num_philos)
	{
		philo = &data->philos[i];
		curr_time = get_time();
		pthread_mutex_lock(&data->death_mtx);
		if ((curr_time - philo->last_time_eat) > data->time_to_die)
		{
			data->simul_running = 0;
			pthread_mutex_unlock(&data->death_mtx);
			pthread_mutex_lock(&data->print_mtx);
			printf("%ld %d died\n", curr_time - data->start, philo->id);
			pthread_mutex_unlock(&data->print_mtx);
			break ;
		}
		pthread_mutex_unlock(&data->death_mtx);
	}
}

static void	check_philos_ate(t_data *data)
{
	t_philo	*philo;
	int		all_ate;
	int		i;

	all_ate = 1;
	i = -1;
	while (++i < data->num_philos)
	{
		philo = &data->philos[i];
		pthread_mutex_lock(&data->death_mtx);
		if (philo->meals_count < data->min_meals)
			all_ate = 0;
		pthread_mutex_unlock(&data->death_mtx);
	}
	if (all_ate)
	{
		pthread_mutex_lock(&data->death_mtx);
		data->simul_running = 0;
		pthread_mutex_unlock(&data->death_mtx);
	}
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (simulation_running(data))
	{
		check_philos_death(data);
		if (data->min_meals != -1)
			check_philos_ate(data);
		ft_usleep(1000);
	}
	return (NULL);
}
