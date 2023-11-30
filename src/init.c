/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:47:50 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/11/30 12:58:24 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_init_prg(t_prg *prg, int argc, char **argv)
{
	int	i;

	i = ft_parse(argv, argc, &prg->args);
	if (i > 0)
		return (i);
	if (i == -1)
		printf("Be carefull, with this arguments, a philosopher might die\n");
	i = ft_philosophers(prg);
	return (i);
}

int	ft_init_forks(t_args *args)
{
	int	i;

	args->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
	args->philos);
	i = 0;
	if (!args->forks)
		return (1);
	while (i < args->philos)
	{
		if (pthread_mutex_init(&(args->forks[i]), NULL))
			return (1);
		++i;
	}
	return (0);
}

int	ft_create_philos(t_prg *prg)
{
	t_philo	*ph;
	int		i;

	ph = malloc(sizeof(t_philo) * (prg->args.philos));
	if (!ph)
		return (1);
	i = 0;
	prg->ph = ph;
	while (i < prg->args.philos)
	{
		ph[i].id = i + 1;
		ph[i].control = 10;
		ph[i].p_arg = &prg->args;
		ph[i].l_fork = &(prg->args.forks[i]);
		if (i == 0)
			ph[i].r_fork = &(prg->args.forks[prg->args.philos - 1]);
		else
			ph[i].r_fork = &(prg->args.forks[i - 1]);
		i++;
	}
	return (0);
}
