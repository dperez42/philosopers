/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:10:19 by daniel            #+#    #+#             */
/*   Updated: 2021/06/14 19:10:20 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers3.h"

int	ft_exit_error(void)
{
	write (2, "Error\n", 6);
	system(" leaks philo_one");
	exit (EXIT_FAILURE);
}

int ft_exit_ok(void)
{
	free(table);
	system(" leaks philo_one");
	exit(EXIT_SUCCESS);
}
