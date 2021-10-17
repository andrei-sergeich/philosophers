#include "philo.h"

void ft_print(t_philo	*tmp, pthread_mutex_t	*mutex)
{
	pthread_mutex_lock(mutex);
	printf("phls[it].id - %d\t", tmp->id);
	printf("tm_die - %d\t", tmp->data->tm_die);
	printf("notepme - %d\n", tmp->data->notepme);
	pthread_mutex_unlock(mutex);
}

void	*phls_life(void *phls)
{
	t_philo	*tmp;

	tmp = (t_philo *)phls;
//	if (!(tmp->id % 2))
//		usleep(100);
//	pthread_mutex_lock(tmp->print_mutex);
//	pthread_mutex_lock(tmp->l_fork);
//	pthread_mutex_lock(tmp->r_fork);
//	pthread_mutex_lock(&glob_mutex);
	printf("phls[it].id - %d\t", tmp->id);
	printf("tm_die - %d\t", tmp->data->tm_die);
	printf("notepme - %d\n", tmp->data->notepme);
//	pthread_mutex_unlock(&glob_mutex);
//	pthread_mutex_unlock(tmp->print_mutex);
//	pthread_mutex_unlock(tmp->l_fork);
//	pthread_mutex_unlock(tmp->r_fork);
	ft_print(tmp, tmp->print_mutex);
	return (NULL);
}