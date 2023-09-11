/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:38:16 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/09/06 10:53:27 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_exit_success(t_args *args)
{
	free(args);
	return (0);
}

int	ft_exit_error(t_args args, int error)
{
	if (error == 1)
		ft_putstr_fd("Invalid number of arguments\n", 1);
	if (error == 2)
		ft_putstr_fd("Error: arguments MUST be valid numbers\n", 1);
	if (error == 3)
		printf("For this arguments, time to die should be greater than %d\n", \
		args.t_die);
	ft_putstr_fd("Use example: ./philo 4 401 200 200 (5)\n", 1);
	return (1);
}

/*void	ft_free_prg(t_prg *prg)
{
	free(prg);
}*/
