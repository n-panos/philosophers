/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:38:16 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/11/27 15:49:26 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_exit_success(t_prg *prg)
{
	ft_sleep(200);
	ft_free_prg(prg);
	return (0);
}

int	ft_parse_errors(t_prg *prg, int error)
{
	if (error == 1)
		printf("Invalid number of arguments\n");
	if (error == 2)
		printf("Error: arguments MUST be valid numbers\n");
	if (error == 3)
		printf("For this arguments, time to die should be greater than %d\n", \
		prg->args.t_die);
	printf("Use example: ./philo 4 401 200 200 (5)\n");
	ft_free_prg(prg);
	return (1);
}

void	ft_free_prg(t_prg *prg)
{
	pthread_mutex_destroy(&prg->args.writer);
	if (prg->args.forks != NULL)
		free(prg->args.forks);
	free(prg->ph);
	free(prg);
}
