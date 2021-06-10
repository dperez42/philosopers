#include "philosophers3.h"

//Get actual time
unsigned long long ft_gettime_mill()
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

//Get time from start
unsigned long long ft_gettime()
{
    return (ft_gettime_mill() - table->init_time);
}
