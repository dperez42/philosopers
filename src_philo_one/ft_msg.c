/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:00:42 by daniel            #+#    #+#             */
/*   Updated: 2021/06/14 20:00:50 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void ft_putnbr(unsigned long int nb)
{
    char c;

    if (nb < 10)
    {
        c = nb + '0';
        write(1, &c, 1);
    }
    else
    {
        ft_putnbr(nb/10);
        ft_putnbr(nb%10);
    }
}

void ft_msg(unsigned long long time, int philo, char *str)
{
    pthread_mutex_lock(&table->messg);
    if (table->flag != 1)
    {
        ft_putnbr(time);
        write(1," ",1);
        ft_putnbr(philo);
        write(1, str, ft_strlen(str));
    }
    pthread_mutex_unlock(&table->messg);
    return ;
}