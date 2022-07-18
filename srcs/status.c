/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:34:15 by cjimenez          #+#    #+#             */
/*   Updated: 2022/07/18 12:41:31 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    sleeping(t_env *env)
{
    print_msg(env, "is sleeping");
    usleep(env->params->tt_sleep * 1000);
}

void    thinking(t_env *env)
{
    print_msg(env, "is thinking");
}


