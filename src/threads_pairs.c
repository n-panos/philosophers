/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_pairs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:04:31 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/08/10 11:53:44 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_pair_threads(t_prg *prg, int error)
{
	if (error != 0)
		return (error);
	ft_create_threads();
	return (0);
}
