/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 10:20:08 by anachat           #+#    #+#             */
/*   Updated: 2025/06/24 15:33:47 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulation_ended(t_data *data)
{
	int	ended;

	ended = 0;
	pthread_mutex_lock(&data->death_mtx);
	ended = data->end_sim;
	pthread_mutex_unlock(&data->death_mtx);
	return (ended);
}

static void check_philos_death(t_data *data)
{
	t_philo	*philo;
	long	curr_time;
	int		i;

	i = 0;
	while(i < data->num_philos)
	{
		philo = &data->philos[i];
		curr_time = get_time();
		pthread_mutex_lock(&data->death_mtx);
		// print the condition values
		if ((curr_time - philo->last_time_eat) >= data->time_to_die)
		{
			data->end_sim = 1;
			pthread_mutex_unlock(&data->death_mtx);
			pthread_mutex_lock(&data->print_mtx);
			printf("%ld %d died\n", curr_time - data->start, philo->id);
			pthread_mutex_unlock(&data->print_mtx);
			break;
		}
		pthread_mutex_unlock(&data->death_mtx);
		i++;
	}
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	printf("Monitor thread started\n");
	while (1)
	{
		if (simulation_ended(data))
			break;
		check_philos_death(data);
	}
	return (NULL);
}
