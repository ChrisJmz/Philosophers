/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:21:35 by cjimenez          #+#    #+#             */
/*   Updated: 2022/07/12 15:56:59 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_arg(char **av, t_params *params)
{
    params->nb_philo = ft_atoi(av[1]);
    params->tt_die = ft_atoi(av[2]);
    params->tt_eat = ft_atoi(av[3]);
    params->tt_sleep = ft_atoi(av[4]);
    params->status = 1;
    params->finish = 0;
}

void    init_mutex(t_env *env)
{
    env->params->forks = malloc(sizeof(pthread_mutex_t));
    if (!env->params->forks)
        return ;
    env->params->lock = malloc(sizeof(pthread_mutex_t));
    if (!env->params->lock)
        return ;
    pthread_mutex_init(env->params->forks, NULL);
    pthread_mutex_init(env->params->lock, NULL);
}

t_env *init_philo(char **av, t_params **params)
{
    t_env   *env;
    int i;
    
    i = -1;
    init_arg(av, *params);
    env = malloc(sizeof(t_env) * (ft_atoi(av[1])));
    if (!env)
        return (0);
    while (++i < ft_atoi(av[1]))
    {
        env[i].params = *params;
        env[i].id = i;
        env[i].laps = -1;
        env[i].laps_done = 0;
        env[i].last_eat = 0;
        env[i].status = 1;
        pthread_mutex_init(&env[i].right_fork, NULL);
        pthread_mutex_init(&env[i].lock, NULL);
        env[(i + 1) % env->params->nb_philo].left_fork
            = &env[i].right_fork;
    }
    return (env);
}

// void    loop_philo(t_env *env)
// {
//     int i;
// }

