/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:36:05 by dperez-z          #+#    #+#             */
/*   Updated: 2021/06/23 08:50:10 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//Custom usleep funtion
void	ft_usleep(unsigned long long time, unsigned long long delay)
{
	while ((ft_gettime() - time) < delay)
	{}
	return ;
}

//life of a philosopher
void	*ft_routine(void *arg)
{
	unsigned long long	time;
	int					philo;

	philo = *(int *)arg;
	while (1)
	{
		ft_take_fork(philo);
		time = ft_gettime();
		g_table->philos[philo].last_meal = time;
		ft_msg(time, philo, "\e[32m\tis eating\n\e[0m");
		ft_usleep (time, g_table->time_to_eat);
		//usleep (g_table->time_to_eat * 1000);
		ft_release_fork(philo);
		g_table->philos[philo].total_eats ++;
		if (g_table->philos[philo].total_eats == g_table->max_meals)
		{
			g_table->finish_phi++;
			break;
		}
		time = ft_gettime();
		ft_msg(time, philo, "\e[1;34m\tis spleeping\n\e[0m");
		ft_usleep(time, g_table->time_to_sleep);
		//usleep(g_table->time_to_sleep * 1000);
		ft_msg(ft_gettime(), philo, "\e[34m\tis thinking\n\e[0m");
	}
	return (NULL);
}

//check if die or full meals
void	*ft_control(void *arg)
{
	int					i;
	unsigned long long	time;
	long long			aux;

	//i = *(int *)arg;
	while (1)
	{
		i = 1;
		time = ft_gettime();
		while (i <= g_table->nb_of_philosophers)
		//{
		//while (1)
		{
			//time = ft_gettime();
			aux = (time - g_table->philos[i].last_meal);
			if ( aux > g_table->time_to_die)
			{
				g_table->finish_time = 1;
				g_table->die_time = time;
				ft_msg(time, i, "\e[31m\thas died\n\e[0m");
				g_table->flag = 1;
				//exit(0);
				ft_exit_ok();
			}
			i++;
			//usleep(100);
		}
		usleep(10);
	}
	return (NULL);
}

int	main(int argc, char **args)
{
	int	i;
	unsigned long long	time;
	
	g_table = malloc (sizeof(t_table));
	if (!ft_parse(argc, args))
		return (0);
	while (1)
	{
		i = 1;
		if (g_table->finish_phi == (g_table->nb_of_philosophers) && argc == 6)
		{
			ft_msg(ft_gettime(), 0, "\e[0;35m\tlimit of meals reached\n\e[0m");
			g_table->flag = 1;
			ft_exit_ok();
		}
		if (g_table->finish_time == 1)
		{
			//ft_msg(g_table->die_time, i, "\e[31m\thas died\n\e[0m");
			//g_table->flag = 1;
			ft_exit_ok();
		}
	}
	return (0);
}
