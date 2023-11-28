/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:37:40 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/11/28 12:28:39 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

/*void	*ft_philo_routine(void *v_philo)
{
	t_philo		*philo;
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
	if (philo->id == 2)
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
	}
	return (0);
}*/

void	*ft_routine(void *v_philo)
{
	t_philo		*philo;

	philo = (t_philo *)v_philo;
	ft_eat(*philo);
	return (0);
}

void	ft_eat(t_philo philo)
{
	ft_get_fork(philo);
	ft_sleep(200);
	ft_print_status("finished eating", philo);
	pthread_mutex_unlock(philo.l_fork);
	pthread_mutex_unlock(philo.r_fork);
}

void	ft_get_fork(t_philo philo)
{
	int	i;

	if (philo.id == 1)
		i = 1;
	else
		i = philo.id % 2;
	if (i == 0)
	{
		pthread_mutex_lock(philo.r_fork);
		ft_print_status("has taken right fork", philo);
		pthread_mutex_lock(philo.l_fork);
		ft_print_status("has taken left fork", philo);
	}
	else
	{
		pthread_mutex_lock(philo.l_fork);
		ft_print_status("has taken left fork", philo);
		pthread_mutex_lock(philo.r_fork);
		ft_print_status("has taken right fork", philo);
	}
	++philo.test_count;
}

int	ft_create_thread(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *)v_philo;
	if (pthread_create(&philo->thread_id, NULL, &ft_routine, v_philo))
		return (1);
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
