/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_odds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:11:39 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/09/04 13:12:11 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

	/*if (ret == 0 && args->philos > 0 && args->philos % 2 == 0)
		ft_pair_threads(args, ret);
	else if (ret == 0 && args->philos > 0 && args->philos % 2 == 1)
		ft_odd_threads(args, ret);

int	ft_odd_threads(t_prg *prg, int error)
{
	int	i;

	if (error != 0)
		return (error);
	i = 1;
	while (i <= prg->philos)
	{
		ft_create_thread(i);
		i++;
	}
	return (0);
}
*/