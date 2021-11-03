#include "../include/philo_bonus.h"

void	ft_putnbr_ll(long long n)
{
	if (n == -9223372036854775807)
	{
		write(1, "-9223372036854775807", 23);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr_ll(-n);
	}
	else if (n > 9)
		ft_putnbr_ll(n / 10);
	if (n >= 0)
	{
		n = n % 10 + 48;
		write(1, &n, 1);
	}
}

void	ft_putendl(char *s)
{
	if (s)
	{
		while (*s)
			write(1, s++, 1);
	}
	write(1, "\n", 1);
}

void	ft_print(long time, int id, char *msg, sem_t *print_sem)
{
	sem_wait(print_sem);
	ft_putnbr_ll(time);
	write(1, " ", 1);
	ft_putnbr_ll(id);
	ft_putendl(msg);
	sem_post(print_sem);
}

//void	phls_msg(int msg_code, long time, int id, pthread_mutex_t *print_mutex)
//{
////	pthread_mutex_lock(print_mutex);
//	if (msg_code == L_FORK_TAKEN)
//		ft_print(time, id, " has taken a fork", print_mutex);
//	else if (msg_code == R_FORK_TAKEN)
//		ft_print(time, id, " has taken a fork", print_mutex);
//	else if (msg_code == EATING)
//		ft_print(time, id, " is eating", print_mutex);
//	else if (msg_code == SLEEPING)
//		ft_print(time, id, " is sleeping", print_mutex);
//	else if (msg_code == THINKING)
//		ft_print(time, id, " is thinking", print_mutex);
//	else if (msg_code == DIED)
//	{
//		ft_print(time, id, " died", print_mutex);
//		return ;
//	}
////	pthread_mutex_unlock(print_mutex);
//}