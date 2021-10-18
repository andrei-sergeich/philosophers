#include "philo.h"

int	create_threads(t_philo *phls, t_data *data)
{
	pthread_t	*ph_th;
	int			it;

	data->time = get_time();
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
		if (pthread_join(ph_th[it], NULL) != 0) /* was detach */
			return (err_msg(PTHREAD_ERROR));
		it++;
	}

//	printf("%ld\n", data->time);
	return (0);
}

int	philosophers(t_data *data)
{
	t_philo			*phls;
	pthread_mutex_t	*fork;
	int				it;

	phls = (t_philo *)malloc(sizeof(t_philo) * data->num_phls);
	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->num_phls);
	data->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
//	phls->print_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
//	pthread_mutex_init(phls->print_mutex, NULL);
	pthread_mutex_init(data->mutex, NULL);
	it = 0;
	while (it < data->num_phls)
	{
		phls[it].id = it + 1;
		pthread_mutex_init(&fork[it], NULL);
//		pthread_mutex_init(data->mutex, NULL);
//		pthread_mutex_init(phls->print_mutex, NULL);
		phls[it].l_fork = &fork[it];
		phls[it].r_fork = &fork[(it + 1) % data->num_phls];
		phls[it].data = data;
		if (data->notepme_flag == 1)
			phls[it].num_meals = 0;
		it++;
	}
//	it = 0;
//	while (it < data->num_phls)
//	{
//		phls[it].data->notepme++;
//		printf("phls[it].id - %d\t", phls[it].id);
//		printf("tm_die - %d\t", phls[it].data->tm_die);
//		printf("notepme - %d\n", phls[it].data->notepme);
//		it++;
//	}
//	printf("notepme - %d\n", phls[0].data->notepme);

	if (create_threads(phls, data) != 0)
		return (1);
//	free(fork);
//	free(data->mutex);
	free(phls);
	return (0);
}
