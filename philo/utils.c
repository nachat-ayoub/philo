/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:45:49 by anachat           #+#    #+#             */
/*   Updated: 2025/04/07 16:19:30 by anachat          ###   ########.fr       */
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

size_t	get_time(void)
{
	struct timeval	time;
	if (gettimeofday(&time, NULL) == -1)
		return (write(2, "gettimeofday Error\n", 20), 0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_usleep(size_t ms)
{
	size_t	start;
	int		res;

	start = get_time();
	while ((get_time() - start) < ms)
		res = usleep(500);
	return (res);
}
