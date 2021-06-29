/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:10:29 by daniel            #+#    #+#             */
/*   Updated: 2021/06/28 13:37:50 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers3.h"

//init semaphores
int	init_sem(t_table *table)
{
	int		i;
	char	semaphore[250];

	sem_unlink("forks");
	table->forks = sem_open("forks", O_CREAT | O_EXCL, 0644,
			table->nb_of_philosophers);
	if (table->forks == SEM_FAILED)
		return (0);
	// O_CREAT, S_IRWXU
	/*
	sem_unlink("fork");
	table->fork = sem_open("fork", O_CREAT | O_EXCL, 0644, 1);
	if (table->fork == SEM_FAILED)
		return (0);
	*/
	sem_unlink("write");
	table->write = sem_open("write", O_CREAT | O_EXCL, 0644, 1);
	if (table->write == SEM_FAILED)
		return (0);
	sem_unlink("timeA");
	table->timeA = sem_open("timeA", O_CREAT | O_EXCL, 0644, 1);
	if (table->time == SEM_FAILED)
		return (0);
	sem_unlink("end");
	table->end = sem_open("end", O_CREAT | O_EXCL, 0644, 0);
	if (table->end == SEM_FAILED)
		return (0);
	sem_unlink("meal");
	table->nb_meal = sem_open("meal", O_CREAT | O_EXCL, 0644, 0);
	if (table->nb_meal == SEM_FAILED)
		return (0);
	return (1);
}

//parsing and init variables
int	ft_parse(t_table *table, int argc, char **args)
{
	if (argc < 5 || argc > 6)
		ft_exit_error();
	table->nargc = argc;
	table->nb_of_philosophers = ft_atoi_int(args[1]);
	table->time_to_die = ft_atoi_int(args[2]);
	table->time_to_eat = ft_atoi_int(args[3]);
	table->time_to_sleep = ft_atoi_int(args[4]);
	table->init_time = ft_gettime_mill();
	if (argc == 6)
		table->meals = ft_atoi_int(args[5]);
	init_sem(table);
	ft_create_pid(table);
	return (1);
}
