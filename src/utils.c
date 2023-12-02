/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:51:25 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/02 10:38:59 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_check_dead(t_philo *philo)
{
	long int	currentt;

	currentt = ft_get_time() - philo->last_meal;
	if (currentt > philo->p_arg->t_die)
	{
		ft_print_status("died", philo);
		return (1);
	}
	return (0);
}

void	ft_print_status(char *str, t_philo *ph)
{
	unsigned long	time;

	pthread_mutex_lock(&(ph->p_arg->writer));
	time = ft_get_time() - ph->p_arg->start_time;
	if (ph->p_arg->alive == 0 && ph->p_arg->full != ph->p_arg->philos)
	{
		printf("%lu - %d %s\n", time, ph->id, str);
		if (ft_strncmp(str, "died", 4) == 0)
			ph->p_arg->alive = 1;
	}
	pthread_mutex_unlock(&(ph->p_arg->writer));
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

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;
	size_t				i;

	i = 0;
	ss1 = (const unsigned char *)s1;
	ss2 = (const unsigned char *)s2;
	if (len == 0)
		return (0);
	while (ss1[i] == ss2[i] && ss1[i] != '\0' && ss2[i] != '\0' && i < len - 1)
		i++;
	return (ss1[i] - ss2[i]);
}
