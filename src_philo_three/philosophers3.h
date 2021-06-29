#ifndef PHILOSOPHERS3_H
# define PHILOSOPHERS3_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/types.h>

# define  DIED  3
# define  FULL  2

typedef struct s_table
{
	int					nargc;
	int					nb_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					meals;
	unsigned long long	init_time;
	pid_t				*philo;
	int					id;
	unsigned long long	last_meal;
	int					total_eats;
	int					stop;
	int					is_eating;
	sem_t				*fork;
	sem_t				*forks;
	sem_t				*write;
	sem_t				*timeA;
	sem_t				*time;
	sem_t				*end;
	sem_t				*nb_meal;
	pthread_t			controller;
	pthread_t			thread_end;
	
}			t_table;

//t_table	*g_table;
int					ft_atoi_int(char *str);
int					ft_exit_error(void);
int					ft_exit_ok(t_table *table, int ex);
int					ft_exit_ok_meals(int ex);
int					ft_exit_child_ok(int ex);
unsigned long long	ft_gettime_mill(void);
unsigned long long	ft_gettime(t_table *table);
unsigned long long	ft_gettime_father(t_table *table);
void				ft_msg(t_table *table, unsigned long long time, int act, char *str);
int					ft_strlen(char *str);
void				ft_usleep(unsigned long long time, unsigned long long delay);
int					ft_parse(t_table *table, int argc, char **args);
void				init_phylos(void);
void				*ft_control(void *arg);
int					ft_routine(t_table *table);
void				ft_take_fork(t_table *table);
void				ft_release_fork(t_table *table);
int					ft_create_pid(t_table *table);
void				ft_create_waitpids(pid_t	*philo);
void				*full_meals(void *args);
#endif
