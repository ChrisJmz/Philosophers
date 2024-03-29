/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:23:14 by cjimenez          #+#    #+#             */
/*   Updated: 2022/07/19 15:24:47 by cjimenez         ###   ########.fr       */
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

typedef struct s_params
{
    int             nb_philo;
    int             tt_die;
    int             tt_eat;
    int             tt_sleep;
    int             status;
    long long       time_start;
    int             finish;
    pthread_mutex_t *forks;
    pthread_mutex_t *lock;
}   t_params;

typedef struct s_env
{
    pthread_t       thread;
    t_params        *params;
    int             id;
    long long int   last_meal;
    int             laps;
    int             status;
    int             laps_done;
    pthread_mutex_t *left_fork;
    pthread_mutex_t right_fork;
    pthread_mutex_t lock;
}   t_env;

//  inits
void    init_arg(char **av, t_params *params);
int     init_mutex(t_env *env);
t_env   *init_philo(char **av, t_params **params);
t_env   *init_philo_5(char **av, t_params **params);
void    init_philo_1(t_env *env);

//  utils
int                 ft_atoi(const char *nptr);
int                 ft_strlen(const char *str);
int                 is_strnum(char *str);
void                ft_error(char *str);
long unsigned int   timer(void);
void                print_msg(t_env *env, const char *str);
void                destroy_mutex(t_env *env);
void                ft_usleep(long unsigned int ms, t_env *env);
int                 philo_status(t_env *env);

// args check
int     check_max(char *av);
int    check_args(int ac, char **av, int i);

// philo status
void    sleeping(t_env *env);
void    thinking(t_env *env);
int     eating(t_env *env);
int     take_fork(t_env *env);
void    dead(t_env *env);

// execute philo
void    pexecute(t_env *env);
void	run(t_env *env);
#endif
