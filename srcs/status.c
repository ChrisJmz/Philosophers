/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:34:15 by cjimenez          #+#    #+#             */
/*   Updated: 2022/07/19 13:11:56 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    sleeping(t_env *env)
{
    print_msg(env, "is sleeping");
    ft_usleep(env->params->tt_sleep, env);
}

void    thinking(t_env *env)
{
    print_msg(env, "is thinking");
}

int   eating(t_env *env)
{
    if (take_fork(env) == 1)
        return (1);
    print_msg(env, "is eating");
    pthread_mutex_lock(env->params->forks);
    env->last_eat = timer();
    pthread_mutex_unlock(env->params->forks);
    ft_usleep(env->params->tt_eat, env);
    pthread_mutex_lock(env->params->forks);
    env->laps_done++;
    pthread_mutex_unlock(env->params->forks);
    pthread_mutex_unlock(env->left_fork);
    pthread_mutex_unlock(&env->right_fork);
    return (0);
}

void    dead(t_env *env)
{
    pthread_mutex_lock(&env->lock);
    printf("%lu philo %d died\n", timer(), env->id);
    env->params->status = 0;
    pthread_mutex_unlock(&env->lock);
}

int take_fork(t_env *env)
{
    if (env->id % 2 == 0)
        pthread_mutex_lock(&env->right_fork);
    else
        pthread_mutex_lock(env->left_fork);
    print_msg(env, "has taken a fork");
    if (env->id % 2 == 0)
    {
        if (pthread_mutex_lock(env->left_fork))
        {
            pthread_mutex_unlock(&env->right_fork);
            return (1);
        }
        print_msg(env, "has taken a fork");
    }
    else
    {
        if (pthread_mutex_lock(&env->right_fork))
        {
            pthread_mutex_unlock(env->left_fork);
            return (1);
        }
        print_msg(env, "has taken a fork");
    }
    return (0);
}

