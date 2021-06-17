 #include "philosophers.h"

unsigned long long ft_gettime_mill()
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

unsigned long long ft_gettime()
{
    return (ft_gettime_mill() - g_table->init_time);
}
