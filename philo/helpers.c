/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:29:14 by anachat           #+#    #+#             */
/*   Updated: 2025/06/26 21:16:14 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

int	simulation_running(t_data *data)
{
	int	run;

	run = 1;
	pthread_mutex_lock(&data->death_mtx);
	run = data->simul_running;
	pthread_mutex_unlock(&data->death_mtx);
	return (run);
}


void	set_simulation_running(t_data *data, int val)
{
	pthread_mutex_lock(&data->death_mtx);
	data->simul_running = val;
	pthread_mutex_unlock(&data->death_mtx);
}


int	clean(t_data *data, int status)
{
	int	i;

	if (!data)
		return (status);
	if (data->forks)
	{
		i = -1;
		while (++i)
			pthread_mutex_destroy(&data->forks[i]);
		free(data->forks);
		data->forks = NULL;
	}
	if (data->philos)
	{
		free(data->philos);
		data->philos = NULL;
		pthread_mutex_destroy(&data->death_mtx);
		pthread_mutex_destroy(&data->print_mtx);
	}
	free(data);
	return (status);
}
