/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:55:03 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/11/28 12:05:52 by ipanos-o         ###   ########.fr       */
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

void	ft_print_status(char *str, t_philo ph)
{
	unsigned long	time;

	pthread_mutex_lock(&(ph.p_arg->writer));
	time = ft_get_time() - ph.p_arg->start_time;
	if (ph.p_arg->alive == 0 && ph.p_arg->fed == 0)
		printf("[%lu] - %d %s\n", time, ph.id, str);
	pthread_mutex_unlock(&(ph.p_arg->writer));
}
