/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:48:54 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/11/27 16:58:54 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_args
{
	int				philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_meals;
	long int		start_time;
	pthread_mutex_t	writer;
	pthread_mutex_t	*forks;
}			t_args;

typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	int				test_count;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_args			*p_arg;
}			t_philo;

typedef struct s_prg
{
	t_args	args;
	t_philo	*ph;
}			t_prg;

//		MAIN FUNCTIONS

int		ft_init_prg(t_prg *prg, int argc, char **argv);
int		ft_philosophers(t_prg *prg);

//		PARSE ARGS

int		ft_parse(char **argv, int argc, t_args *args);
int		ft_args_to_struct(t_args *args, int argc, char **argv);
int		ft_aredigit_atoi(char *str);

//		PRG CONFIG

void	ft_init_struct(t_prg *prg);

//		PHILO INIT

int		ft_init_forks(t_args *args);
int		ft_create_philos(t_prg *prg);

//		THREADS

void	*ft_routine(void *v_philo);
void	ft_eat(t_philo philo);
int		ft_create_thread(void *v_philo);
int		ft_end_threads(t_philo *philo);

//		UTILS

int			ft_atoi(const char *str);
int			ft_isdigit(int c);

long int	ft_get_time(void);
void		ft_sleep(long int time_in_ms);

//		EXIT + ERROR + TEST FUNCTIONS

int		ft_exit_success(t_prg *prg);
int		ft_parse_errors(t_prg *prg, int error);
void	ft_free_prg(t_prg *prg);

#endif