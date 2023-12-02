/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:38:01 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/02 11:36:18 by nacho            ###   ########.fr       */
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

	//atexit(leaks);
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

	if (ft_init_forks(&(prg->args)) == 1)
		return (1);
	if (ft_create_philos(prg) == 1)
		return (1);
	i = 0;
	while (i < prg->args.philos)
	{
		ft_create_thread(&prg->ph[i]);
		i++;
	}
	ft_sleep(prg->args.t_die);
	while (prg->args.alive == 0)
	{
		if (prg->args.full == prg->args.philos)
			break;
		ft_alive(prg);
	}
	ft_end_threads(prg->ph);
	return (0);
}

void	ft_alive(t_prg *prg)
{
	int	i;

	i = 0;
	while (i < prg->args.philos)
	{
		if (prg->args.alive == 1)
			break ;
		if (prg->args.n_meals == -2 || prg->ph[i].meals < prg->args.n_meals)
			ft_check_dead(&(prg->ph[i]));
		++i;
	}
}
