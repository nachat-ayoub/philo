/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:06:16 by anachat           #+#    #+#             */
/*   Updated: 2025/06/23 11:55:44 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	// mutex_handle(&philo->data->data_mtx, MUTEX_LOCK);

	mutex_handle(&philo->r_fork->mtx, MUTEX_LOCK);
	print_action(philo, "has taken a fork");
	mutex_handle(&philo->l_fork->mtx, MUTEX_LOCK);
	print_action(philo, "has taken a fork");

	// mutex_handle(&philo->data->data_mtx, MUTEX_UNLOCK);
}

void	eating(t_philo *philo)
{
	mutex_handle(&philo->data->data_mtx, MUTEX_LOCK);
	philo->meals_count++;
	philo->last_time_eat = get_time();
	print_action(philo, "is eating");
	ft_usleep(philo->data->time_to_eat);
	mutex_handle(&philo->data->data_mtx, MUTEX_UNLOCK);

	// put forks
	mutex_handle(&philo->r_fork->mtx, MUTEX_UNLOCK);
	mutex_handle(&philo->l_fork->mtx, MUTEX_UNLOCK);
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
