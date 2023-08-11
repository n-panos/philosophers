#include "../header/philo.h"

int	ft_threads(t_prg *prg)
{
	pthread_t		*t;
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	t = ft_create_threads(prg, prg->philos);
	if (t == NULL)
		return (9);
	if (ft_end_threads(t, prg->philos) == 1)
		return (10);
	pthread_mutex_destroy(&mutex);
	return (0);
}

void	ft_create_philo(void *arg)
{
}

pthread_t	*ft_create_threads(t_prg *prg, int philo_num)
{
	int				i;
	pthread_t		*t;
	pthread_mutex_t	*f_mutex;

	i = 0;
	t = malloc(sizeof(pthread_t) * (prg->philos));
	f_mutex = malloc(sizeof(pthread_mutex_t) * (prg->philos));
	while (i < prg->philos)
	{
		pthread_mutex_init(&f_mutex[i], NULL);
		if (pthread_create(t[i], NULL, &ft_create_philo, &f_mutex))
			return (NULL);
		i++;
	}
	return (t);
}

//	pthread_join needs free?

int	ft_end_threads(pthread_t *t, int philo_num)
{
	int	i;

	i = 0;
	while (t[i] < philo_num)
	{
		if (pthread_join(t[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}