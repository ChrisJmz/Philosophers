/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:14:42 by cjimenez          #+#    #+#             */
/*   Updated: 2022/07/14 15:28:32 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long unsigned int   timer(void)
{
    static long         start = 0;
    long unsigned int   time;
    struct timeval      tv;

    if (start == 0)
    {
        gettimeofday(&tv, NULL);
        start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
        time = 0;
    }
    else
    {
        gettimeofday(&tv, NULL);
        time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) - start;
    }
    return (time);
}