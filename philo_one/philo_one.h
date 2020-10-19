/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:14:47 by casteria          #+#    #+#             */
/*   Updated: 2020/10/19 22:58:09 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include "pthread.h"
# include <unistd.h>
# include <stdio.h> // to_delete
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

# define STD_OUT 1
# define SUCCESS 0
# define IS_FREE 1
# define IS_BUSY 0
# define DIED 1
# define ALIVE 0
# define ETERNITY_OF_PAINFUL_EXISTANCE 1
# define TRUE 1
# define FALSE 0

typedef enum		e_errors
{
	FAIL = -1,
	BAD_ARGS = 2,
	MALLOC,
	TIME,
	MUTEX_INIT,
	THREAD_INIT,
	THREAD_JOIN, //
	MUTEX_LOCK,
	MUTEX_UNLOCK,
	SLEEP
}					t_errors;

typedef struct		s_fork
{
	int				index;
	short int		status; // mb need to delete
	pthread_mutex_t	mutex;
}					t_fork;

typedef struct		s_args
{
	size_t			number_of_philosophers;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			number_of_times_each_philosopher_must_eat;
}					t_args;

typedef struct		s_params
{
	t_args			args;
	t_fork			**forks;
	long long		s_time;
	pthread_mutex_t	output_mutex;
}					t_params;

typedef struct		s_philosopher
{
	pthread_t		id;
	int				index;
	int				ret_val; //
	t_fork			*left_hand;
	t_fork			*right_hand;
	t_params		*params;
	long long		eat_last_time;
	long long		thread_time;
	size_t			eat_times;
}					t_philosopher;

typedef struct		s_philosophers
{
	t_params		params;
	t_philosopher	**philosophers;
}					t_philosophers;

int					philo_one(int argc, char **argv);
int					print_error(t_errors error);
void				ft_putstr(const char *str);
int					ft_atoi(const char *c);
int					init(int argc, char **argv, t_philosophers *philosophers);
int					start(t_philosophers *p);
long long			get_time(void);
long long			get_proc_time(t_params *params);
int					wait_till_death(t_philosophers *p);
void				*vicious_circle(void *arg);
int					set_forks(t_philosophers *p);
void				assign_forks(t_philosophers *p, int index);
int					clean(t_philosophers *p);
void				print_status(t_philosopher *phil, long long time, int index, char *status);
short int			is_error(int val);


#endif
