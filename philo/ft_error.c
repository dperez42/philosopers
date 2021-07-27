/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:00:36 by daniel            #+#    #+#             */
/*   Updated: 2021/07/05 08:35:27 by dperez-z         ###   ########.fr       */
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
	while (i <= g_table->nb_of_philosophers)
		pthread_mutex_destroy(&g_table->forks[i++]);
	exit (EXIT_SUCCESS);
}
