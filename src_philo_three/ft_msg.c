#include "philosophers.h"

void ft_putnbr(unsigned long int nb)
{
    char c;

    if (nb < 10)
    {
        c = nb + '0';
        write(1, &c, 1);
    }
    else
    {
        ft_putnbr(nb/10);
        ft_putnbr(nb%10);
    }
}

void ft_msg(unsigned long long time, int philo, char *str)
{
    sem_wait(table->write);
    ft_putnbr(time);
    write(1," ",1);
    ft_putnbr(philo);
    write(1, str, ft_strlen(str));
    sem_post(table->write);
    return ;
}