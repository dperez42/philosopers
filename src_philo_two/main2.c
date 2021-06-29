/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:58:28 by daniel            #+#    #+#             */
/*   Updated: 2021/06/20 19:31:03 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers2.h"

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
		//usleep(g_table->time_to_eat * 1000);
		ft_release_fork(philo);
		time = ft_gettime();
		g_table->philos[philo].total_eats ++;
		ft_msg(time, philo, "\e[1;34m\tis spleeping\n\e[0m");
		ft_usleep(time, g_table->time_to_sleep);
		ft_msg(ft_gettime(), philo, " \e[34m\tis thinking\n\e[0m");
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
		ft_msg(time, 0, "\e[0;35m\tLimit of meals reached\n\e[0m");
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
				ft_msg(time, i, "\e[31m\thas died\n\e[0m");
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
	int	i;
	unsigned long long	time;
	
	g_table = malloc (sizeof(t_table));
	if (!ft_parse(argc, args))
		return (0);
	while (1)
	{
		i = 1;
		sem_wait(g_table->control);
		while (i <= g_table->nb_of_philosophers)
		{
			time = ft_gettime();
			if ((time - g_table->philos[i].last_meal) > g_table->time_to_die)
			{
				ft_msg(time, i, "\e[31m\thas died\n\e[0m");
				g_table->state = 1;
				printf( " time: %llu last meal: %llu  tiem to die: %llu\n", time, g_table->philos[i].last_meal, g_table->time_to_die);
				ft_exit_ok();
			}
			i++;
		}
		time = ft_gettime();
		if (argc == 6)
			ft_isfull(time);
		sem_post(g_table->control);
	}
	return (0);
}
