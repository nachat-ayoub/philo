/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:20:42 by anachat           #+#    #+#             */
/*   Updated: 2025/06/25 18:00:46 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void	set_forks(t_philo *philo, t_fork *forks, int i)
// {
// 	int	num_philos;

// 	num_philos = philo->data->num_philos;
// 	philo->r_fork = &forks[i];
// 	philo->l_fork = &forks[(i + 1) % num_philos]; // % philo_nbr for last philo (last philo l_fork is id 0)
// }

long	get_time()
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000);
}

static void philos_init(t_data *data)
{
	t_philo	*philo;
	int		i;
	int		num_philos;
	
	i = -1;
	while (++i < data->num_philos)
	{
		num_philos = data->num_philos;
		philo = &data->philos[i];
		philo->id = i + 1;
		philo->meals_count = 0;
		philo->last_time_eat = get_time();
		philo->data = data;
		philo->r_fork = &data->forks[i];
		philo->l_fork = &data->forks[(i + 1) % num_philos];
	}
}

int	data_init(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->data_mtx, NULL);
	pthread_mutex_init(&data->death_mtx, NULL);
	pthread_mutex_init(&data->print_mtx, NULL);
	data->simul_running = 1;
	data->start = get_time();
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	// TODO: handle leaks on malloc fail
	if (!data->philos)
		return (printf("Allocation Error\n"), 1);
	data->forks = malloc(sizeof(t_mutex) * data->num_philos);
	if (!data->forks)
		return (printf("Allocation Error\n"), 1);
	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	philos_init(data);
	i = 0;
	while (i < data->num_philos)
	{
		pthread_create(&data->philos[i].thread, NULL, start_dinner, &data->philos[i]);
		i++;
	}
	i = 0;
	if (pthread_create(&data->monitor_th, NULL, monitor_routine, data))
		return (printf("Failed to create monitor thread")); // clean(data);
	pthread_join(data->monitor_th, NULL);
	while (i < data->num_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	return (0);
}
