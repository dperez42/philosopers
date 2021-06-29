/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:10:19 by daniel            #+#    #+#             */
/*   Updated: 2021/06/28 13:34:57 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers3.h"

int	ft_exit_error(void)
{
	write (2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

int	ft_exit_child_ok(int ex)
{
	sem_unlink("time");
	sem_unlink("fork");
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
		//waitpid(table->philo[j], &status, 0);
		j++;
	}
	free(table->philo);
	//free(table);
	exit(ex);
}
