/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:20:42 by anachat           #+#    #+#             */
/*   Updated: 2025/06/25 22:07:59 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000);
}

static void	philos_init(t_data *data)
{
	t_philo	*philo;
	int		num_philos;
	int		i;

	num_philos = data->num_philos;
	i = -1;
	while (++i < num_philos)
	{
		philo = &data->philos[i];
		philo->id = i + 1;
		philo->meals_count = 0;
		philo->last_time_eat = get_time();
		philo->data = data;
		philo->r_fork = &data->forks[i];
		philo->l_fork = &data->forks[(i + 1) % num_philos];
	}
}

static int	init_forks(t_data *data, int len)
{
	int	i;

	data->forks = malloc(sizeof(t_mutex) * data->num_philos);
	if (!data->forks)
		return (printf("Allocation Error\n"), 1);
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

int	data_init(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
		return (printf("Allocation Error\n"), 1);
	if (init_forks(data->forks, data->num_philos))
		return (1);
	if (pthread_mutex_init(&data->death_mtx, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->print_mtx, NULL) != 0)
		return (1);
	philos_init(data);
	i = -1;
	while (++i < data->num_philos)
		pthread_create(&data->philos[i].thread, NULL,
			start_dinner, &data->philos[i]);
	if (pthread_create(&data->monitor_th, NULL, monitor_routine, data))
		return (printf("Failed to create monitor thread"), 1);
	i = -1;
	while (++i < data->num_philos)
		pthread_join(data->philos[i].thread, NULL);
	pthread_join(data->monitor_th, NULL);
	return (0);
}
