#include "../include/philo_bonus.h"

void	philo_destroyer(t_philo *phls, t_data *data)
{
	int	it;

	pthread_mutex_destroy(data->print_mutex);
	it = 0;
	while (it < data->num_phls)
	{
		pthread_mutex_destroy(phls[it].l_fork);
//		pthread_mutex_destroy(phls[it].r_fork);
		it++;
	}
}

int	philo_creator(t_philo *phls, t_data *data)
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
	if (philo_checker(phls) != 0)
		return (1);
	philo_destroyer(phls, data);
	free(ph_th);
	return (0);
}

int	philosophers(t_data *data)
{
	t_philo	*phls;
	int		it;
	int		pid;

	it = 0;
	phls = (t_philo *)malloc(sizeof(t_philo) * data->num_phls);
	sem_opener(data);
	data->creation_time = get_time();
	while (it < data->num_phls)
	{
		pid = fork();
		if (pid == -1)
			return (err_msg(FORK_ERROR));
//		phls[it] = (malloc(sizeof(t_philo) * data->num_phls));
		phls[it].pid = pid;
		if (pid == 0)
		{
			phls[it].id = it + 1;
			phls[it].fork = data->fork;
			phls[it].data = data;
			if (data->notepme_flag == 1)
				phls[it].num_meals = 0;
			phls_life((void *)&phls[it]);
			exit(0);
		}
		it++;
	}
	if (philo_creator(phls, data) != 0)
		return (1);
//	free(fork);
//	free(data->print_mutex);
	free(phls);
	return (0);
}
