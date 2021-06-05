#include "philosophers.h"

//init variables
void init_phylos(void)
{
    int i;

    table->philos = malloc (sizeof(t_philos)*(table->nb_of_philosophers + 1));
    table->forks = malloc (sizeof(pthread_mutex_t)*(table->nb_of_philosophers + 1));
    i = 1;
    while (i <= table->nb_of_philosophers)
    {
        table->actual = i;
        pthread_mutex_init (&table->forks[i],NULL);
        if (i == 1)
            table->philos[i].fork_left = table->nb_of_philosophers;
        else 
            table->philos[i].fork_left = i - 1;
        table->philos[i].fork_right = i;
        table->philos[i].state = 0;
        table->philos[i].die = 0;
        table->philos[i].id = i;
        table->philos[i].total_eats = 0;
        table->philos[i].last_meal = ft_gettime();
        pthread_create (&table->philos[i].philo , NULL , ft_routine,  (void *)&table->philos[i].id );
        i++;
    }
    return;
}

//parsing and init variables
int ft_parse(int argc, char **args)
{
    if (argc < 5 || argc >6)
        ft_exit_error();
    table->nargc = argc;
    table->nb_of_philosophers = ft_atoi_int(args[1]);
    table->time_to_die = ft_atoi_int(args[2]);
    table->time_to_eat = ft_atoi_int(args[3]);
    table->time_to_sleep = ft_atoi_int(args[4]);
    pthread_mutex_init (&table->fork, NULL);
    pthread_mutex_init (&table->write, NULL);
    pthread_mutex_init (&table->control, NULL);
    pthread_mutex_init (&table->messg, NULL);
     table->init_time = ft_gettime_mill();
    if (argc == 6)
        table->meals = ft_atoi_int(args[5]);
    init_phylos();
    pthread_create (&table->controller, NULL , ft_control,  (void *)&table->nargc );
    return (1);
}