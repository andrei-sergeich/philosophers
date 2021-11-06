#include "../include/philo.h"

void	mutex_destroyer(t_philo *phls, t_data *data)
{
	int	it;

	pthread_mutex_destroy(data->print_mutex);
	it = 0;
	while (it < data->num_phls)
	{
		pthread_mutex_destroy(phls[it].l_fork);
		it++;
	}
}

void	philo_creator(t_philo *phls, t_data *data, pthread_mutex_t *fork)
{
	int	it;

	it = 0;
	while (it < data->num_phls)
	{
		pthread_mutex_init(&fork[it], NULL);
		phls[it].id = it + 1;
		phls[it].l_fork = &fork[it];
		phls[it].r_fork = &fork[(it + 1) % data->num_phls];
		phls[it].data = data;
		if (data->notepme > 0)
		{
			phls[it].num_meals = 0;
			phls[it].satiety = 0;
		}
		it++;
	}
}

int	philo_starter(t_philo *phls, t_data *data)
{
	pthread_t	*ph_th;
	int			it;

	data->creation_time = get_time();
	ph_th = malloc(sizeof(pthread_t) * data->num_phls);
	it = 0;
	while (it < data->num_phls)
	{
		if (pthread_create(&ph_th[it], NULL, phls_life, (void *)&phls[it]) != 0)
			return (err_msg(PTHREAD_ERROR));
		it++;
	}
	it = 0;
	while (it < data->num_phls)
	{
		if (pthread_detach(ph_th[it]) != 0)
			return (err_msg(PTHREAD_ERROR));
		it++;
	}
//	life_checker((void *)phls);
	if (philo_checker(phls) != 0)
		return (1);
	mutex_destroyer(phls, data);
	free(ph_th);
	return (0);
}

int	philosophers(t_data *data)
{
	t_philo			*phls;
	pthread_mutex_t	*fork;

	phls = (t_philo *)malloc(sizeof(t_philo) * data->num_phls);
	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
			data->num_phls);
	data->print_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!phls || !fork || !data->print_mutex)
		return (err_msg(MALLOC_ERROR));
	pthread_mutex_init(data->print_mutex, NULL);
	philo_creator(phls, data, fork);
	if (philo_starter(phls, data) != 0)
		return (1);
	free(fork);
	free(data->print_mutex);
	free(phls);
	return (0);
}
