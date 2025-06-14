/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:22:27 by anachat           #+#    #+#             */
/*   Updated: 2025/06/14 17:02:35 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*simulation(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	
	return (NULL);
}

void	start_dinner(t_data *data)
{
	int	i;

	i = 0;
	if (data->min_meals == -1)
		return ;
	else if(data->num_philos == 1)
	{
		// TODO
	}
	else
	{
		while (i < data->num_philos)
		{
			thread_handle(&data->philos[i].thread, &simulation, &data->philos[i], THREAD_CREATE);
			i++;
		}		
	}
}