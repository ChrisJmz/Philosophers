/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:04:00 by cjimenez          #+#    #+#             */
/*   Updated: 2022/07/12 16:03:29 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_params	*params;

	if (check_args (ac, av, 1) == 1)
		return (printf("Wrongs parameters\n"), 1);
	params = malloc(sizeof(t_params));
	if (!params)
		return (1);
	init_philo(av, &params);

	return (0);
}

void	run(t_env *env)
{
	int	i;

	i = 0;
	if i(!env)
		return ;
	
}
