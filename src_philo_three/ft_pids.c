/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:17:12 by dperez-z          #+#    #+#             */
/*   Updated: 2021/06/28 12:34:39 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers3.h"

//Create pids.
int		ft_create_pid(t_table *table)
{
	int		i;

	table->philo = malloc (sizeof(pid_t) * (table->nb_of_philosophers + 1));
	if (!table->philo)
		exit(1);
	i = 1;
	while (i <= table->nb_of_philosophers)
	{
		table->philo[i] = fork();
		if (table->philo[i] == 0)
		{
			table->id = i;
			table->total_eats = 0;
			sem_unlink("time");
			table->time = sem_open("time", O_CREAT | O_EXCL, 0644, 1);
			if (table->time == SEM_FAILED)
				return (0);
			sem_unlink("fork");
			table->fork = sem_open("fork", O_CREAT | O_EXCL, 0644, 1);
			if (table->fork == SEM_FAILED)
				return (0);
			ft_routine(table);
			exit(0);
		}
		else if (table->philo[i] == -1)
		{
			exit (1);
		}
		i++;
	}
	
	return (0);
}
