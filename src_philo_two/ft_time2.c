/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:58:53 by daniel            #+#    #+#             */
/*   Updated: 2021/06/18 20:29:46 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers2.h"

//give actual time
unsigned long long	ft_gettime_mill(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

//give time from start
unsigned long long	ft_gettime(void)
{
	static struct timeval	tv;
	unsigned long long	time;
	
	sem_wait(g_table->time);
	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000);
	time = time - g_table->init_time;
	sem_post(g_table->time);
	return (time);	
}
