/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:10:04 by daniel            #+#    #+#             */
/*   Updated: 2021/06/17 12:17:24 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers3.h"

//action of taking forks
void	ft_take_fork(int philo)
{
	unsigned long long	time;

	sem_wait(g_table->lock);
	sem_wait(g_table->forks);
	time = ft_gettime();
	ft_msg(time, philo, " has taken a fork\n");
	sem_wait(g_table->forks);
	time = ft_gettime();
	ft_msg(time, philo, " has taken a fork\n");
	sem_post(g_table->lock);
	return ;
}

//release forks
void	ft_release_fork(int philo)
{
	sem_post(g_table->forks);
	sem_post(g_table->forks);
	return ;
}

//life of a philosopher
int	ft_routine(void)
{
	unsigned long long	time;
	int					philo;

	philo = g_table->id;
	while (1)
	{
		ft_take_fork(philo);
		time = ft_gettime();
		g_table->last_meal = time;
		ft_msg(time, philo, " is eating\n");
		usleep(g_table->time_to_eat * 1000);
		ft_release_fork(philo);
		g_table->total_eats ++;
		if (g_table->total_eats == g_table->meals)
			return (FULL);
		time = ft_gettime();
		ft_msg(time, philo, " is sleeping\n");
		usleep(g_table->time_to_sleep * 1000);
		time = ft_gettime();
		ft_msg(time, philo, " is thinking\n");
	}
	return (0);
}

//check if die starving 
void	*ft_control(void *arg)
{
	unsigned long long	time;

	while (1)
	{
		time = ft_gettime();
		if ((time - g_table->last_meal) > g_table->time_to_die)
		{
			ft_msg(time, g_table->id, " has died\n");
			g_table->finish = 1;
			exit(DIED);
		}
	}
	return (NULL);
}

int	main(int argc, char **args)
{
	pid_t	*philo;

	if (!ft_parse(argc, args))
		return (0);
	philo = malloc (sizeof(pid_t) * (g_table->nb_of_philosophers + 1));
	if (!philo)
		exit(1);
	philo = ft_create_pid(philo);
	ft_create_waitpids(philo);
	ft_msg(ft_gettime(), 0, " All Philosphers had eaten enought\n");
	exit (0);
	return (0);
}
