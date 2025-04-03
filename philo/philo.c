/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:07:14 by anachat           #+#    #+#             */
/*   Updated: 2025/04/03 16:09:21 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *arg)
{
	printf("Thread says: %s\n", (char *)arg);
	return ("NULL");
}

int	main(int ac, char **av)
{
	pthread_t t1;

	(void)ac;
	(void)av;

	// void *res = NULL;
	// pthread_create(&t1, NULL, &routine, "Hi!");
	// pthread_join(t1, NULL);

	return 0;
}
