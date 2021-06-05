 #include "philosophers2.h"

unsigned long long ft_gettime_mill()
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

unsigned long long ft_gettime()
{
    //printf("ac %llu \nin %llu \n", ft_gettime_mill(), table->init_time);
    return (ft_gettime_mill() - table->init_time);
}
