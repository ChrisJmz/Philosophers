/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:23:14 by cjimenez          #+#    #+#             */
/*   Updated: 2022/07/11 14:43:27 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <inttypes.h>
# include <stdlib.h>

# define ERROR 42

typedef struct s_env t_env;

// typedef struct s_status
// {
//     THINKING;
//     EATING;
//     SLEEPING;
//     TOOK_FORK;
//     DEAD;
// }   t_status;

typedef struct s_philo
{
    int         id;
    int         left;
    int         right;
    int         eat_count;
    bool        done;
    uint64_t    last_eat;
    pthread_t   thread;
    t_env       *env;
}   t_philo;

typedef struct s_env
{
    int             nb_philo;
    int             tt_die;
    int             tt_eat;
    int             tt_sleep;
    int             must_eat;
    int             count_done;
    bool            is_running;
    t_philo         *philos;
    pthread_mutex_t *forks;
    pthread_mutex_t write;
}   t_env;

//  inits
void    init_arg(int ac, char **av, t_env *env);

//  utils
int     ft_atoi(const char *nptr);
int     ft_strlen(const char *str);
int     is_strnum(char *str);
void    ft_error(char *str);

#endif
