#include "../include/philo.h"

int	satiety_checker(t_philo *phls)
{
	int	it;
	int	full_satiety;

	it = 0;
	full_satiety = 0;
	while (it < phls->data->num_phls)
	{
		full_satiety += phls[it].satiety;
		it++;
	}
	if (full_satiety >= phls->data->num_phls)
		return (1);
	return (0);
}

void	*life_checker(void *phls_void)
{
	int		it;
	t_philo	*phls;

	it = 0;
	phls = (t_philo *)phls_void;
	while (1)
	{
		if (it >= phls[0].data->num_phls)
			it = 0;
		if (phls[0].data->notepme > 0)
		{
			if (satiety_checker(phls) == 1)
				return (NULL);
		}
		if ((get_time() - phls[it].last_meal) > phls[it].data->tm_die)
		{
			phls_msg(DIED, get_time() - phls[it].data->creation_time, \
						phls[it].id, phls[0].data->print_mutex);
			return ((void *) 1);
		}
		it++;
		usleep(100);
	}
	return (NULL);
}

int	philo_checker(t_philo *phls)
{
	pthread_t	checker;

	if (pthread_create(&checker, NULL, life_checker, (void *)phls) != 0)
		return (err_msg(PTHREAD_ERROR));
	if (pthread_join(checker, NULL) != 0)
		return (err_msg(PTHREAD_ERROR));
	return (0);
}
