/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvaz-fe <igvaz-fe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:43:04 by igvaz-fe          #+#    #+#             */
/*   Updated: 2022/03/15 22:04:53 by igvaz-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_setup(t_setup *setup, int argc, char *argv[])
{
	setup->n_philos = ft_atoi(argv[1]);
	if (setup->n_philos < 1)
	{
		printf("Error: Need at least one philosopher.\n");
		exit(0);
	}
	setup->time_to_die = ft_atoi(argv[2]);
	setup->time_to_eat = ft_atoi(argv[3]);
	setup->time_to_sleep = ft_atoi(argv[4]);
	setup->times_to_eat = 0;
	if (argc > 5)
		setup->times_to_eat = ft_atoi(argv[5]);
}

int	main(int argc, char *argv[])
{
	t_setup	setup;

	if (argc < 5 || argc > 6)
	{
		printf("Invalid syntax!\n");
		exit(1);
	}
	init_setup(&setup, argc, argv);
	return (0);
}
