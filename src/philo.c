/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:38:01 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/09/06 12:48:26 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static void	ft_print_prg(t_args args);

void	leaks()
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
	ft_end_threads(prg->ph, prg->args.philos);
	if (ret != 0)
		return (ft_exit_error(prg->args, ret));
	return (0);
	/*return (ft_exit_success(args));*/
}

int	ft_init_prg(t_prg *prg, int argc, char **argv)
{
	int	i;

	i = ft_parse(argv, argc, &prg->args);
	ft_putstr_fd("\ni: ", 1);
	ft_putnbr_fd(i, 1);
	ft_putstr_fd("\n", 1);
	if (i != 0)
		return (i);
	ft_print_prg(prg->args);
	ft_init_struct(prg);
	ft_create_philos(prg);
	return (0);
}

void	ft_init_struct(t_prg *prg)
{
	pthread_mutex_init(&prg->args.write_mutex, NULL);
}

static void	ft_print_prg(t_args args)
{
	ft_putstr_fd("number of philosophers: ", 1);
	ft_putnbr_fd(args.philos, 1);
	ft_putstr_fd("\ntime to die: ", 1);
	ft_putnbr_fd(args.t_die, 1);
	ft_putstr_fd("\ntime to eat: ", 1);
	ft_putnbr_fd(args.t_eat, 1);
	ft_putstr_fd("\ntime sleeping: ", 1);
	ft_putnbr_fd(args.t_sleep, 1);
	ft_putstr_fd("\nnumber of meals: ", 1);
	ft_putnbr_fd(args.n_meals, 1);
	ft_putstr_fd("\n", 1);
}
