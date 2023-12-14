/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:38:01 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/14 09:29:34 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	leaks(void)
{
	system("leaks -q philo");
}

int	main(int argc, char **argv)
{
	t_prg	*prg;
	int		ret;

	prg = malloc(sizeof(t_prg));
	if (!prg)
		return (1);
	ret = ft_init_prg(prg, argc, argv);
	if (ret > 0)
		return (ft_parse_errors(prg, ret));
	return (ft_exit_success(prg));
}

int	ft_philosophers(t_prg *prg)
{
	int	i;
	int	alive;

	i = 0;
	while (i < prg->args.philos)
	{
		ft_create_thread(&prg->ph[i]);
		i++;
	}
	ft_sleep(prg->args.t_die);
	while (1)
	{
		alive = ft_cpy_mutex(prg->args.alive, &prg->args.died);
		if (alive == 1)
			break ;
		if (ft_full(prg) == 1)
			break ;
		ft_alive(prg);
	}
	ft_end_threads(prg->ph);
	return (0);
}

void	ft_alive(t_prg *prg)
{
	int	i;
	int	alive;

	i = 0;
	while (i < prg->args.philos)
	{
		alive = ft_cpy_mutex(prg->args.alive, &prg->args.died);
		if (alive == 1)
			break ;
		ft_check_dead(&(prg->ph[i]));
		++i;
	}
}

int	ft_full(t_prg *prg)
{
	int	full;
	int	i;
	int	meals;

	i = 0;
	full = 0;
	while (i < prg->args.philos)
	{
		pthread_mutex_lock(&(prg->args.eating));
		meals = prg->ph[i].meals;
		pthread_mutex_unlock(&(prg->args.eating));
		if (meals == prg->args.n_meals)
			++full;
		++i;
	}
	if (full == prg->args.philos)
		return (1);
	ft_sleep(5);
	return (0);
}
