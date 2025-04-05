/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:07:14 by anachat           #+#    #+#             */
/*   Updated: 2025/04/05 11:44:21 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	print_data(t_data *data)
{
	if (!data)
		return ;
	printf("Data:\n");
	printf("  Number of philosophers     : %d\n", data->num_philos);
	printf("  Time to die (ms)           : %d\n", data->time_die);
	printf("  Time to eat (ms)           : %d\n", data->time_eat);
	printf("  Time to sleep (ms)         : %d\n", data->time_sleep);
	printf("  Minimum meals per philos.  : %d\n", data->min_meals);
	printf("  Start timestamp (ms)       : %d\n", data->start);
	printf("  Simulation ended?          : %s\n", data->end ? "yes" : "no");
}


int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 5 && ac != 6)
		return (printf("Invalid args count\n"), 1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (printf("Allocation Error\n"), 0);
	memset(data, 0, sizeof(t_data));
	if (parse(data, av))
		return (1);
	print_data(data);
	return (0);
}
