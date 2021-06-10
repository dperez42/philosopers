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
