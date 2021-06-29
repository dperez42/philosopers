#ifndef PHILOSOPHERS2_H
# define PHILOSOPHERS2_H
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

typedef struct s_philos
{
	int					id;
	pthread_t			philo;
	unsigned long long	last_meal;
	int					total_eats;
}			t_philos;

typedef struct s_table
{
	int					nargc;
	int					nb_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					meals;
	int					state;
	unsigned long long	init_time;
	t_philos			*philos;
	sem_t				*forks;
	sem_t				*write;
	sem_t				*lock;
	sem_t				*time;
	sem_t				*control;
}			t_table;

t_table					*g_table;
int						ft_atoi_int(char *str);
int						ft_exit_error(void);
int						ft_exit_ok(void);
unsigned long long		ft_gettime_mill(void);
unsigned long long		ft_gettime(void);
void					ft_msg(unsigned long long time, int act, char *str);
int						ft_strlen(char *str);
int						ft_parse(int argc, char **args);
void					init_phylos(void);
void					*ft_control(void *arg);
void					*ft_routine(void *arg);
void					ft_take_fork(int philo);
void					ft_release_fork(int philo);
void					ft_usleep(unsigned long long time, unsigned long long delay);
#endif
