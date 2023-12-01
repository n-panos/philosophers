/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:45:47 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/01 10:48:16 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*ft_routine(void *v_philo)
{
	t_philo		*philo;

	philo = (t_philo *)v_philo;
	while (1)
	{
		if (philo->p_arg->alive == 0)
			ft_eat(philo);
		if (philo->p_arg->alive == 0)
			ft_philo_sleep(philo);
		else
		{
			pthread_mutex_unlock(philo->l_fork);
			pthread_mutex_unlock(philo->r_fork);
		}
		if (philo->p_arg->alive == 1)
			break ;
	}
	return (0);
}

int	ft_philo_sleep(t_philo *philo)
{
	ft_print_status("is sleeping", philo);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	ft_sleep(philo->p_arg->t_sleep);
	ft_print_status("is thinking", philo);
	return (1);
}

void	ft_eat(t_philo *philo)
{
	ft_get_fork(*philo);
	philo->last_meal = ft_get_time();
	ft_sleep(philo->p_arg->t_eat);
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
		ft_print_status("has taken a fork", &philo);
		pthread_mutex_lock(philo.l_fork);
		ft_print_status("is eating", &philo);
	}
	else
	{
		pthread_mutex_lock(philo.l_fork);
		ft_print_status("has taken a fork", &philo);
		pthread_mutex_lock(philo.r_fork);
		ft_print_status("is eating", &philo);
	}
}