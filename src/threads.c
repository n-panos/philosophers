/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:37:40 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/11/29 10:57:11 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*ft_routine(void *v_philo)
{
	t_philo		*philo;
	long int	t_last_meal;

	philo = (t_philo *)v_philo;
	t_last_meal = ft_get_time();
	while (1)
	{
		ft_eat(philo, t_last_meal);
		if (philo->p_arg->alive == 0)
			ft_philo_sleep(philo);
		if (philo->control == 0 || philo->p_arg->alive == 1)
			break ;
	}
	return (0);
}

int	ft_philo_sleep(t_philo *philo)
{
	ft_print_status("is sleeping", *philo);
	ft_sleep(philo->p_arg->t_sleep);
	ft_print_status("is thinking", *philo);
}

long int	ft_eat(t_philo *philo, long int t_last_meal)
{
	ft_get_fork(*philo);
	t_last_meal = ft_get_time();
	ft_sleep_live(philo, philo->p_arg->t_eat);
	philo->control--;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (t_last_meal);
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
		ft_print_status("has taken a fork", philo);
		pthread_mutex_lock(philo.l_fork);
		ft_print_status("is eating", philo);
	}
	else
	{
		pthread_mutex_lock(philo.l_fork);
		ft_print_status("has taken a fork", philo);
		pthread_mutex_lock(philo.r_fork);
		ft_print_status("is eating", philo);
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
