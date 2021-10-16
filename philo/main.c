#include "philo.h"

int	argv_processing(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (err_msg(WRONG_COUNT_OF_ARGUMENTS));
	data->num_phls = ft_atoi(argv[1]);
	data->tm_die = ft_atoi(argv[2]);
	data->tm_eat = ft_atoi(argv[3]);
	data->tm_sleep = ft_atoi(argv[4]);
	data->notepme = 0;
	if (data->num_phls < 1 || data->tm_die < 1 || data->tm_eat < 1 \
		|| data->tm_sleep < 1)
		return (err_msg(WRONG_ARGUMENT));
	if (argc == 6)
	{
		data->notepme = ft_atoi(argv[5]);
		if (data->notepme < 1)
			return (err_msg(WRONG_ARGUMENT));
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*phls;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (err_msg(MALLOC_ERROR));
	if (argv_processing(data, argc, argv) != 0)
	{
		free(data);
		return (1);
	}
	phls = (t_philo *)malloc(sizeof(t_philo) * data->num_phls);
	if (!phls)
		return (err_msg(MALLOC_ERROR));
	if (philosophers(phls, data) != 0)
	{
		free(data);
		free(phls);
		return (1);
	}
//	printf("num_phls - %d\n", data->num_phls);
//	printf("tm_die - %d\n", data->tm_die);
//	printf("tm_eat - %d\n", data->tm_eat);
//	printf("tm_sleep - %d\n", data->tm_sleep);
//	printf("notepme - %d\n", data->notepme);

	free(data);
	free(phls);
	return (0);
}

//int	main(int argc, char *argv[])
//{
//	if (argc < 5 || argc > 6)
//		return (err_msg(WRONG_COUNT_OF_ARGUMENTS));
//	if (philo(argc, argv) != 0)
//		return (1);
//	return (0);
//}
