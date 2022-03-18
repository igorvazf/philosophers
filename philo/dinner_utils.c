/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvaz-fe <igvaz-fe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:42:22 by igvaz-fe          #+#    #+#             */
/*   Updated: 2022/03/17 22:09:19 by igvaz-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *action)
{
	long	current_time;

	current_time = elapsed_time(philo->setup_philo->start_time);
	pthread_mutex_lock(&philo->setup_philo->print_locker);
	if (!philo->setup_philo->is_died)
		printf("%5ld %3d %s\n", current_time, philo->philo_id, action);
	pthread_mutex_unlock(&philo->setup_philo->print_locker);
}
