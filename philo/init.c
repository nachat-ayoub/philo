/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:20:42 by anachat           #+#    #+#             */
/*   Updated: 2025/06/14 11:39:35 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_forks(t_philo *philo, t_fork *forks, int i)
{
	philo->r_fork = forks + i;
	philo->l_fork = forks + ((i + 1) % philo->data->num_philos); // % philo_nbr for last philo (last philo l_fork is id 0)
}

static void philos_init(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < data->num_philos)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->meals_count = 0;
		philo->is_full = 0;
		philo->data = data;
		set_forks(philo, data->forks, i);
	}
}

int	data_init(t_data *data)
{
	int i;
	data->end = 0;
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
		return (printf("Allocation Error\n"), 1);
	data->forks = malloc(sizeof(t_fork) * data->num_philos);
	if (!data->forks)
		return (printf("Allocation Error\n"), 1);
	i = -1;
	philos_init(data);
	while (++i < data->num_philos)
	{
		mutex_handle(&data->forks[i].fork, MUTEX_INIT);
		data->forks[i].fork_id = i;
	}
	return (0);
}
