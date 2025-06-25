/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:29:14 by anachat           #+#    #+#             */
/*   Updated: 2025/06/25 22:01:15 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
