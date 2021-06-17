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
	int					finish;
	unsigned long long	init_time;
	int					id;
	unsigned long long	last_meal;
	int					total_eats;
	sem_t				*forks;
	sem_t				*write;
	sem_t				*lock;
	pthread_t			controller;
}			t_table;

t_table	*g_table;
int					ft_atoi_int(char *str);
int					ft_exit_error(void);
int					ft_exit_ok(void);
unsigned long long	ft_gettime_mill(void);
unsigned long long	ft_gettime(void);
void				ft_usleep(int length);
void				ft_msg(unsigned long long time, int act, char *str);
int					ft_strlen(char *str);
int					ft_parse(int argc, char **args);
void				init_phylos(void);
void				*ft_control(void *arg);
int					ft_routine(void);
void				ft_take_fork(int philo);
pid_t				*ft_create_pid(pid_t *philo);
void				ft_create_waitpids(pid_t	*philo);
#endif
