/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:21:36 by dperez-z          #+#    #+#             */
/*   Updated: 2021/06/17 14:21:56 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//action of taking forks
void	ft_take_fork(int philo, int philo_prev)
{
	unsigned long long	time;

	pthread_mutex_lock(&g_table->fork);
	pthread_mutex_lock(&g_table->forks[g_table->philos[philo].fork_right]);
	time = ft_gettime();
	ft_msg(time, philo, " has taken a fork\n");
	pthread_mutex_lock(&g_table->forks[g_table->philos[philo].fork_left]);
	time = ft_gettime();
	ft_msg(time, philo, " has taken a fork\n");
	pthread_mutex_unlock(&g_table->fork);
	return ;
}

// Release forks;
void	ft_release_fork(int philo, int philo_prev)
{
	pthread_mutex_unlock(
		&g_table->forks[g_table->philos[philo].fork_right]);
	pthread_mutex_unlock(&g_table->forks[g_table->philos[philo].fork_left]);
	return ;
}
