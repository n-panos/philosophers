/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:48:54 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/09/06 13:14:25 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_args
{
	int				philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_meals;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	*fork;
}			t_args;

typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
	t_args			*p_arg;
}			t_philo;

typedef struct s_prg
{
	t_args	args;
	t_philo	*ph;
}			t_prg;

//		PARSE ARGS

int		ft_parse(char **argv, int argc, t_args *args);
int		ft_args_to_struct(t_args *args, int argc, char **argv);
int		ft_aredigit_atoi(char *str);

//		PRG CONFIG

int		ft_init_prg(t_prg *prg, int argc, char **argv);
void	ft_init_struct(t_prg *prg);
int		ft_create_philos(t_prg *prg);

//		THREADS	/	PHILOSOPHERS

//int		ft_pair_threads(t_args *args, int error);
//int		ft_odd_threads(t_args *args, int error);

int		ft_create_forks(t_prg *prg, t_philo philo);
int		ft_create_thread(void *v_philo);
void	*ft_philo_routine(void *v_philo);
int		ft_end_threads(t_philo *philo, int philo_num);

//		UTILS

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//		EXIT + ERROR + TEST FUNCTIONS

int		ft_exit_success(t_args *args);
int		ft_exit_error(t_args args, int error);

#endif