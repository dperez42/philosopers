/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:10:04 by daniel            #+#    #+#             */
/*   Updated: 2021/06/28 13:43:44 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers3.h"

//life of a philosopher
int	ft_routine(t_table *table)
{
	unsigned long long	time;
	int					philo;

	philo = table->id;
	table->is_eating = 0;
	table->last_meal = ft_gettime(table);
	pthread_create(&table->controller, NULL, &ft_control, (void *)table);
	pthread_detach(table->controller);
	while (1)
	{	
		ft_take_fork(table);
		table->is_eating = 1;
		time = ft_gettime(table);
		table->last_meal = time;
		ft_msg(table, time, philo, "\e[32m\tis eating\n\e[0m");
		usleep (table->time_to_eat * 1000);
		ft_release_fork(table);
		time = ft_gettime(table);
		table->total_eats ++;
		table->is_eating = 0;
		if (table->total_eats == table->meals)
		{	
			//ft_msg(table, time, philo, "\e[1;34m\tha terminado de comer\n\e[0m");
			sem_post(table->nb_meal);
			break;
		}
		ft_msg(table, time, philo, "\e[1;34m\tis spleeping\n\e[0m");
		usleep(table->time_to_sleep*1000);
		time = ft_gettime(table);
		ft_msg(table, time, philo, "\e[34m\tis thinking\n\e[0m");		
	}
	ft_exit_child_ok(FULL);
	return(FULL);
}
//check if die starving 
void	*ft_control(void *arg)
{
	long long 	aux;
	t_table		*table;

	table = (t_table *)arg;
	
	while (1)
	{
		sem_wait(table->fork );
		aux = ft_gettime(table) - table->last_meal;
		if (!table->is_eating && aux > table->time_to_die)
		{
			ft_msg(table, ft_gettime(table), table->id, "\e[31m\thas died\n\e[0m");
			//sem_wait(table->write);
			sem_post(table->fork );
			//sem_wait(table->write);
			sem_post(table->end);
			//sem_wait(table->write);
			ft_exit_child_ok(DIED);
		}
		sem_post(table->fork);
		usleep(1000);
	}
	return (NULL);
}

//check if every philisophers had eaten
void	*full_meals(void *args)
{
	int j;
	t_table		*table;

	table = (t_table *)args;
	
	j = 1;
	while (j <= table->nb_of_philosophers)
	{
		sem_wait(table->nb_meal);
		j++;
	}
	ft_msg(table, ft_gettime_father(table), 0, "\e[0;35m\tLimit of meals reached\n\e[0m");
	//sem_wait(table->write);
	sem_post(table->end);
	//sem_wait(table->write);
	ft_exit_ok(table, FULL);
	return (NULL);
}

//main process
int	main(int argc, char **args)
{
	t_table		*table;
	pthread_t	thread_meals;

	table = malloc (sizeof(t_table));
	if (!table)
		exit(1);
	if (!ft_parse(table, argc, args))
		return (0);
	if (argc == 6)
	{
		if (pthread_create(&thread_meals, NULL, &full_meals, (void*)table))
			return (1);
		pthread_detach(thread_meals);
	}
	sem_wait(table->end);
	ft_exit_ok(table, 0);
	return (0);
}
