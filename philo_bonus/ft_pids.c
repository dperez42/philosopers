/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:17:12 by dperez-z          #+#    #+#             */
/*   Updated: 2021/06/29 11:06:12 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//Create semaphores of childs process
int	ft_create_sema_childs(t_table *table)
{
	sem_unlink("time");
	table->time = sem_open("time", O_CREAT | O_EXCL, 0644, 1);
	if (table->time == SEM_FAILED)
		return (1);
	sem_unlink("fork");
	table->fork = sem_open("fork", O_CREAT | O_EXCL, 0644, 1);
	if (table->fork == SEM_FAILED)
		return (1);
	return (0);
}

//Create pids.
int	ft_create_pid(t_table *table)
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
			table->is_eating = 0;
			ft_create_sema_childs(table);
			ft_routine(table);
			exit(0);
		}
		else if (table->philo[i] == -1)
			exit (1);
		i++;
	}
	return (0);
}
