/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:06:16 by anachat           #+#    #+#             */
/*   Updated: 2025/06/24 14:54:51 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	// mutex_handle(&philo->data->data_mtx, MUTEX_LOCK);
	pthread_mutex_lock(&philo->r_fork);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(&philo->l_fork);
	print_action(philo, "has taken a fork");
	// mutex_handle(&philo->data->data_mtx, MUTEX_UNLOCK);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->data_mtx);
	philo->meals_count++;
	philo->last_time_eat = get_time();
	print_action(philo, "is eating");
	pthread_mutex_unlock(&philo->data->data_mtx);
	ft_usleep(philo->data->time_to_eat);

	// put forks
	pthread_mutex_unlock(&philo->r_fork);
	pthread_mutex_unlock(&philo->l_fork);
}

void	sleeping(t_philo *philo)
{
	print_action(philo, "is sleeping");
	ft_usleep(philo->data->time_sleep);
}

void	thinking(t_philo *philo)
{
	print_action(philo, "is thinking");
}

void	died(t_philo *philo)
{
	print_action(philo, "died");
}
