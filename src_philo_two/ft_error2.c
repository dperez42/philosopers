/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:58:21 by daniel            #+#    #+#             */
/*   Updated: 2021/06/17 11:12:36 by dperez-z         ###   ########.fr       */
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
	pthread_detach(g_table->controller);
	while(i <= g_table->nb_of_philosophers)
		pthread_detach(g_table->philos[i++].philo);
	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("lock");
	sem_close(g_table->forks);
	sem_close(g_table->write);
	sem_close(g_table->lock);
	free(g_table->philos);
	free(g_table);
	exit(EXIT_SUCCESS);
}
