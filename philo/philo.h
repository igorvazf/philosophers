/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvaz-fe <igvaz-fe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:54:55 by igvaz-fe          #+#    #+#             */
/*   Updated: 2022/03/20 21:56:27 by igvaz-fe         ###   ########.fr       */
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
	pthread_mutex_t	*forks;
	int				is_died;
	int				n_philos;
	long			start_time;
	int				time_to_die;
	int				time_to_eat;
	int				times_to_eat;
	pthread_mutex_t	print_locker;
	int				time_to_sleep;
}	t_setup;

typedef struct s_philo
{
	int			n_meals;
	int			philo_id;
	long		last_meal;
	int			left_fork;
	int			right_fork;
	pthread_t	thread;
	t_setup		*setup_philo;
}	t_philo;

int		ft_isdigit(int i);
void	eating(t_philo *philo);
long	get_time(void);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
int		check_meals(t_philo *philo);
int		start_dinner(t_philo *philo);
void	print_action(t_philo *philo, char *action);

#endif
