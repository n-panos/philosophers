/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:45:47 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/14 09:40:53 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*ft_routine(void *v_philo)
{
	t_philo	*philo;
	int		alive;
	int		meals;

	philo = (t_philo *)v_philo;
	if (ft_solo_routine(philo) == 0)
		return (0);
	while (1)
	{
		alive = ft_cpy_mutex(philo->p_arg->alive, &philo->p_arg->died);
		meals = ft_cpy_mutex(philo->meals, &philo->p_arg->eating);
		if (alive == 1 || meals == philo->p_arg->n_meals)
			break ;
		if (alive == 0)
			ft_eat(philo);
		ft_philo_sleep(philo);
	}
	return (0);
}

int	ft_solo_routine(t_philo *philo)
{
	if (philo->p_arg->philos == 1)
	{
		ft_print_status("has taken a fork", philo);
		ft_sleep(philo->p_arg->t_die);
		ft_print_status("died", philo);
		return (0);
	}
	if ((philo->id > 1 && philo->id % 2 == 0) || \
		(philo->p_arg->philos % 2 == 1 && philo->p_arg->philos == philo->id))
		ft_sleep(5);
	return (1);
}
