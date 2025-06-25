/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:29:14 by anachat           #+#    #+#             */
/*   Updated: 2025/06/24 18:21:37 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	mutex_handle(t_mutex *mutex, int code)
// {
// 	if (code == MUTEX_LOCK)
// 		return (pthread_mutex_lock(mutex));
// 	else if (code == MUTEX_UNLOCK)
// 		return (pthread_mutex_unlock(mutex));
// 	else if (code == MUTEX_INIT)
// 		return (pthread_mutex_init(mutex, NULL));
// 	else if (code == MUTEX_DESTROY)
// 		return (pthread_mutex_destroy(mutex));
// 	else
// 		return (printf("Wrong mutex operation code\n"), 1);
// }

// int	thread_handle(pthread_t *thread, void *(*fn)(void *), void *arg, int code)
// {
// 	if (code == THREAD_CREATE)
// 		return (pthread_create(thread, NULL, fn, arg));
// 	else if (code == THREAD_JOIN)
// 		return (pthread_join(*thread, NULL));
// 	else if (code == THREAD_DETACH)
// 		return (pthread_detach(*thread));
// 	else
// 		return (1);
// }

// int	simulation_end(t_data *data)
// {
// 	return (get_int(&data->data_mtx, &data->end_sim));
// }


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
	}
	pthread_mutex_destroy(&data->data_mtx);
	pthread_mutex_destroy(&data->print_mtx);
	free(data);
	return (status);
}