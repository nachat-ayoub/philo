/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:16:58 by anachat           #+#    #+#             */
/*   Updated: 2025/06/21 14:25:09 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int parse(t_data *data, char **av)
{
	if (!ft_atoi(av[1]) || !ft_atoi(av[2]) || !ft_atoi(av[3])
		|| !ft_atoi(av[4]) || !ft_atoi(av[5]))
		return (printf("Invalid Number\n"), 1);
	data->num_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]); // in ms
	data->time_to_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->min_meals = ft_atoi(av[5]);
	return (0);
}
