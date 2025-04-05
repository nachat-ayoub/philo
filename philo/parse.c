/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:16:58 by anachat           #+#    #+#             */
/*   Updated: 2025/04/05 11:44:05 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int parse(t_data *data, char **av)
{
	if (ft_atoi(av[1]) == -1 || ft_atoi(av[2]) == -1 || ft_atoi(av[3]) == -1
		|| ft_atoi(av[4]) == -1 || ft_atoi(av[5]) == -1)
		return (printf("Invalid Number\n"), 1);
	data->num_philos = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->min_meals = ft_atoi(av[5]);
	return (0);
}
