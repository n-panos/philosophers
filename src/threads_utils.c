/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:44:10 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/11/27 15:34:08 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_create_philos(t_prg *prg)
{
	t_philo	*ph;
	int		i;

	ph = malloc(sizeof(t_philo) * (prg->args.philos));
	if (!ph)
		return (1);
	i = 0;
	prg->ph = ph;
	while (i < prg->args.philos)
	{
		ph[i].id = i;
		ph[i].p_arg = &prg->args;
		ph[i].l_fork = &(prg->args.forks[i]);
		if (i == 0)
			ph[i].r_fork = &(prg->args.forks[prg->args.philos - 1]);
		else
			ph[i].r_fork = &(prg->args.forks[i - 1]);
		i++;
	}
	return (0);
}

//				(fork - sizeof(pthread_mutex_t));

int	ft_init_forks(t_args *args)
{
	int				i;

	args->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
	args->philos);
	i = 0;
	if (!args->forks)
		return (1);
	while (i < args->philos)
	{
		if (pthread_mutex_init(&(args->forks[i]), NULL))
			return (1);
		++i;
	}
	return (0);
}

int	ft_create_thread(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *)v_philo;
	if (pthread_create(&philo->thread_id, NULL, &ft_philo_routine, v_philo))
		return (1);
	return (0);
}

void	*ft_philo_routine(void *v_philo)
{
	t_philo	*philo;
	long int	i;

	philo = (t_philo *)v_philo;
	pthread_mutex_lock(&philo->p_arg->writer);
	i = ft_get_time() - philo->p_arg->start_time;
	printf("\nThis is philo number %d, time is: %ld\n", philo->id, i);
	//pthread_mutex_unlock(&philo->p_arg->write_mutex);
	ft_sleep(200);
	//pthread_mutex_lock(&philo->p_arg->write_mutex);
	i = ft_get_time() - philo->p_arg->start_time;
	printf("\nThis is again philo number %d, time is: %ld\n", philo->id, i);
	pthread_mutex_unlock(&philo->p_arg->writer);
	/*if (philo->id == 2)
	{
		pthread_mutex_lock(philo->l_fork);
		printf("\nPhilo number %d grabing left Fork\n", philo->id);
		sleep(2);
		pthread_mutex_unlock(philo->l_fork);
	}
	if (philo->id == 3)
	{
		pthread_mutex_lock(philo->r_fork);
		printf("\nPhilo number %d grabing right Fork\n", philo->id);
		sleep(2);
		pthread_mutex_unlock(philo->r_fork);
	}*/
	return (0);
}



int	ft_end_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->p_arg->philos)
	{
		if (pthread_join(philo[i].thread_id, NULL) != 0)
			return (1);
		pthread_mutex_destroy(&philo->p_arg->forks[i]);
		i++;
	}
	return (0);
}
