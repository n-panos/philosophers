/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:37:40 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/11/28 21:22:43 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*ft_routine(void *v_philo)
{
	t_philo		*philo;
	long int	count_to_die;

	philo = (t_philo *)v_philo;
	while (1)
	{
		count_to_die = ft_get_time();
		ft_eat(philo, count_to_die);
		ft_philo_sleep(philo);
		if (philo->control == 0)
			break ;
	}
	return (0);
}

void	ft_philo_sleep(t_philo *philo)
{
	ft_print_status("is sleeping", *philo);
	ft_sleep(philo->p_arg->t_sleep);
}

void	ft_eat(t_philo *philo, long int count_to_die)
{
	ft_get_fork(*philo);
	ft_sleep(philo->p_arg->t_eat);
	ft_print_status("finished eating", *philo);
	philo->control--;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
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
