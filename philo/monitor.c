/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 10:20:08 by anachat           #+#    #+#             */
/*   Updated: 2025/06/26 21:17:47 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_philos_death(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < data->num_philos)
	{
		philo = &data->philos[i];
		pthread_mutex_lock(&data->death_mtx);
		if ((get_time() - philo->last_time_eat) > data->time_to_die)
		{
			pthread_mutex_unlock(&data->death_mtx);
			set_simulation_running(data, 0);
			pthread_mutex_lock(&data->print_mtx);
			printf("%ld %d died\n", get_time() - data->start, philo->id);
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

	i = -1;
	all_ate = 1;
	while (++i < data->num_philos)
	{
		philo = &data->philos[i];
		pthread_mutex_lock(&data->death_mtx);
		if (philo->meals_count < data->min_meals)
			all_ate = 0;
		pthread_mutex_unlock(&data->death_mtx);
		if (!all_ate)
			break ;
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
		ft_sleep(1);
	}
	return (NULL);
}
