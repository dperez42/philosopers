/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 20:45:51 by daniel            #+#    #+#             */
/*   Updated: 2021/06/20 19:33:50 by daniel           ###   ########.fr       */
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
	ft_msg(time, philo, "\e[1;32m\thas taken a fork\n\e[0m");
	sem_wait(g_table->forks);
	time = ft_gettime();
	ft_msg(time, philo, "\e[1;32m\thas taken a fork\n\e[0m");
	sem_post(g_table->lock);
	return ;
}

// Release forks;
void	ft_release_fork(int philo)
{
	unsigned long long	time;
	
	sem_post(g_table->forks);
	sem_post(g_table->forks);
	//time = ft_gettime();
	//ft_msg(time, philo, " has release a fork\n");
	//time = ft_gettime();
	//ft_msg(time, philo, " has release a fork\n");
	return ;
}
