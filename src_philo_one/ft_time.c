/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:34:38 by dperez-z          #+#    #+#             */
/*   Updated: 2021/06/21 00:21:25 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long long	ft_gettime_mill(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

unsigned long long	ft_gettime(void)
{
	static struct timeval	tv;
	unsigned long long	time;
	
	pthread_mutex_lock(&g_table->time);
	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000);
	time = time - g_table->init_time;
	pthread_mutex_unlock(&g_table->time);
	return (time);
}
