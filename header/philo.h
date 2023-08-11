/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:48:54 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/08/09 18:12:06 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_prg
{
	int		philos;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		n_meals;
}			t_prg;

typedef struct s_philo
{
	int		number;
	char	state;
}			t_philo;

//		PARSE ARGS

int		ft_parse(char **argv, int argc, t_prg *prg);
int		ft_args_to_struct(t_prg *prg, int argc, char **argv);
int		ft_aredigit_atoi(char *str);

//		THREADS	/	PHILOSOPHERS

int		ft_pair_threads(t_prg *prg, int error);
int 	ft_odd_threads(t_prg *prg, int error);

//		UTILS

int		ft_atoi(const char *str);
int		ft_isdigit(int c);

//		EXIT + ERROR + TEST FUNCTIONS

int		ft_exit_success(t_prg *prg);
int		ft_exit_error(t_prg *prg, int error);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif