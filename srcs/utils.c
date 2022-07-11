/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:28:27 by cjimenez          #+#    #+#             */
/*   Updated: 2022/07/11 12:30:47 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	number;
	int	a;
	int	neg;

	neg = 1;
	a = 0;
	number = 0;
	while (nptr[a] == '\t' || nptr[a] == '\n' || nptr[a] == '\r'
		|| nptr[a] == '\v' || nptr[a] == '\f' || nptr[a] == ' ')
		a++;
	if (nptr[a] == '-' || nptr[a] == '+')
	{
		if (nptr[a] == '-')
			neg = -1;
		a++;
	}
	while (nptr[a] >= '0' && nptr[a] <= '9')
	{
		number = number * 10 + (nptr[a] - '0');
		a++;
	}
	return (number * neg);
}

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

static int  is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_strnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_digit(str[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_error(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}