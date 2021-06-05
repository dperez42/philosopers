#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philos
{
    int        id;
    pthread_t  philo;
    unsigned long long       last_meal;
    int        total_eats;
    int        fork_left;
    int        fork_right;
    int        die;
    int        state;
}			t_philos;

typedef struct s_table
{
	int nargc;
    int nb_of_philosophers; 
    int time_to_die; //en ms
    int time_to_eat; //en ms
    int time_to_sleep; // en ms
    int meals;
    unsigned long long init_time;
    t_philos *philos;
    pthread_mutex_t *forks;
    pthread_mutex_t fork;
    pthread_mutex_t write;
    pthread_mutex_t control;
    pthread_mutex_t messg;
    pthread_t  controller;
    int     actual;
}			t_table;

t_table *table;

int	ft_atoi_int(char *str);
int	ft_exit_error(void);
int ft_exit_ok(void);
unsigned long long ft_gettime_mill();
unsigned long long ft_gettime();
void    ft_usleep(int length);
void ft_msg(unsigned long long time, int act, char *str);
int ft_strlen(char *str);

int ft_parse(int argc, char **args);
void init_phylos(void);
void *ft_control(void *arg);
void *ft_routine(void *arg);
void ft_take_fork(int philo, int philo_prev);

# endif