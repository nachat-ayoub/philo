/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:20:42 by anachat           #+#    #+#             */
/*   Updated: 2025/06/27 11:26:29 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philos_init(t_data *data)
{
	t_philo	*philo;
	int		num_philos;
	int		i;

	data->philos = safe_malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
		return (1);
	num_philos = data->num_philos;
	i = -1;
	data->start = get_time();
	while (++i < num_philos)
	{
		philo = &data->philos[i];
		philo->id = i + 1;
		philo->meals_count = 0;
		philo->data = data;
		philo->r_fork = &data->forks[i];
		philo->l_fork = &data->forks[(i + 1) % num_philos];
		philo->last_time_eat = get_time();
	}
	return (0);
}

static int	init_forks(t_data *data, int len)
{
	int	i;

	data->forks = safe_malloc(sizeof(t_mutex) * data->num_philos);
	if (!data->forks)
		return (1);
	i = -1;
	while (++i < len)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{	
			while (--i)
				pthread_mutex_destroy(&data->forks[i]);
			return (free(data->forks), data->forks = NULL, 1);
		}
	}
	return (0);
}

static void	detach_philos_threads(t_philo *philos, int num_philos)
{
	while (--num_philos)
	{
		if (pthread_detach(philos[num_philos].thread) != 0)
		{
			printf("Failed to detach philo thread %d\n", philos[num_philos].id);
			return ;
		}
	}
}

static void	create_philos_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				start_dinner, &data->philos[i]) != 0)
		{	
			printf("Failed to create philosopher thread\n");
			detach_philos_threads(data->philos, i);
			return ;
		}
		i++;
	}
}

int	data_init(t_data *data)
{
	int	i;

	if (init_forks(data, data->num_philos))
		return (1);
	if (pthread_mutex_init(&data->death_mtx, NULL) != 0)
		return (free(data->philos), data->philos = NULL, 1);
	if (pthread_mutex_init(&data->print_mtx, NULL) != 0)
		return (pthread_mutex_destroy(&data->death_mtx),
			free(data->philos), data->philos = NULL, 1);
	if (philos_init(data))
		return (pthread_mutex_destroy(&data->death_mtx),
			pthread_mutex_destroy(&data->print_mtx), 1);
	create_philos_threads(data);
	if (pthread_create(&data->monitor_th, NULL, monitor_routine, data))
		return (printf("Failed to create monitor thread"),
			detach_philos_threads(data->philos, data->num_philos), 1);
	i = -1;
	while (++i < data->num_philos)
		pthread_join(data->philos[i].thread, NULL);
	pthread_join(data->monitor_th, NULL);
	return (0);
}
