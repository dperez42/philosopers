/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:58:28 by daniel            #+#    #+#             */
/*   Updated: 2021/06/17 12:46:36 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers2.h"

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

//life of a philosopher
void	*ft_routine(void *arg)
{
	unsigned long long	time;
	int					philo;
	int					philo_prev;

	philo = *(int *)arg;
	philo_prev = philo - 1;
	if (philo_prev < 1)
		philo_prev = g_table->nb_of_philosophers;
	while (1)
	{
		ft_take_fork(philo);
		time = ft_gettime();
		g_table->philos[philo].last_meal = time;
		ft_msg(time, philo, " is eating\n");
		usleep(g_table->time_to_eat * 1000);
		g_table->philos[philo].total_eats ++;
		time = ft_gettime();
		ft_msg(time, philo, " is sleeping\n");
		sem_post(g_table->forks);
		sem_post(g_table->forks);
		usleep(g_table->time_to_sleep * 1000);
		time = ft_gettime();
		ft_msg(time, philo, " is thinking\n");
	}
	return (NULL);
}

//Check if all philosophers have eate
void	ft_isfull(unsigned long long time)
{
	int	j;
	int	flag;

	j = 1;
	flag = 0;
	while (j <= g_table->nb_of_philosophers)
	{
		if (g_table->philos[j].total_eats < g_table->meals)
			flag = 1;
		j++;
	}
	if (!flag)
	{
		ft_msg(time, 0, " All philosopers have eaten\n");
		g_table->state = 1;
		ft_exit_ok();
	}
	return ;
}

//check if die or full meals
void	*ft_control(void *arg)
{
	int					i;
	int					nb_args;
	unsigned long long	time;

	nb_args = *(int *)arg;
	while (1)
	{
		i = 1;
		while (i <= g_table->nb_of_philosophers)
		{
			time = ft_gettime();
			if ((time - g_table->philos[i].last_meal) > g_table->time_to_die)
			{
				ft_msg(time, i, " has died\n");
				g_table->state = 1;
				ft_exit_ok();
			}
			if (nb_args == 6)
				ft_isfull(time);
			i++;
		}
	}
	return (NULL);
}

int	main(int argc, char **args)
{
	g_table = malloc (sizeof(t_table));
	if (!ft_parse(argc, args))
		return (0);
	while (1)
	{
	}
	return (0);
}
