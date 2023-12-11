/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:45:47 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/11 10:34:07 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*ft_routine(void *v_philo)
{
	t_philo		*philo;

	philo = (t_philo *)v_philo;
	if (philo->p_arg->philos == 1)
	{
		ft_solo_routine(philo);
		return (0);
	}
	if ((philo->id > 1 && philo->id % 2 == 0) || \
		(philo->p_arg->philos % 2 == 1 && philo->p_arg->philos == philo->id))
		ft_sleep(5);
	while (1)
	{
		if (philo->p_arg->alive == 0)
			ft_eat(philo);
		ft_philo_sleep(philo);
		if (philo->p_arg->alive == 1 || philo->meals == philo->p_arg->n_meals)
			break ;
	}
	return (0);
}

int	ft_philo_sleep(t_philo *philo)
{
	ft_print_status("is sleeping", philo);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	if (philo->p_arg->alive == 0)
		ft_sleep(philo->p_arg->t_sleep);
	ft_print_status("is thinking", philo);
	if (philo->meals == philo->p_arg->n_meals)
		philo->p_arg->full++;
	return (1);
}

void	ft_eat(t_philo *philo)
{
	ft_get_fork(*philo);
	philo->last_meal = ft_get_time();
	philo->meals++;
	ft_sleep(philo->p_arg->t_eat);
}

void	ft_get_fork(t_philo philo)
{
	pthread_mutex_lock(philo.l_fork);
	ft_print_status("has taken a fork", &philo);
	pthread_mutex_lock(philo.r_fork);
	ft_print_status("is eating", &philo);
}

void	ft_solo_routine(t_philo *philo)
{
	ft_print_status("has taken a fork", philo);
	ft_sleep(philo->p_arg->t_die);
	ft_print_status("died", philo);
}
