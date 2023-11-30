/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:51:25 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/11/30 12:59:51 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_check_dead(t_philo *philo, long int t_last_meal)
{
	long int	t_current;

	t_current = ft_get_time() - t_last_meal;
	if (t_current > philo->p_arg->t_die)
		philo->p_arg->alive = 1;
}

void	ft_print_status(char *str, t_philo ph)
{
	unsigned long	time;

	pthread_mutex_lock(&(ph.p_arg->writer));
	time = ft_get_time() - ph.p_arg->start_time;
	if (ph.p_arg->alive == 0)
		printf("%lu - %d %s\n", time, ph.id, str);
	pthread_mutex_unlock(&(ph.p_arg->writer));
}

int	ft_atoi(const char *str)
{
	unsigned long long int	suma;
	int						signo;

	suma = 0;
	signo = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		signo = 1;
	if (*str == '+' || *str == '-')
		str++;
	while ('0' <= *str && *str <= '9' && *str != '\0')
	{
		if (suma < 9223372036854775807)
		{
			suma = suma * 10 + (*str - '0');
			str++;
		}
		else
			return (signo - 1);
	}
	if (signo == 1)
		return (-suma);
	return (suma);
}

int	ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
		return (1);
	return (0);
}
