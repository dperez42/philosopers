/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:58:21 by daniel            #+#    #+#             */
/*   Updated: 2021/06/18 20:44:33 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers2.h"

int	ft_exit_error(void)
{
	write (2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

int	ft_exit_ok(void)
{
	int	i;

	i = 1;
	while (i <= g_table->nb_of_philosophers)
		pthread_detach(g_table->philos[i++].philo);
	free(g_table->philos);
	free(g_table);
	exit(EXIT_SUCCESS);
}
