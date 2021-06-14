/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:10:29 by daniel            #+#    #+#             */
/*   Updated: 2021/06/14 19:10:30 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers3.h"

//init semaphores
int		init_sem(void)
{
	sem_unlink("forks");
	if ((table->forks = sem_open("forks", O_CREAT, S_IRWXU, table->nb_of_philosophers)) ==
																	SEM_FAILED)
		return (0);
	sem_unlink("write");
	if ((table->write = sem_open("write", O_CREAT, S_IRWXU, 1)) == SEM_FAILED)
		return (0);
	sem_unlink("lock");
	if ((table->lock = sem_open("lock", O_CREAT, S_IRWXU, 1)) == SEM_FAILED)
		return (0);
    return (1);
}

//parsing and init variables
int ft_parse(int argc, char **args)
{
    if (argc < 5 || argc > 6)
        ft_exit_error();
    table->nargc = argc;
    table->nb_of_philosophers = ft_atoi_int(args[1]);
    table->time_to_die = ft_atoi_int(args[2]);
    table->time_to_eat = ft_atoi_int(args[3]);
    table->time_to_sleep = ft_atoi_int(args[4]);
    table->init_time = ft_gettime_mill();
    if (argc == 6)
        table->meals = ft_atoi_int(args[5]);
    init_sem();
    table->total_eats = 0;
    table->last_meal = ft_gettime();
    return (1);
}