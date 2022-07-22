/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:33:05 by cjimenez          #+#    #+#             */
/*   Updated: 2022/07/22 12:46:19 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_max(char *av)
{
	if (ft_strlen(av) > 11)
		return (1);
	if (av[0] == '-')
	{
		if (ft_atoi(av) > 0)
			return (1);
	}
	else
	{
		if (ft_atoi(av) < 0)
			return (1);
	}
	return (0);
}

int	check_args(int ac, char **av, int i)
{
	if (ac < 5)
		return (1);
	else if (ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > 200
		|| ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
		return (1);
	while (av[i])
	{
		if (is_strnum(av[i]) == 0 || check_max(av[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
