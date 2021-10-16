#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define WRONG_COUNT_OF_ARGUMENTS -1
# define WRONG_ARGUMENT -2
# define MALLOC_ERROR -3
# define PTHREAD_ERROR -4

typedef struct s_data
{
	int	num_phls;
	int	tm_die;
	int	tm_eat;
	int	tm_sleep;
	int	notepme;
}	t_data;

typedef struct s_philos
{
	t_data			*data;
	pthread_mutex_t	print_mutex;
	long			last_meal;
}	t_philo;

int	argv_processing(t_data *data, int argc, char **argv);
int	philosophers(t_philo *phls, t_data *data);
int	ft_atoi(const char *str);
int	err_msg(int err_number);

#endif