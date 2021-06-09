#include "philosophers3.h"

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
    write(1," ", 1);
    ft_putnbr(philo);
    write(1, str, ft_strlen(str));
    //write(1,"\n",1);
    //ft_putnbr(getpid());
    //write(1," xx ",4);
    //ft_putnbr(getppid());
    //write(1,"\n",1);
    //write(1," total comidas: ",16);
    //ft_putnbr(table->total_eats);
    //write(1," xxx ",5);
    sem_post(table->write);

    return ;
}