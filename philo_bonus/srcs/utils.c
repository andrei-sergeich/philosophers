#include "../include/philo_bonus.h"

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
	else if (err_number == WRONG_ARGUMENT)
		printf("you passed the wrong argument");
	else if (err_number == MALLOC_ERROR)
		printf("malloc error");
	else if (err_number == PTHREAD_ERROR)
		printf("pthread error");
	return (1);
}

void	phls_msg(int msg_code, long time, int id, sem_t *print_sem)
{
	sem_wait(print_sem);
//	pthread_mutex_lock(print_mutex);
	if (msg_code == L_FORK_TAKEN)
		printf("%ld %d has taken a fork\n", time, id);
	else if (msg_code == R_FORK_TAKEN)
		printf("%ld %d has taken a fork\n", time, id);
	else if (msg_code == EATING)
		printf("%ld %d is eating\n", time, id);
	else if (msg_code == SLEEPING)
		printf("%ld %d is sleeping\n", time, id);
	else if (msg_code == THINKING)
		printf("%ld %d is thinking\n", time, id);
	else if (msg_code == DIED)
	{
		printf("%ld %d died\n", time, id);
		exit (1);
	}
//	pthread_mutex_unlock(print_mutex);
	sem_post(print_sem);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	sem_opener(t_data *data)
{
	if (sem_unlink("print_sem") == -1)
		exit(1);
	if (sem_unlink("fork"))
		exit(1);
	data->print_sem = sem_open("print_sem", O_CREAT, 0666, 1);
	data->fork = sem_open("fork", O_CREAT, 0666, 1);
	if (data->print_sem == 0 || data->fork == 0)
		exit(1);
}