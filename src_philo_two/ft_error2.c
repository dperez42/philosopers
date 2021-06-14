/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:58:21 by daniel            #+#    #+#             */
/*   Updated: 2021/06/14 13:58:22 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers2.h"

int	ft_exit_error(void)
{
	write (2, "Error\n", 6);
	system(" leaks philo_one");
	exit (EXIT_FAILURE);
}

int ft_exit_ok(void)
{
	
	int i;
		pthread_detach(table->controller);
		i = 1;
	
	while(i <= table->nb_of_philosophers)
	{
		pthread_detach(table->philos[i].philo);
		i++;
	}
	
	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("lock");
	free(table->philos);
	free(table);
	
	//system(" leaks philo_two");
	exit(EXIT_SUCCESS);
}
