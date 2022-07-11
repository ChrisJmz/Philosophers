/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:21:35 by cjimenez          #+#    #+#             */
/*   Updated: 2022/07/11 14:41:20 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_max(char *av)
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

int    check_args(char **av, int i)
{
    while (av[i])
    {
        if (is_strnum(av[i]) == 0 || check_max(av[i]) == 1)
            return (printf("Error\n"), 1);
        i++;
    }
    return (0);
}


void    init_arg(int ac, char **av, t_env *env)
{
    if (ac < 5)
    {
        printf("Error\n");
        exit (ERROR);
    }
    else if (check_args(av, 1) == 0)
    {
        env->nb_philo = ft_atoi(av[1]);
        env->tt_die = ft_atoi(av[2]);
        env->tt_eat = ft_atoi(av[3]);
        env->tt_sleep = ft_atoi(av[4]);
        env->must_eat = -1;
        env->is_running = true;
        if (ac == 6)
            env->must_eat = ft_atoi(av[5]);
    }
}