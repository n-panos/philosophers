/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:12:03 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/11/29 10:10:07 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_parse(char **argv, int argc, t_args *args)
{
	int	t_min;

	if (ft_args_to_struct(args, argc, argv) == 1)
		return (1);
	if (args->philos == -1 || args->t_die == -1 || args->t_eat == -1 || \
	args->t_sleep == -1 || args->n_meals == -1)
		return (2);
	t_min = args->t_eat + args->t_sleep;
	if (args->philos % 2 == 1)
	{
		if (args->t_eat > args->t_sleep)
			t_min += args->t_eat;
		else
			t_min += args->t_sleep;
	}
	if (args->t_die <= t_min)
	{
		args->t_die = t_min;
		return (-1);
	}
	return (0);
}

int	ft_args_to_struct(t_args *args, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);
	args->philos = ft_aredigit_atoi(argv[1]);
	args->t_die = ft_aredigit_atoi(argv[2]);
	args->t_eat = ft_aredigit_atoi(argv[3]);
	args->t_sleep = ft_aredigit_atoi(argv[4]);
	args->forks = NULL;
	args->start_time = ft_get_time();
	args->alive = 0;
	pthread_mutex_init(&args->writer, NULL);
	if (argc == 6)
		args->n_meals = ft_aredigit_atoi(argv[5]);
	else
		args->n_meals = -2;
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
