/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:07:14 by anachat           #+#    #+#             */
/*   Updated: 2025/06/26 11:29:47 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data		*data;

	if (ac != 5 && ac != 6)
		return (printf("Invalid args count\n"), 1);
	data = safe_malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->min_meals = -1;
	data->simul_running = 1;
	data->start = get_time();
	if (parse(data, av))
		return (clean(data, 1));
	if (data_init(data))
		return (clean(data, 1));
	return (clean(data, 0));
}
