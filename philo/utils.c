/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:45:49 by anachat           #+#    #+#             */
/*   Updated: 2025/06/27 18:37:56 by anachat          ###   ########.fr       */
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

	if (simulation_running(philo->data))
	{
		pthread_mutex_lock(&philo->data->print_mtx);
		timestamp = (get_time() - philo->data->start);
		printf("%ld %d %s\n", timestamp, philo->id, action);
		pthread_mutex_unlock(&philo->data->print_mtx);
	}
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (printf("Allocation Error\n"), NULL);
	memset(ptr, 0, size);
	return (ptr);
}

void	ft_sleep(long duration_ms, t_data *data)
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
