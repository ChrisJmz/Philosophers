/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:04:00 by cjimenez          #+#    #+#             */
/*   Updated: 2022/06/27 15:43:52 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	if (ac > 1)
		if (is_strnum(av[1]) == 1)
			printf("oui");
		else
			printf("non");
	else
		return (1);
	return (0);
}
