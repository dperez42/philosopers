/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:58:21 by daniel            #+#    #+#             */
/*   Updated: 2021/06/14 19:50:15 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers2.h"

int	ft_exit_error(void)
{
	write (2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

int ft_exit_ok(void)
{
	int i;

	i = 1;
	pthread_detach(table->controller);
	while(i <= table->nb_of_philosophers)
		pthread_detach(table->philos[i++].philo);
	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("lock");
	sem_close(table->forks);
	sem_close(table->write);
	sem_close(table->lock);
	free(table->philos);
	free(table);
	exit(EXIT_SUCCESS);
}
