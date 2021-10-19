#include "philo.h"

void	eating_or_sleeping(long time)
{
	long	start; //time_t
	long	stop;	//time_t

	start = get_time();
	stop = start + time; // get_time() + time
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
	if (phls->data->notepme_flag == 1)
	{
		phls->num_meals++;
		if (phls->num_meals >= phls->data->notepme)
			phls->does_not_eat = 1;
	}
	philo_sleeping(phls);
}

void	philo_takes_forks(t_philo *phls)
{
	pthread_mutex_lock(phls->l_fork);
	phls_msg(L_FORK_TAKEN, get_time() - phls->data->creation_time, \
				phls->id, phls->data->print_mutex);
	pthread_mutex_lock(phls->r_fork);
	phls_msg(L_FORK_TAKEN, get_time() - phls->data->creation_time, \
				phls->id, phls->data->print_mutex);
	philo_eating(phls);
}

void	*phls_life(void *phls)
{
	t_philo	*tmp;
//	int i = 5;

	tmp = (t_philo *)phls;
	tmp->last_meal = get_time(); // remove
	tmp->num_meals = 0;
	if (!(tmp->id % 2))			// maybe remove
		usleep(100); // 100?
	while (1)
	{
		philo_takes_forks(phls);
		phls_msg(THINKING, get_time() - tmp->data->creation_time, tmp->id, \
					tmp->data->print_mutex);
	}

//	ft_print(phls);
	return (NULL);
}