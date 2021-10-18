#include "philo.h"

void	ft_print(t_philo *tmp)
{
	pthread_mutex_lock(tmp->print_mutex);
	printf("phls[it].id - %d\t", tmp->id);
	printf("tm_die - %d\t", tmp->data->tm_die);
	printf("notepme - %d\n", tmp->data->notepme);
	pthread_mutex_unlock(tmp->print_mutex);
}

void	*phls_life(void *phls)
{
	t_philo	*tmp;

	tmp = (t_philo *)phls;
//	if (!(tmp->id % 2))
//		usleep(100);
	pthread_mutex_lock(tmp->data->mutex);
	printf("phls[it].id - %d\t", tmp->id);
	printf("tm_die - %d\t", tmp->data->tm_die);
	printf("notepme - %d\n", tmp->data->notepme);
	pthread_mutex_unlock(tmp->data->mutex);
//	ft_print(tmp);
	return (NULL);
}