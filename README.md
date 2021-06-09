# philosopers

Introduction to the basics of process threading, and how work on the same memory space. And learn about mutexes, semaphores, and shared memory. 

usage :

./philo_one number_philosopher time_to_die time_to_eat time_to_sleep [number_of_time_each_philosophers_must_eat] arguments in square brackets are not required (number_of_time_each_philosophers_must_eat)

example :

./philo_one 4 500 200 200
 
options:

◦ number_of_philosophers: is the number of philosophers and also the number of forks

◦ time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after starting his last meal or the beginning of the simulation, it dies

◦ time_to_eat: is in milliseconds and is the time it takes for a philosopher to eat. During that time he will need to keep the two forks.

◦ time_to_sleep: is in milliseconds and is the time the philosopher will spend sleeping.

◦ number_of_times_each_philosopher_must_eat: argument is optional, if all philosophers eat at least 'number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.

## philo_one

philosopher with threads and mutex

FUNCTIONS

memset, printf, malloc, free, write,usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init,pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock

RULES

• One fork between each philosopher, therefore there will be a fork at the right and at the left of each philosopher.

• To avoid philosophers duplicating forks, you should protect the forks state with a mutex for each of them.

• Each philosopher should be a thread.

## philo_two

philosopher with threads and semaphore

FUNCTIONS

memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, sem_open, sem_close, sem_post, sem_wait, sem_unlink

RULES

• All the forks are in the middle of the table.

• They have no states in memory but the number of available forks is represented by a semaphore.

• Each philosopher should be a thread.

## philo_three

philosopher with processes and semaphore

FUNCTIONS

memset, printf, malloc, free, write, fork, kill, exit, pthread_create, pthread_detach, pthread_join, usleep, gettimeofday, waitpid, sem_open, sem_close, sem_post, sem_wait, sem_unlink

RULES

• All the forks are in the middle of the table.

• They have no states in memory but the number of available forks is represented by a semaphore.

• Each philosopher should be a process and the main process should not be a philoso- pher.


WhileTrueThenDream. fork(). Parte I: ,Creación de un nuevo proceso, hijos, padres, zombies y huérfanos https://www.youtube.com/watch?v=VwjP-KFuZCM
WhileTrueThenDream. fork(). Parte II. wait, fork , exit status, múltiples hijos https://www.youtube.com/watch?v=Dt9z_ohQWHI
Use ommand "ps lf" (show process herarchy)
