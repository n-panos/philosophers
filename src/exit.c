/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:38:16 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/08/09 12:27:37 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_exit_success(t_prg *prg)
{
	free(prg);
	return (0);
}

int	ft_exit_error(t_prg *prg, int error)
{
	if (error == 1)
		ft_putstr_fd("Invalid number of arguments\n", 1);
	if (error == 2)
		ft_putstr_fd("Error: arguments MUST be valid numbers\n", 1);
	if (error == 3)
		printf("For this arguments, time to die should be greater than %d\n", \
		prg->t_die);
	ft_putstr_fd("Use example: ./philo 4 401 200 200 (5)\n", 1);
	free(prg);
	return (1);
}

/*void	ft_free_prg(t_prg *prg)
{
	free(prg);
}*/

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
