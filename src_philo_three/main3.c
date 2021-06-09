#include "philosophers3.h"

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

void ft_release_fork(int philo)
{
    unsigned long long time;

    //sem_wait(table->lock);
    time = ft_gettime();
    ft_msg(time, philo, " has release a fork\n");
    time = ft_gettime();
    ft_msg(time, philo, " has release a fork\n");
    sem_post(table->forks);
    sem_post(table->forks);
    //sem_post(table->lock);
    return;
}

//life of a philosopher
int ft_routine(void)
{
    unsigned long long time;
    int philo;

    philo = table->id;
    while(1)
    {
        ft_take_fork(philo);
        time = ft_gettime();
        table->last_meal = time;
        ft_msg(time, philo, " is eating\n");
        usleep(table->time_to_eat * 1000);
        ft_release_fork(philo);
        table->total_eats ++;
        if (table->total_eats == table->meals)
        {
            ft_msg(table->total_eats, philo, " is full of meals\n");
            return(2);
        }
        time = ft_gettime();
        ft_msg(time, philo, " is sleeping\n");
        usleep(table->time_to_sleep * 1000);
        time = ft_gettime();
        ft_msg(time, philo, " is thinking\n");
    }
  
    return (2);
}

//check if die or full meals
void *ft_control(void *arg)
{
    unsigned long long time;

    while(1)
    {
        //printf("Hh");    
        time = ft_gettime();
        if ((time - table->last_meal) > table->time_to_die)
        {
            ft_msg(time, table->id, " has died\n");
            exit(3);
        }
    }
    return NULL;
}

int ft_check_states(int *states)
{
    int i;
    i = 1;
    while (i <= table->nb_of_philosophers)
    {
        if (states[i]==3)
            return(1);
        i++;
    }
    i = 1;
    while (i <= table->nb_of_philosophers)
    {
        if (states[i]!=2)
            return(0);
        i++;
    }
    return(1);
}

int main(int argc, char **args)
{
    pid_t philo;
    int *pids;

    table = malloc (sizeof(t_table));
    if (!ft_parse(argc, args))
        return(0);;
    pids = malloc(sizeof(int)*(table->nb_of_philosophers+1));
    int i;
    i = 1;
    while (i <= table->nb_of_philosophers)
    {
        philo = fork();
        printf(" philo number %d \n", philo); //no funciona
        pids[i] = philo;
        if (philo == 0)           //inicia los procesos
		{	
            table->id = i;
            pthread_create (&table->controller , NULL , ft_control,  (void *)&table->id ); //probar si declaranlo antes?
            exit(ft_routine());
        }
        else if (philo == -1)
        {
            //error//
        }
        else if (philo > 0)
        {
            printf(" "); //do nothing para seguir creando procesos
            //exit(0);
        }
        i++;
    }

    while(1){}



   // while (1){}
    /*
    //while (1)
    //{
        i = 1;
        while (i <= table->nb_of_philosophers)
        {  
            if (table->philos[i] != 0)
            {
                wtr[i] = waitpid(table->philos[i], &wstatus, WUNTRACED | WCONTINUED);
                if (WIFEXITED(wstatus)) {
                    printf(" %i exited, status=%d\n", i, WEXITSTATUS(wstatus));
                    states[i] = WEXITSTATUS(wstatus);
                    //if (states[i] == 2)
                    //    exit(0);
                    exit (0);
                } 
            }
        i++;
        }
        //printf("aqui %i\n", ft_check_states(states));
        //if (ft_check_states(states)){
            //printf("aqui\n");
            //exit(0);
        //}
        //printf(" proceso %i\n", table->philos[0]);
    //}
   */
   //exit (0);
    return (0);
}