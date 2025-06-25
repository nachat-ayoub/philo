/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:45:49 by anachat           #+#    #+#             */
/*   Updated: 2025/06/25 21:39:05 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	long	nb;
	size_t	i;

	if (!str || str[0] == '\0')
		return (0);
	if (!(*str))
		return (0);
	i = 0;
	nb = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		nb = nb * 10 + (str[i++] - '0');
		if (nb > INT_MAX)
			return (0);
	}
	return (nb);
}

void	print_action(t_philo *philo, char *action)
{
	long	timestamp;

	pthread_mutex_lock(&philo->data->print_mtx);
	if (philo->data->simul_running)
	{
		timestamp = (get_time() - philo->data->start);
		printf("%ld %d %s\n", timestamp, philo->id, action);
	}
	pthread_mutex_unlock(&philo->data->print_mtx);
}

void	ft_usleep(long duration_ms)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < duration_ms)
		usleep(50);
}
