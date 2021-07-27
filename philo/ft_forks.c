/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:21:36 by dperez-z          #+#    #+#             */
/*   Updated: 2021/06/29 09:47:13 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//action of taking forks
void	ft_take_fork(int philo)
{
	unsigned long long	time;

	pthread_mutex_lock(&g_table->fork);
	pthread_mutex_lock(&g_table->forks[g_table->philos[philo].fork_left]);
	pthread_mutex_lock(&g_table->forks[g_table->philos[philo].fork_right]);
	time = ft_gettime();
	ft_msg(time, philo, "\e[1;32m\thas taken a fork\n\e[0m");
	ft_msg(time, philo, "\e[1;32m\thas taken a fork\n\e[0m");
	pthread_mutex_unlock(&g_table->fork);
	return ;
}

// Release forks;
void	ft_release_fork(int philo)
{
	pthread_mutex_unlock(
		&g_table->forks[g_table->philos[philo].fork_right]);
	pthread_mutex_unlock(&g_table->forks[g_table->philos[philo].fork_left]);
	return ;
}
