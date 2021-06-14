/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:10:04 by daniel            #+#    #+#             */
/*   Updated: 2021/06/14 19:10:05 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        time = ft_gettime();
        if ((time - table->last_meal) > table->time_to_die)
        {
            ft_msg(time, table->id, " has died\n");
            exit(DIED);
        }
    }
    return NULL;
}


int main(int argc, char **args)
{
    pid_t   *philo;
    pid_t   pid_table;
    int     wstatus;
    int     i;

    table = malloc (sizeof(t_table));
    if (!table)
        exit(1);
    //table->pid_table = getpid();
    if (!ft_parse(argc, args))
        return(0);
    philo = malloc (sizeof(pid_t) * (table->nb_of_philosophers + 1));
    if (!philo)
        exit(1);
    i = 1;
    while (i <= table->nb_of_philosophers)
    {
        philo[i] = fork();
        //printf(" philo number %d \n", philo); //no funciona
        if (philo[i] == 0)           //inicia los procesos
		{	
            table->id = i;
            pthread_create (&table->controller , NULL , ft_control,  (void *)&table->id ); //probar si declaranlo antes?
            exit(ft_routine());
        }
        else if (philo[i] == -1)
        {
           //s printf(" pid del padre  en el hijo %i \n", philo);
        }
        else if (philo[i] > 0)
        {
            printf(" pid del padre  en el hijo %i \n", philo[i]);
            //printf(" "); //do nothing para seguir creando procesos
            //exit(0);
        }
        i++;
    }
    int j;
    i = 1;
    while (i <= table->nb_of_philosophers)
    {
        waitpid(philo[i], &wstatus, 0); //WUNTRACED | WCONTINUED);
        if (WIFEXITED(wstatus)) {
                ft_msg(ft_gettime(), WEXITSTATUS(wstatus), " exit status\n");
                //printf(" %i exited, status=%d\n", i, WEXITSTATUS(wstatus));
                if (WEXITSTATUS(wstatus) == DIED)
                {
                    j = 1;
                    while (j <= table->nb_of_philosophers)
                        kill(philo[j++], 1);
                    exit(0);
                }
    }
    i++;
    } 
    ft_msg(ft_gettime(), 0, " All Philosphers had eaten enought\n");
    exit(0);
    return (0);
}