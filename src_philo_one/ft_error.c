#include "philosophers.h"

int	ft_exit_error(void)
{
	write (2, "Error\n", 6);
	system(" leaks philo_one");
	exit (EXIT_FAILURE);
}

int ft_exit_ok(void)
{
	int i;
	i = 1;

	pthread_mutex_destroy(&table->fork);
	pthread_mutex_destroy(&table->write);
	pthread_mutex_destroy(&table->control);
	while(i <= table->nb_of_philosophers)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
		i = 1;
	while(i <= table->nb_of_philosophers)
	{
		pthread_detach(table->philos[i].philo);
		i++;
	}
	free(table->forks);
	free(table->philos);
	free(table);
	//system(" leaks philo_one");
	exit(EXIT_SUCCESS);
}
