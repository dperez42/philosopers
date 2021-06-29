#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philos
{
	int					id;
	pthread_t			philo;
	//pthread_t			controller;
	unsigned long long	last_meal;
	int					total_eats;
	int					fork_left;
	int					fork_right;
}			t_philos;

typedef struct s_table
{
	int					nargc;
	int					nb_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					max_meals;
	int					flag;
	unsigned long long	init_time;
	int					finish_phi;
	int					finish_time;
	unsigned long long	die_time;
	pthread_t			controller;
	t_philos			*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		fork;
	pthread_mutex_t		messg;
	pthread_mutex_t		time;
	
}			t_table;

t_table				*g_table;
int					ft_atoi_int(char *str);
int					ft_exit_error(void);
int					ft_exit_ok(void);
unsigned long long	ft_gettime_mill(void);
unsigned long long	ft_gettime(void);
void				ft_msg(unsigned long long time, int act, char *str);
int					ft_strlen(char *str);
int					ft_parse(int argc, char **args);
void				init_phylos(void);
void				*ft_control(void *arg);
void				*ft_routine(void *arg);
void				ft_take_fork(int philo);
void				ft_release_fork(int philo);
#endif
