/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvaz-fe <igvaz-fe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:54:55 by igvaz-fe          #+#    #+#             */
/*   Updated: 2022/03/16 22:56:52 by igvaz-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define MAX_INT	2147483647

typedef struct s_setup
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
	int				is_died;
	long			start_time;
	pthread_mutex_t	*forks;
}	t_setup;

typedef struct s_philo
{
	int		philo_id;
	int		n_meals;
	long	last_meal;
	int		left_fork;
	int		right_fork;
	t_setup	*setup_philo;
}	t_philo;

int		ft_isdigit(int i);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
long	get_current_time(void);

#endif
