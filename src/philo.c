/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:38:01 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/11/30 12:58:12 by ipanos-o         ###   ########.fr       */
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
	while (prg->args.alive == 0)
	{
	}
	ft_end_threads(prg->ph);
	return (0);
}
