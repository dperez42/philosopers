/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:17:12 by dperez-z          #+#    #+#             */
/*   Updated: 2021/06/17 12:17:19 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers3.h"

//Create Waitpids.
void	ft_create_waitpids(pid_t	*philo)
{
	int	i;
	int	j;
	int	wstatus;

	i = 1;
	while (i <= g_table->nb_of_philosophers)
	{
		waitpid(philo[i], &wstatus, WUNTRACED | WCONTINUED);
		if (WIFEXITED(wstatus))
		{
			if (WEXITSTATUS(wstatus) == DIED)
			{
				j = 1;
				while (j <= g_table->nb_of_philosophers)
					kill(philo[j++], 1);
				exit(0);
			}
		}
		i++;
	}
}

//Create pids.
pid_t	*ft_create_pid(pid_t *philo)
{
	int		i;

	i = 1;
	while (i <= g_table->nb_of_philosophers)
	{
		philo[i] = fork();
		if (philo[i] == 0)
		{	
			g_table->id = i;
			pthread_create(&g_table->controller, NULL, ft_control,
				(void *)&g_table->id);
			exit(ft_routine());
		}
		else if (philo[i] == -1)
		{
			exit (1);
		}
		i++;
	}
	return (philo);
}
