/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:10:24 by daniel            #+#    #+#             */
/*   Updated: 2021/06/17 11:12:36 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers3.h"

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

void	ft_msg(unsigned long long time, int philo, char *str)
{
	sem_wait(g_table->write);
	if (g_table->finish == 0)
	{
		ft_putnbr(time);
		write(1, " ", 1);
		ft_putnbr(philo);
		write(1, str, ft_strlen(str));
	}
	sem_post(g_table->write);
	return ;
}
