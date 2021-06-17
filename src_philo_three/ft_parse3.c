/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:10:29 by daniel            #+#    #+#             */
/*   Updated: 2021/06/17 12:07:51 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers3.h"

//init semaphores
int	init_sem(void)
{
	sem_unlink("forks");
	g_table->forks = sem_open("forks", O_CREAT, S_IRWXU,
			g_table->nb_of_philosophers);
	if (g_table->forks == SEM_FAILED)
		return (0);
	sem_unlink("write");
	g_table->write = sem_open("write", O_CREAT, S_IRWXU, 1);
	if (g_table->write == SEM_FAILED)
		return (0);
	sem_unlink("lock");
	g_table->lock = sem_open("lock", O_CREAT, S_IRWXU, 1);
	if (g_table->lock == SEM_FAILED)
		return (0);
	return (1);
}

//parsing and init variables
int	ft_parse(int argc, char **args)
{
	if (argc < 5 || argc > 6)
		ft_exit_error();
	g_table = malloc (sizeof(t_table));
	if (!g_table)
		exit(1);
	g_table->nargc = argc;
	g_table->nb_of_philosophers = ft_atoi_int(args[1]);
	g_table->time_to_die = ft_atoi_int(args[2]);
	g_table->time_to_eat = ft_atoi_int(args[3]);
	g_table->time_to_sleep = ft_atoi_int(args[4]);
	g_table->init_time = ft_gettime_mill();
	g_table->finish = 0;
	if (argc == 6)
		g_table->meals = ft_atoi_int(args[5]);
	init_sem();
	g_table->total_eats = 0;
	g_table->last_meal = ft_gettime();
	return (1);
}
