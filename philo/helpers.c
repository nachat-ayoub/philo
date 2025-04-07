/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:29:14 by anachat           #+#    #+#             */
/*   Updated: 2025/04/07 10:54:56 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_handle(t_mutex *mutex, int code)
{
	if (code == MUTEX_LOCK)
		return (pthread_mutex_lock(mutex));
	else if (code == MUTEX_UNLOCK)
		return (pthread_mutex_unlock(mutex));
	else if (code == MUTEX_INIT)
		return (pthread_mutex_init(mutex, NULL));
	else if (code == MUTEX_DESTROY)
		return (pthread_mutex_destroy(mutex));
	else
		return (printf("Wrong mutex operation code\n"), 1);
}

int	thread_handle(pthread_t *thread, void *(*fn)(void *), void *arg, int code)
{
	if (code == THREAD_CREATE)
		return (pthread_create(thread, NULL, fn, arg));
	else if (code == THREAD_JOIN)
		return (pthread_join(*thread, NULL));
	else if (code == THREAD_DETACH)
		return (pthread_detach(*thread));
	else
		return (1);
}

void	set_int(t_mutex *mutex, int *dest, int val)
{ 
	mutex_handle(mutex, MUTEX_LOCK);
	*dest = val;
	mutex_handle(mutex, MUTEX_UNLOCK);
}

int	get_int(t_mutex *mutex, int *val)
{
	int	res;
	mutex_handle(mutex, MUTEX_LOCK);
	res = *val;
	mutex_handle(mutex, MUTEX_UNLOCK);
	return (res);
}

int	simulation_end(t_data *data)
{
	return (get_int(data->data_mtx, &data->end));
}
