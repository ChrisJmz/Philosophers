/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:28:27 by cjimenez          #+#    #+#             */
/*   Updated: 2022/07/20 11:28:29 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	r;
	int			verif;

	r = 0;
	verif = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			verif = -verif;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (r * verif > 2147483647)
			return (-1);
		else if (r * verif < -2147483648)
			return (0);
		r = r * 10 + str[i] - 48;
		i++;
	}
	return (r * verif);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	is_digit(int c)
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
