/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:10:19 by daniel            #+#    #+#             */
/*   Updated: 2021/07/05 08:54:23 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_exit_error(void)
{
	write (2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

int	ft_exit_child_ok(int ex, t_table *table)
{
	sem_unlink("time");
	sem_unlink("fork");
	free(table->philo);
	exit(ex);
}

int	ft_exit_ok(t_table *table, int ex)
{
	int	j;
	int	status;

	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("end");
	sem_unlink("meal");
	sem_unlink("timeA");
	j = 1;
	while (j <= table->nb_of_philosophers)
	{
		kill(table->philo[j], SIGKILL);
		j++;
	}
	exit(ex);
}
