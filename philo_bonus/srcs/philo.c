#include "../include/philo_bonus.h"

//void	philo_destroyer(t_philo *phls, t_data *data)
//{
//	int	it;
//
//	pthread_mutex_destroy(data->print_sem);
//	it = 0;
//	while (it < data->num_phls)
//	{
//		pthread_mutex_destroy(phls[it].fork);
////		pthread_mutex_destroy(phls[it].r_fork);
//		it++;
//	}
//}
//
//int	philo_creator(t_philo *phls, t_data *data)
//{
//	pthread_t	*ph_th;
//	int			it;
//
//	data->creation_time = get_time();
//	ph_th = malloc(sizeof(pthread_t) * data->num_phls);
//	it = 0;
//	while (it < data->num_phls)
//	{
//		if (pthread_create(&ph_th[it], NULL, phls_life, (void *)&phls[it]) != 0)
//			return (err_msg(PTHREAD_ERROR));
//		it++;
//	}
//	it = 0;
//	while (it < data->num_phls)
//	{
//		if (pthread_detach(ph_th[it]) != 0)
//			return (err_msg(PTHREAD_ERROR));
//		it++;
//	}
//	if (philo_checker(phls) != 0)
//		return (1);
//	philo_destroyer(phls, data);
//	free(ph_th);
//	return (0);
//}

void	sem_opener(t_data *data)
{
	if (sem_unlink("print_sem") == -1)
		exit(1);
	if (sem_unlink("fork"))
		exit(1);
//	sem_unlink("print_sem");
//	sem_unlink("fork");
	data->print_sem = sem_open("print_sem", O_CREAT, 0644, 1);
	data->fork = sem_open("fork", O_CREAT, 0644, data->num_phls);
	if (data->print_sem == 0 || data->fork == 0)
		exit(1);
}

void	sem_closer(t_data *data)
{
	if (sem_close(data->print_sem))
		exit(1);
//	if (sem_unlink("print_sem") == -1)
//		exit(1);
	if (sem_close(data->fork))
		exit(1);
//	if (sem_unlink("fork"))
//		exit(1);
}

int	philosophers(t_data *data)
{
	t_philo	*phls;
	int		it;


	it = 0;
	phls = (t_philo *)malloc(sizeof(t_philo) * data->num_phls);
	sem_opener(data);
	data->creation_time = get_time();
	while (it < data->num_phls)
	{
		phls[it].pid = fork();
		if (phls[it].pid == -1)
			return (err_msg(FORK_ERROR));
		if (phls[it].pid == 0)
		{
			phls[it].id = it + 1;
			phls[it].data = data;
			if (data->notepme > 0)
			{
				phls[it].num_meals = 0;
				phls[it].satiety = 0;
			}
			phls_life((void *)&phls[it]);
//			exit(0);
		}
//		if (data->num_phls % 2)
//			usleep(100);
		it++;
	}
//	if (philo_creator(phls, data) != 0)
//		return (1);
	it = 0;
	waitpid(-1, NULL, 0);
	while (it < data->num_phls)
	{
		kill(phls[it].pid, SIGKILL);
		it++;
	}
	sem_closer(data);
	free(phls);
	return (0);
}
