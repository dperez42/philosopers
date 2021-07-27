/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:10:24 by daniel            #+#    #+#             */
/*   Updated: 2021/06/29 10:37:57 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putnbr(unsigned long int nb)
{
	char	c;

	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return ;
}

void	ft_msg(t_table *table, unsigned long long time, int philo, char *str)
{
	sem_wait(table->write);
	ft_putnbr(time);
	write(1, "\t", 1);
	if (philo != 0)
		ft_putnbr(philo);
	write(1, str, ft_strlen(str));
	sem_post(table->write);
	return ;
}
