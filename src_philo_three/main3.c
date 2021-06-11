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
    return ;
}

//release forks
void ft_release_fork(int philo)
{
    unsigned long long time;

    time = ft_gettime();
    ft_msg(time, philo, " has release a fork\n");
    time = ft_gettime();
    ft_msg(time, philo, " has release a fork\n");
    sem_post(table->forks);
    sem_post(table->forks);
    return ;
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
            return(FULL);
        }
        time = ft_gettime();
        ft_msg(time, philo, " is sleeping\n");
        usleep(table->time_to_sleep * 1000);
        time = ft_gettime();
        ft_msg(time, philo, " is thinking\n");
    }
    return (0);
}

//check if die or full meals
void *ft_control(void *arg)
{
    unsigned long long time;

    while(1)
    {
        //printf("Hh");    
        if (getppid() != table->pid_table){
            printf("the father stops\n");
                exit(0);
        }
        time = ft_gettime();
        if ((time - table->last_meal) > table->time_to_die)
        {
            ft_msg(time, table->id, " has died\n");
            exit(DIED);
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
    pid_t pid_table;
    int wstatus;

   
    printf(" pid del padre %i \n", pid_table);
    table = malloc (sizeof(t_table));
    table->pid_table = getpid();
    if (!ft_parse(argc, args))
        return(0);
    int i;
    i = 1;
    while (i <= table->nb_of_philosophers)
    {
        philo = fork();
        //printf(" philo number %d \n", philo); //no funciona
        if (philo == 0)           //inicia los procesos
		{	
            table->id = i;
            pthread_create (&table->controller , NULL , ft_control,  (void *)&table->id ); //probar si declaranlo antes?
            exit(ft_routine());
        }
        else if (philo == -1)
        {
           //s printf(" pid del padre  en el hijo %i \n", philo);
        }
        else if (philo > 0)
        {
            //printf(" pid del padre  en el hijo %i \n", philo);
            //printf(" "); //do nothing para seguir creando procesos
            //exit(0);
        }
        i++;
    }
    i = 1;
    while (i <= table->nb_of_philosophers)
    {
        waitpid(philo, &wstatus, WUNTRACED | WCONTINUED);
        if (WIFEXITED(wstatus)) {
                ft_msg(ft_gettime(), WEXITSTATUS(wstatus), " exit status\n");
                //printf(" %i exited, status=%d\n", i, WEXITSTATUS(wstatus));
                if (WEXITSTATUS(wstatus) == DIED)
                {
                    usleep(5 * 1000);
                    exit(0);
                }
    }
    i++;
    }
    printf("everyone has eaten enought\n");
    //system(" leaks philo_three");
    exit(0);
    return (0);
}