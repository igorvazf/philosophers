/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvaz-fe <igvaz-fe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:29:19 by igvaz-fe          #+#    #+#             */
/*   Updated: 2022/03/17 23:08:50 by igvaz-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*only_one(t_philo *philo)
{
	pthread_mutex_lock(&philo->setup_philo->forks[philo->left_fork]);
	philo->last_meal = get_current_time();
	print_action(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->setup_philo->forks[philo->left_fork]);
	print_action(philo, "DIED");
	philo->setup_philo->is_died = 1;
	return (NULL);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->setup_philo->n_philos == 1)
		return (only_one(philo));
	return (NULL);
}

int	start_dinner(t_philo *philo)
{
	int	i;

	i = 0;
	philo->setup_philo->start_time = get_current_time();
	while (i < philo->setup_philo->n_philos)
	{
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < philo->setup_philo->n_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	return (0);
}
