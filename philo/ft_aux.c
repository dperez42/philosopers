/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:57:26 by daniel            #+#    #+#             */
/*   Updated: 2021/06/17 13:33:27 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (0);
	return (1);
}

int	ft_is_integer(char *str)
{
	int	i;
	int	flsig;
	int	flnb;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_max_min_int(unsigned long long int	result, int	sign)
{
	if ((result > 2147483647) && sign >= 0)
		return (1);
	if ((result > 2147483648) && sign < 0)
		return (1);
	return (0);
}

int	ft_atoi_int(char *str)
{
	int						sign;
	unsigned long long int	result;

	if (ft_is_integer(str))
		ft_exit_error();
	sign = 1;
	result = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	if (*str == '\0' || sign < 0)
		ft_exit_error();
	while (!ft_isdigit(*str) && *str)
	{
		result = result * 10 + *str - '0';
		str++;
		if (ft_max_min_int(result, sign))
			ft_exit_error();
	}
	return (sign * result);
}
