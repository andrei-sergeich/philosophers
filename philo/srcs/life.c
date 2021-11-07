/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:42:16 by cmero             #+#    #+#             */
/*   Updated: 2021/11/07 12:42:17 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eating_or_sleeping(long time)
{
	long	start;
	long	stop;

	start = get_time();
	stop = start + time;
	while (stop > start)
	{
		usleep(50);
		start = get_time();
	}
}

void	philo_sleeping(t_philo *phls)
{
	phls_msg(SLEEPING, get_time() - phls->data->creation_time, \
				phls->id, phls->data->print_mutex);
	eating_or_sleeping(phls->data->tm_sleep);
}

void	philo_eating(t_philo *phls)
{
	phls_msg(EATING, get_time() - phls->data->creation_time, \
				phls->id, phls->data->print_mutex);
	phls->last_meal = get_time();
	eating_or_sleeping(phls->data->tm_eat);
	pthread_mutex_unlock(phls->l_fork);
	pthread_mutex_unlock(phls->r_fork);
	if (phls->data->notepme > 0)
	{
		phls->num_meals++;
		if (phls->num_meals >= phls->data->notepme)
			phls->satiety = 1;
	}
}

void	philo_takes_forks(t_philo *phls)
{
	pthread_mutex_lock(phls->l_fork);
	phls_msg(L_FORK_TAKEN, get_time() - phls->data->creation_time, \
				phls->id, phls->data->print_mutex);
	pthread_mutex_lock(phls->r_fork);
	phls_msg(R_FORK_TAKEN, get_time() - phls->data->creation_time, \
				phls->id, phls->data->print_mutex);
}

void	*phls_life(void *phls_void)
{
	t_philo	*phls;

	phls = (t_philo *)phls_void;
	phls->last_meal = get_time();
	phls->num_meals = 0;
	if (!(phls->id % 2))
		usleep(100);
	while (1)
	{
		philo_takes_forks(phls);
		philo_eating(phls);
		philo_sleeping(phls);
		phls_msg(THINKING, get_time() - phls->data->creation_time, phls->id, \
					phls->data->print_mutex);
	}
	return (NULL);
}
