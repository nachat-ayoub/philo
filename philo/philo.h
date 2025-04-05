/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:10:59 by anachat           #+#    #+#             */
/*   Updated: 2025/04/05 11:31:53 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <pthread.h>

typedef struct s_data t_data;

typedef struct s_fork
{
	int				fork_id;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_philo
{
	int		id;
	long	meals_c;
	long	last_eat;
	int		is_full;
	t_fork	*l_fork;
	t_fork	*r_fork;
}	t_philo;

struct s_data
{
	int	num_philos;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	min_meals;
	int	start; // timestamp
	int	end; // 1 | 0
};

int	ft_atoi(char *str);
int	parse(t_data *data, char **av);


#endif
