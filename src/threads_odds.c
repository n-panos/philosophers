#include "../header/philo.h"

int	ft_odd_threads(t_prg *prg, int error)
{
	int	i;

	if (error != 0)
		return (error);
	i = 1;
	while (i <= prg->philos)
	{
		ft_create_thread(i);
		i++;
	}
	return (0);
}
