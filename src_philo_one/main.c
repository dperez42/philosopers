#include "philosophers.h"

//action of taking forks
void ft_take_fork(int philo, int philo_prev)
{
    unsigned long long time;

    pthread_mutex_lock(&g_table->fork);
    pthread_mutex_lock(&g_table->forks[g_table->philos[philo].fork_right]);
    time = ft_gettime();
    ft_msg(time, philo, " has taken a fork\n");
    pthread_mutex_lock(&g_table->forks[g_table->philos[philo].fork_left]);
    time = ft_gettime();
    ft_msg(time, philo, " has taken a fork\n");
    pthread_mutex_unlock(&g_table->fork);
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
        philo_prev = g_table->nb_of_philosophers;
    while(1){
    ft_take_fork(philo, philo_prev);
    time = ft_gettime();
    g_table->philos[philo].last_meal = time;
    ft_msg(time, philo, " is eating\n");
    usleep(g_table->time_to_eat * 1000);
    g_table->philos[philo].total_eats ++;
    time = ft_gettime();
    ft_msg(time, philo, " is sleeping\n");
    pthread_mutex_unlock(&g_table->forks[g_table->philos[philo].fork_right]);
    //ft_msg(time, philo, " has release fork\n");
    pthread_mutex_unlock(&g_table->forks[g_table->philos[philo].fork_left]);
    //ft_msg(time, philo, " has release fork\n");
    usleep(g_table->time_to_sleep * 1000);
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
    while (j <= g_table->nb_of_philosophers)
    {
        if (g_table->philos[j].total_eats < g_table->meals)
            flag = 1;
        j++;
    }
    if (!flag)
    {
        ft_msg(time, 0, " All philosopers have eaten\n");
        g_table->flag = 1;
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
        while (i <= g_table->nb_of_philosophers)
        {
            pthread_mutex_lock(&g_table->control);
            time = ft_gettime();
            if ((time - g_table->philos[i].last_meal) > g_table->time_to_die)
            {
                ft_msg(time, i, " has died\n");
                g_table->flag = 1;
                ft_exit_ok();
            }
            if (nb_args == 6)
                ft_full(time);
            pthread_mutex_unlock(&g_table->control);
            i++;
        }
    }
    return NULL;
}

int main(int argc, char **args)
{
    g_table = malloc (sizeof(t_g_table));
    if (!ft_parse(argc, args))
        return(0);;
    while (1)
    {
    }
    return (0);
}