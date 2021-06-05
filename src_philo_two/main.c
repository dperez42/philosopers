#include "philosophers.h"

//action of taking forks
void ft_take_fork(int philo)
{
    unsigned long long time;

    sem_wait(table->lock);
	sem_wait(table->forks);
    time = ft_gettime();
    ft_msg(time, philo, " has taken a fork\n");
	sem_wait(table->forks);
    time = ft_gettime();
    ft_msg(time, philo, " has taken a fork\n");
    sem_post(table->lock);
    return;

}

//life of a philosopher
void *ft_routine(void *arg)
{
    unsigned long long time;
    int philo;
    int philo_prev;

    philo = *(int*)arg;
    philo_prev = philo - 1;
    if (philo_prev < 1)
        philo_prev = table->nb_of_philosophers;
    while(1){
    ft_take_fork(philo);
    time = ft_gettime();
    table->philos[philo].last_meal = time;
    ft_msg(time, philo, " is eating\n");
    usleep(table->time_to_eat * 1000);
    table->philos[philo].total_eats ++;
    time = ft_gettime();
    ft_msg(time, philo, " is sleeping\n");
	sem_post(table->forks);
	sem_post(table->forks);
    usleep(table->time_to_sleep * 1000);
    time = ft_gettime();
    ft_msg(time, philo, " is thinking\n");
    }
  
    return NULL;
}

//check if die or full meals
void *ft_control(void *arg)
{
    int i;
    int nb_args;
    nb_args = *(int*)arg;
    unsigned long long time;
    int j;
    int flag;
    
    while(1)
    {
        i = 1;
        while (i <= table->nb_of_philosophers)
        {
            time = ft_gettime();
            if ((time - table->philos[i].last_meal) > table->time_to_die)
            {
                ft_msg(time, i, " has died\n");
                //printf("%llu %i Philosopher died\n", time, i);
                //printf(" %llu %i\n", (time - table->philos[i].last_meal), table->time_to_die);
                ft_exit_ok();
            }
            time = ft_gettime();
            if (nb_args == 6) // && table->philos[i].total_eats >= table->meals)
            {
                j = 1;
                flag = 0;
                while (j <= table->nb_of_philosophers)
                {
                    if (table->philos[j].total_eats < table->meals)
                        flag = 1;
                    j++;
                }
                if (!flag)
                {
                    ft_msg(time, 0, " All philosopers have eaten\n");
                    //printf("%llu all Philosoper have eaten\n", time);
                    ft_exit_ok();
                }
            }
            i++;
        }
    }
    
    return NULL;

}

int main(int argc, char **args)
{
    table = malloc (sizeof(t_table));
    if (!ft_parse(argc, args))
        return(0);;
    while (1)
    {
    }
    return (0);
}