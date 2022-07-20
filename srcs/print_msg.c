/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:12:45 by cjimenez          #+#    #+#             */
/*   Updated: 2022/07/20 12:27:03 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_msg(t_env *env, const char *str)
{
    pthread_mutex_lock(env->params->forks);
    if (env->params->status == 0)
    {
        pthread_mutex_unlock(env->params->forks);
        return ;
    }
    printf("[\e[0;33m%lu ms\e[0m] Philo %d %s\n", timer(), env->id + 1, str);
    pthread_mutex_unlock(env->params->forks);
}