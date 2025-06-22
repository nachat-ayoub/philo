/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:22:27 by anachat           #+#    #+#             */
/*   Updated: 2025/06/22 21:06:50 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_dinner(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->num_philos == 1)
	{
		print_action(philo, "has taken a fork");
		ft_usleep(philo->data->time_to_die);
		// print_action(philo, "died");
		return (NULL);
	}
	// while (!simulation_ended(philo->data))
	// {
		// think();
		// take_forks();
		// eat();
		// put_forks();
		// sleep();
	// }
	return (NULL);
}