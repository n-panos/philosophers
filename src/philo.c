/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:38:01 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/11/27 15:50:06 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	leaks()
{
	system("leaks -q philo");
}

int	main(int argc, char **argv)
{
	t_prg	*prg;
	int		ret;

	atexit(leaks);
	prg = malloc(sizeof(t_prg));
	if (!prg)
		return (1);
	ret = ft_init_prg(prg, argc, argv);
	if (ret != 0)
		return (ft_parse_errors(prg, ret));
	return (ft_exit_success(prg));
}

int	ft_init_prg(t_prg *prg, int argc, char **argv)
{
	int	i;

	i = ft_parse(argv, argc, &prg->args);
	if (i != 0)
		return (i);
	ft_philosophers(prg);
	return (0);
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
	ft_sleep(200);
	ft_end_threads(prg->ph);
	return (0);
}

/*static void	ft_print_prg(t_args args)
{
	printf("number of philosophers: %d\n", args.philos);
	printf("time to die: %d\n", args.t_die);
	printf("time to eat: %d\n", args.t_eat);
	printf("time sleeping: %d\n", args.t_sleep);
	printf("number of meals: %d\n", args.n_meals);
}*/
