/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:39:17 by daniel            #+#    #+#             */
/*   Updated: 2021/06/29 10:37:42 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//action of taking forks
void	ft_take_fork(t_table *table)
{
	sem_wait(table->forks);
	sem_wait(table->forks);
	ft_msg(table, ft_gettime(table), table->id,
		"\e[1;32m\thas taken a fork\n\e[0m");
	ft_msg(table, ft_gettime(table), table->id,
		"\e[1;32m\thas taken a fork\n\e[0m");
	return ;
}

//release forks
void	ft_release_fork(t_table *table)
{
	sem_post(table->forks);
	sem_post(table->forks);
	return ;
}
