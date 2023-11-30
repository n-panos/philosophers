/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:55:03 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/11/29 11:47:23 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

long int	ft_get_time(void)
{
	long int		time;
	struct timeval	current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_sleep(long int time_in_ms)
{
	long int	start_time;

	start_time = ft_get_time();
	while ((ft_get_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

void	ft_sleep_live(t_philo *philo, long int start_t, long int sleep_t)
{
	if (start_t < sleep_t)
	{
		ft_sleep(sleep_t - start_t);
		philo->p_arg->alive == 1;
		ft_print_status("died", *philo);
	}
	else
		ft_sleep(sleep_t);
}