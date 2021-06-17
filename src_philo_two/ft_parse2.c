/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:58:24 by daniel            #+#    #+#             */
/*   Updated: 2021/06/17 13:28:38 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers2.h"

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

//init variables
void	init_phylos(void)
{
	int	i;

	g_table->philos = malloc (sizeof(t_philos)
			* (g_table->nb_of_philosophers + 1));
	i = 1;
	init_sem();
	while (i <= g_table->nb_of_philosophers)
	{
		g_table->philos[i].id = i;
		g_table->philos[i].total_eats = 0;
		g_table->philos[i].last_meal = ft_gettime();
		pthread_create(&g_table->philos[i].philo, NULL, ft_routine,
			(void *)&g_table->philos[i].id);
		i++;
	}
	return ;
}

//parsing and init variables
int	ft_parse(int argc, char **args)
{
	if (argc < 5 || argc > 6)
		ft_exit_error();
	g_table->nargc = argc;
	g_table->nb_of_philosophers = ft_atoi_int(args[1]);
	g_table->time_to_die = ft_atoi_int(args[2]);
	g_table->time_to_eat = ft_atoi_int(args[3]);
	g_table->time_to_sleep = ft_atoi_int(args[4]);
	g_table->init_time = ft_gettime_mill();
	g_table->state = 0;
	if (argc == 6)
		g_table->meals = ft_atoi_int(args[5]);
	init_phylos();
	pthread_create(&g_table->controller, NULL, ft_control,
		(void *)&g_table->nargc);
	return (1);
}
