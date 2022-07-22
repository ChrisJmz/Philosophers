/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:04:00 by cjimenez          #+#    #+#             */
/*   Updated: 2022/07/22 12:47:22 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destroy_mutex(t_env *env)
{
	free(env->params->forks);
	free(env->params->lock);
}

int	main(int ac, char **av)
{
	t_params	*params;
	t_env		*env;

	if (check_args (ac, av, 1) == 1)
		return (printf("Wrong parameters\n"), 1);
	params = malloc(sizeof(t_params));
	if (!params)
		return (1);
	if (ac == 5)
		env = init_philo(av, &params);
	else if (ac == 6)
		env = init_philo_5(av, &params);
	else
		return (free(params), ft_error("Wrong parameters\n"), 1);
	run(env);
	free(params);
	return (0);
}

void	run(t_env *env)
{
	int	i;

	i = 0;
	if (!env)
		return ;
	pexecute(env);
	if (env->params->nb_philo == 1)
	{
		free(env);
		return ;
	}
	while (i < env->params->nb_philo)
	{
		pthread_join(env[i].thread, NULL);
		i++;
	}
	destroy_mutex(env);
	if (env)
		free(env);
}
