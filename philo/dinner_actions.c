/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:06:16 by anachat           #+#    #+#             */
/*   Updated: 2025/06/27 15:56:08 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	// if (philo->id % 2 == 0)
	// {
	// 	pthread_mutex_lock(philo->l_fork);
	// 	print_action(philo, "has taken a fork");
	// 	pthread_mutex_lock(philo->r_fork);
	// 	print_action(philo, "has taken a fork");
	// }
	// else
	// {
		pthread_mutex_lock(philo->r_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		print_action(philo, "has taken a fork");
	// }
}

void	eating(t_philo *philo)
{
	print_action(philo, "is eating");
	ft_sleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->data->death_mtx);
	philo->meals_count++;
	philo->last_time_eat = get_time();
	pthread_mutex_unlock(&philo->data->death_mtx);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	sleeping(t_philo *philo)
{
	print_action(philo, "is sleeping");
	ft_sleep(philo->data->time_sleep);
}

void	thinking(t_philo *philo)
{
	print_action(philo, "is thinking");
}
