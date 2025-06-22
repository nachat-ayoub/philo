/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:45:49 by anachat           #+#    #+#             */
/*   Updated: 2025/06/22 20:53:40 by anachat          ###   ########.fr       */
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

	if (!str)
		return (-1);
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

void	clean(t_data **data)
{
	if (!data || !(*data))
		return ;
	free((*data)->philos);
	free((*data)->forks);
	free(*data);
	*data = NULL;
}

void	print_action(t_philo *philo, char *action)
{
	long	timestamp;

	mutex_handle(&philo->data->print_mtx, MUTEX_LOCK);
	if (!philo->data->end_sim)
	{
		timestamp = (get_time() - philo->data->start);
		printf("%ld %d %s\n", timestamp, philo->id, action);
	}
	mutex_handle(&philo->data->print_mtx, MUTEX_UNLOCK);
}

void	ft_usleep(long duration_ms)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < duration_ms)
		usleep(50);
}
