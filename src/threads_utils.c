/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:44:10 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/11/26 13:08:34 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_create_philos(t_prg *prg)
{
	t_philo	*ph;
	int		i;

	ph = malloc(sizeof(t_philo) * (prg->args.philos - 1));
	if (!ph)
		return (1);
	i = 0;
	while (i < prg->args.philos)
	{
		ph[i].id = i;
		ph[i].p_arg = &prg->args;
		i++;
	}
	//ft_create_eat_forks(prg, prg->ph[i]);
	i = 0;
	while (i < prg->args.philos)
	{
		ft_create_thread(&prg->ph[i]);
		i++;
	}
	ft_sleep(200);
	ft_end_threads(prg->ph, prg->args.philos);
	return (0);
}

//				(fork - sizeof(pthread_mutex_t));

int	ft_create_eat_forks(t_prg *prg, t_philo philo)
{
	pthread_mutex_t	*fork;
	int				i;

	fork = malloc(sizeof(pthread_mutex_t) * prg->args.philos);
	i = 0;
	prg->args.fork = fork;
	while (i < prg->args.philos)
	{
		pthread_mutex_init(&fork[i], NULL);
		if (i == 0)
		{
			philo.r_fork = fork + (prg->args.philos - \
			sizeof(pthread_mutex_t));
			philo.l_fork = fork;
		}
		else
		{
			philo.l_fork = fork;
			philo.r_fork = fork - sizeof(pthread_mutex_t);
		}
		fork = fork + sizeof(pthread_mutex_t);
		i++;
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

//	pthread_join needs free?

int	ft_end_threads(t_philo *philo, int philo_num)
{
	int	i;

	i = 0;
	
	while (i < philo_num)
	{
		if (pthread_join(philo[i].thread_id, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
