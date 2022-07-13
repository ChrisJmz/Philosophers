/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:04:00 by cjimenez          #+#    #+#             */
/*   Updated: 2022/07/13 15:42:08 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
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
	{
		env = init_philo_5(av, &params);
		printf("%d", env->laps);
	}
	return (0);
}

// void	run(t_env *env)
// {
// 	int	i;

// 	i = 0;
// 	if i(!env)
// 		return ;
	
// }
