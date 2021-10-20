#include "../include/philo.h"

int	life_checker(t_philo *phls)
{
	if ((get_time() - phls->last_meal) > phls->data->tm_die)
	{
		phls_msg(DIED, get_time() - phls->data->creation_time, \
				phls->id, phls->data->print_mutex);
		return (1);
	}
	return (0);
}

//int	satiety_checker(t_philo *phls)
//{
//	if ()
//}
