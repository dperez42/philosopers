/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:00:36 by daniel            #+#    #+#             */
/*   Updated: 2021/06/22 23:26:09 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_exit_error(void)
{
	write (2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

int	ft_exit_ok(void)
{
	int	i;

	
	i = 1;
	pthread_mutex_destroy(&g_table->fork);
	pthread_mutex_destroy(&g_table->messg);
	pthread_mutex_destroy(&g_table->time);
	pthread_detach(g_table->controller);
	while (i <= g_table->nb_of_philosophers)
		pthread_mutex_destroy(&g_table->forks[i++]);
	i = 1;
	//while (i <= g_table->nb_of_philosophers)
	//	pthread_detach(g_table->philos[i].philo);
	//free(g_table->forks);
	//free(g_table->philos);
	//free(g_table);
	exit(EXIT_SUCCESS);
}
