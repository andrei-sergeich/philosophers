/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:41:05 by cmero             #+#    #+#             */
/*   Updated: 2021/11/07 12:41:06 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define WRONG_COUNT_OF_ARGUMENTS	-1
# define WRONG_ARGUMENT				-2
# define MALLOC_ERROR				-3
# define PTHREAD_ERROR				-4

# define L_FORK_TAKEN	1
# define R_FORK_TAKEN	2
# define EATING			3
# define SLEEPING		4
# define THINKING		5
# define DIED			6

typedef struct s_data
{
	int				num_phls;
	int				tm_die;
	int				tm_eat;
	int				tm_sleep;
	int				notepme;
	long			creation_time;
	pthread_mutex_t	*print_mutex;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	int				id;
	int				num_meals;
	int				satiety;
	long			last_meal;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

int		argv_processing(t_data *data, int argc, char **argv);
int		philosophers(t_data *data);
void	philo_creator(t_philo *phls, t_data *data, pthread_mutex_t *fork);
int		philo_starter(t_philo *phls, t_data *data);
void	*phls_life(void *phls);
void	philo_takes_forks(t_philo *phls);
void	philo_eating(t_philo *phls);
void	philo_sleeping(t_philo *phls);
void	eating_or_sleeping(long time);
int		philo_checker(t_philo *phls);
void	mutex_destroyer(t_philo *phls, t_data *data);

void	*life_checker(void *phls);
int		satiety_checker(t_philo *phls);

int		ft_atoi(const char *str);
int		err_msg(int err_number);
void	phls_msg(int msg_code, long time, int id, pthread_mutex_t *print_mutex);
long	get_time(void);

#endif