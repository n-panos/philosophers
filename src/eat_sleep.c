/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:27:25 by nacho             #+#    #+#             */
/*   Updated: 2023/12/14 09:28:30 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_philo_sleep(t_philo *philo)
{
	int	alive;

	ft_print_status("is sleeping", philo);
	alive = ft_cpy_mutex(philo->p_arg->alive, &philo->p_arg->died);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	if (alive == 0)
	{
		ft_sleep(philo->p_arg->t_sleep);
		ft_print_status("is thinking", philo);
	}
	return (1);
}

void	ft_eat(t_philo *philo)
{
	ft_get_fork(*philo);
	pthread_mutex_lock(&(philo->p_arg->died));
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&(philo->p_arg->died));
	if (philo->p_arg->n_meals != -2)
	{
		pthread_mutex_lock(&(philo->p_arg->eating));
		philo->meals++;
		pthread_mutex_unlock(&(philo->p_arg->eating));
	}
	ft_sleep(philo->p_arg->t_eat);
}

void	ft_get_fork(t_philo philo)
{
	pthread_mutex_lock(philo.l_fork);
	ft_print_status("has taken a fork", &philo);
	pthread_mutex_lock(philo.r_fork);
	ft_print_status("is eating", &philo);
}
