/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:56:47 by cjimenez          #+#    #+#             */
/*   Updated: 2022/07/18 15:48:39 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int  pdead(t_env *env)
{
    if ((timer() - env->last_eat) >= (unsigned long)env->params->tt_die)
    {
       dead(env);
       pthread_mutex_unlock(env->params->forks);
       return (1); 
    }
    return (0);
}

static void checking_forks(t_env *env, int ate, int i)
{
    while (1)
    {
        i = -1;
        ate = 0;
        while (++i < env->params->nb_philo)
        {
            pthread_mutex_lock(env[i].params->forks);
            if (env[i].laps_done == env[i].laps)
            {
                ++ate;
                if (ate == env->params->nb_philo)
                {
                    if (pdead(&env[i]))
                        return ;
                    pthread_mutex_unlock(env[i].params->forks);
                    return ;
                }
                if (pdead(&env[i]))
                    return ;
                pthread_mutex_unlock(env[i].params->forks);
            }
            usleep(200);
        }
    }
}

int philo_status(t_env *env)
{
    pthread_mutex_lock(env->params->forks);
    if (env->params->status != 1)
    {
        pthread_mutex_unlock(env->params->forks);
        return (0);
    }
    pthread_mutex_unlock(env->params->forks);
    return (1);
}

void    *act(void   *philo)
{
    t_env       *env;

    env = philo;
    while (philo_status(env) == 1)
    {
        if (env->laps_done == env->laps)
            return (NULL);
        eating(env);
        if (philo_status(env) != 1)
            return (NULL);
        sleeping(env);
        if (philo_status(env) != 1)
            return (NULL);
        thinking(env);
        if (philo_status(env) != 1)
            return (NULL);
        usleep(200);
    }
    return (NULL);
}

void    pexecute(t_env *env)
{
    int i;

    i = -1;
    env->params->time_start = timer();
    if (init_mutex(env) == 1)
        return ;
    if (env->params->nb_philo == 1)
        return (init_philo_1(env));
    while (++i < env->params->nb_philo)
    {
        if (i % 2 == 0)
            if ((pthread_create(&(env[i].thread), NULL, act, &env[i])))
                return ;
    }
    ft_usleep(10, env);
    i = -1;
    while (i++ < env->params->nb_philo)
    {
        if (i % 2 == 1)
            if ((pthread_create(&(env[i].thread), NULL, act, &env[i])))
                return ;            
    }
    checking_forks(env, 0, 0);
}