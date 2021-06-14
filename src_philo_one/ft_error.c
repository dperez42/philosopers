/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:00:36 by daniel            #+#    #+#             */
/*   Updated: 2021/06/14 20:00:37 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_exit_error(void)
{
	write (2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

int ft_exit_ok(void)
{
	int i;

	i = 1;
	pthread_mutex_destroy(&table->fork);
	pthread_mutex_destroy(&table->write);
	pthread_mutex_destroy(&table->control);
	while(i <= table->nb_of_philosophers)
		pthread_mutex_destroy(&table->forks[i++]);
	i = 1;
	while(i <= table->nb_of_philosophers)
		pthread_detach(table->philos[i++].philo);
	free(table->forks);
	free(table->philos);
	free(table);
	exit(EXIT_SUCCESS);
}
