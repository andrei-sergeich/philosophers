#include "philo.h"

// static int	positive_or_negative(char in)
// {
// 	if (in == 45)
// 		return (-1);
// 	else
// 		return (1);
// }

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
		// sign = positive_or_negative(str[in++]);
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