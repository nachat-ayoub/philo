/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:06:16 by anachat           #+#    #+#             */
/*   Updated: 2025/06/26 21:22:48 by anachat          ###   ########.fr       */
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


void	ft_sleep_2(long duration_ms, t_data *data)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < duration_ms)
	{
		if (!simulation_running(data))
			break ;
		usleep(100);
	}
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mtx);
	philo->meals_count++;
	philo->last_time_eat = get_time();
	print_action(philo, "is eating");
	pthread_mutex_unlock(&philo->data->death_mtx);
	
	ft_sleep_2(philo->data->time_to_eat, philo->data);
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
