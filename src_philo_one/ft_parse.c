/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:01:09 by daniel            #+#    #+#             */
/*   Updated: 2021/06/23 08:44:40 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//init variables
void	init_phylos(void)
{
	int	i;

	g_table->philos = malloc (sizeof(t_philos)
			* (g_table->nb_of_philosophers + 1));
	g_table->forks = malloc (sizeof(pthread_mutex_t)
			* (g_table->nb_of_philosophers + 1));
	i = 1;
	while (i <= g_table->nb_of_philosophers)
	{
		if (i == 1)
			g_table->philos[i].fork_left = g_table->nb_of_philosophers;
		else
			g_table->philos[i].fork_left = i - 1;
		g_table->philos[i].fork_right = i;
		g_table->philos[i].id = i;
		pthread_mutex_init(&g_table->forks[i], NULL);
		i++;
	}
	i = 1;
	while (i <= g_table->nb_of_philosophers)
	{
		g_table->philos[i].total_eats = 0;
		g_table->philos[i].last_meal = ft_gettime();
		pthread_create(&g_table->philos[i].philo, NULL, ft_routine,
			(void *)&g_table->philos[i].id);
		i = i + 2;
	}
	usleep(1);
	i = 2;
	while (i <= g_table->nb_of_philosophers)
	{
		g_table->philos[i].total_eats = 0;
		g_table->philos[i].last_meal = ft_gettime();
		pthread_create(&g_table->philos[i].philo, NULL, ft_routine,
			(void *)&g_table->philos[i].id);
		i = i + 2;
	}
	//i = 1;
	//while (i <= g_table->nb_of_philosophers)
	//	pthread_detach(g_table->philos[i].philo);

	return ;
}

//parsing and init variables
int	ft_parse(int argc, char **args)
{
	int i;
	
	if (argc < 5 || argc > 6)
		ft_exit_error();
	g_table->nargc = argc;
	g_table->nb_of_philosophers = ft_atoi_int(args[1]);
	if (g_table->nb_of_philosophers == 0)
		ft_exit_ok();
	g_table->time_to_die = ft_atoi_int(args[2]);
	g_table->time_to_eat = ft_atoi_int(args[3]);
	g_table->time_to_sleep = ft_atoi_int(args[4]);
	if (argc == 6)
		g_table->max_meals = ft_atoi_int(args[5]);
	pthread_mutex_init(&g_table->fork, NULL);
	pthread_mutex_init(&g_table->messg, NULL);
	pthread_mutex_init(&g_table->time, NULL);
	g_table->finish_phi = 0;
	g_table->finish_time = 0;
	g_table->init_time = ft_gettime_mill();
	g_table->flag = 0;
	init_phylos();
	//i = 1;
	//while (i <= g_table->nb_of_philosophers)
	//{
	pthread_create(&g_table->controller, NULL, ft_control,
		(void *)&g_table->philos[i].id);
	//pthread_detach(g_table->controller);
		i = 1;
	while (i <= g_table->nb_of_philosophers)
		pthread_detach(g_table->philos[i].philo);
	//pthread_detach(g_table->controller);
	//	i++;
	//}
	return (1);
}
