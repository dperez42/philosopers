/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:10:36 by daniel            #+#    #+#             */
/*   Updated: 2021/06/29 10:39:13 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//Get actual time
unsigned long long	ft_gettime_mill(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

//Get time from start
unsigned long long	ft_gettime(t_table *table)
{
	static struct timeval	tv;
	unsigned long long		time;

	sem_wait(table->time);
	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000);
	time = time - table->init_time;
	sem_post(table->time);
	return (time);
}

//Get time from start
unsigned long long	ft_gettime_father(t_table *table)
{
	static struct timeval	tv;
	unsigned long long		time;

	sem_wait(table->timeA);
	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000);
	time = time - table->init_time;
	sem_post(table->timeA);
	return (time);
}
