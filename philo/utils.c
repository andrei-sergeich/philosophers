#include "philo.h"

int	ft_atoi(const char *str)
{
	int		in;
	int		sign;
	long	num;

	in = 0;
	sign = 1;
	num = 0;
	while ((((str[in] > 8) && (str[in] < 14)) || str[in] == 32) && \
			str[in] != '\0')
		in++;
	if (str[in] == 43 || str[in] == 45)
		sign = (str[in++] & 2) - 1;
	if (str[in] < 48 || str[in] > 57)
		return (0);
	while ((str[in] > 47) && (str[in] < 58))
		num = num * 10 + (str[in++] - '0');
	num = num * sign;
	if (num > 2147483647)
		return (-1);
	if (num < -2147483648)
		return (0);
	return ((int)num);
}

int	err_msg(int err_number)
{
	if (err_number == WRONG_COUNT_OF_ARGUMENTS)
		printf("you passed the wrong number of arguments");
	if (err_number == WRONG_ARGUMENT)
		printf("you passed the wrong argument");
	if (err_number == MALLOC_ERROR)
		printf("malloc error");
	if (err_number == PTHREAD_ERROR)
		printf("pthread error");
	return (1);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_print(t_philo *tmp)
{
	pthread_mutex_lock(tmp->data->print_mutex);
	printf("phls[it].id - %d\t", tmp->id);
	printf("tm_die - %d\t", tmp->data->tm_die);
	printf("notepme - %d\n", tmp->data->notepme);
	pthread_mutex_unlock(tmp->data->print_mutex);
}
