/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:39:17 by daniel            #+#    #+#             */
/*   Updated: 2021/06/28 01:15:18 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers3.h"

//action of taking forks
void	ft_take_fork(t_table *table)
{
	sem_wait(table->forks);
	sem_wait(table->forks);
	ft_msg(table, ft_gettime(table), table->id, "\e[1;32m\thas taken a fork\n\e[0m");
	ft_msg(table, ft_gettime(table), table->id, "\e[1;32m\thas taken a fork\n\e[0m");
	return ;
}

//release forks
void	ft_release_fork(t_table *table)
{
	sem_post(table->forks);
	sem_post(table->forks);
	return ;
}
