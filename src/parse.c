/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:12:03 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/08/10 10:27:39 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_parse(char **argv, int argc, t_prg *prg)
{
	int	t_min;

	if (ft_args_to_struct(prg, argc, argv) == 1)
		return (1);
	if (prg->philos == -1 || prg->t_die == -1 || prg->t_eat == -1 || \
	prg->t_sleep == -1 || prg->n_meals == -1)
		return (2);
	t_min = prg->t_eat + prg->t_sleep;
	if (prg->philos % 2 == 1)
	{
		if (prg->t_eat > prg->t_sleep)
			t_min += prg->t_eat;
		else
			t_min += prg->t_sleep;
	}
	if (prg->t_die <= t_min)
	{
		prg->t_die = t_min;
		return (3);
	}
	return (0);
}

int	ft_args_to_struct(t_prg *prg, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);
	prg->philos = ft_aredigit_atoi(argv[1]);
	prg->t_die = ft_aredigit_atoi(argv[2]);
	prg->t_eat = ft_aredigit_atoi(argv[3]);
	prg->t_sleep = ft_aredigit_atoi(argv[4]);
	if (argc == 6)
		prg->n_meals = ft_aredigit_atoi(argv[5]);
	else
		prg->n_meals = -2;
	return (0);
}

int	ft_aredigit_atoi(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (ft_atoi(str));
}
