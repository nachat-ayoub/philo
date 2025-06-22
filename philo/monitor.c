/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 10:20:08 by anachat           #+#    #+#             */
/*   Updated: 2025/06/22 20:52:29 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulation_ended(t_data *data)
{
	int	ended;

	mutex_handle(&data->data_mtx, MUTEX_LOCK);
	ended = data->end_sim;
	mutex_handle(&data->data_mtx, MUTEX_UNLOCK);
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
		// printf("%ld > %ld\n", (curr_time - philo->last_time_eat), data->time_to_die);
		mutex_handle(&data->data_mtx, MUTEX_LOCK);
		if ((curr_time - philo->last_time_eat) > data->time_to_die)
		{
			printf("Checking philosopher Hahah \n");
			print_action(philo, "died");
			data->end_sim = 1;
		}
		mutex_handle(&data->data_mtx, MUTEX_UNLOCK);
		i++;
	}
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	// write the routine:
	while (!simulation_ended(data))
	{
		check_philos_death(data);
	}
	return (NULL);
}
