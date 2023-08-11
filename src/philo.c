/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:38:01 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/08/09 18:13:19 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

//static void	ft_print_prg(t_prg *prg);

void	leaks()
{
	system("leaks -q philo");
}

int	main(int argc, char **argv)
{
	t_prg	*prg;
	int		ret;

	prg = malloc(sizeof(*prg));
	ret = ft_parse(argv, argc, prg);
	if (prg->philos > 0 && prg->philos % 2 == 0)
		ft_pair_threads(prg, ret);
	else if (prg->philos > 0 && prg->philos % 2 == 1)
		ft_odd_threads(prg, ret);
	if (ret != 0)
		return (ft_exit_error(prg, ret));
	return (ft_exit_success(prg));
}

/*static void	ft_print_prg(t_prg *prg)
{
	ft_putstr_fd("number of philosophers: ", 1);
	ft_putnbr_fd(prg->philos, 1);
	ft_putstr_fd("\ntime to die: ", 1);
	ft_putnbr_fd(prg->t_die, 1);
	ft_putstr_fd("\ntime to eat: ", 1);
	ft_putnbr_fd(prg->t_eat, 1);
	ft_putstr_fd("\ntime sleeping: ", 1);
	ft_putnbr_fd(prg->t_sleep, 1);
	ft_putstr_fd("\nnumber of meals: ", 1);
	ft_putnbr_fd(prg->n_meals, 1);
	ft_putstr_fd("\n", 1);
}*/
