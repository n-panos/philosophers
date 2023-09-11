/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:51:25 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/09/04 10:20:30 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

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

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s + i != NULL && s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = (unsigned int)(n * -1);
	}
	else
		nb = (unsigned int)n;
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	c = (nb % 10) + 48;
	ft_putchar_fd(c, fd);
}
