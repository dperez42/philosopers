#include "philosophers.h"

//action of taking forks
void ft_take_fork(int philo, int philo_prev)
{
    unsigned long long time;

    pthread_mutex_lock(&table->fork);
    pthread_mutex_lock(&table->forks[table->philos[philo].fork_right]);
    time = ft_gettime();
    ft_msg(time, philo, " has taken a fork\n");
    pthread_mutex_lock(&table->forks[table->philos[philo].fork_left]);
    time = ft_gettime();
    ft_msg(time, philo, " has taken a fork\n");
    pthread_mutex_unlock(&table->fork);
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
    ft_take_fork(philo, philo_prev);
    time = ft_gettime();
    table->philos[philo].last_meal = time;
    ft_msg(time, philo, " is eating\n");
    usleep(table->time_to_eat * 1000);
    table->philos[philo].total_eats ++;
    time = ft_gettime();
    ft_msg(time, philo, " is sleeping\n");
    pthread_mutex_unlock(&table->forks[table->philos[philo].fork_right]);
    //ft_msg(time, philo, " has release fork\n");
    pthread_mutex_unlock(&table->forks[table->philos[philo].fork_left]);
    //ft_msg(time, philo, " has release fork\n");
    usleep(table->time_to_sleep * 1000);
    time = ft_gettime();
    ft_msg(time, philo, " is thinking\n");
    }
  
    return NULL;
}

void ft_full(unsigned long long time)
{
    int j;
    int flag;
    
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
        table->flag = 1;
        ft_exit_ok();
    }
    return ;
}

//check if die or full meals
void *ft_control(void *arg)
{
    int i;
    int nb_args;
    nb_args = *(int*)arg;
    unsigned long long time;
    
    while(1)
    {
        i = 1;
        while (i <= table->nb_of_philosophers)
        {
            pthread_mutex_lock(&table->control);
            time = ft_gettime();
            if ((time - table->philos[i].last_meal) > table->time_to_die)
            {
                ft_msg(time, i, " has died\n");
                table->flag = 1;
                ft_exit_ok();
            }
            if (nb_args == 6)
                ft_full(time);
            pthread_mutex_unlock(&table->control);
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