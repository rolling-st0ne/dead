/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:14:47 by casteria          #+#    #+#             */
/*   Updated: 2020/10/30 02:28:30 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include "pthread.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
# include <semaphore.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define STD_OUT 1
# define SUCCESS 0
# define IS_FREE 1
# define IS_BUSY 0
# define FULL 2
# define DIED 1
# define ALIVE 0
# define ETERNITY_OF_PAINFUL_EXISTANCE 1
# define TRUE 1
# define FALSE 0

typedef enum		e_errors
{
	FAIL = -1,
	BAD_ARGS = 3,
	MALLOC,
	TIME,
	THREAD_INIT,
	THREAD_JOIN,
	SEM_OPEN,
	SEM_CLOSE,
	SEM_UNLINK,
	SEM_POST,
	SEM_WAIT,
	SLEEP
}					t_errors;

typedef struct		s_args
{
	size_t			number_of_philosophers;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
}					t_args;

typedef struct		s_params
{
	t_args			args;
	sem_t			*sem;
	struct timeval	s_time;
	short int		stop_sign;
}					t_params;

typedef struct		s_philosopher
{
	pthread_t		id;
	int				index;
	int				ret_val;
	t_params		*params;
	int				eaten;
	struct timeval	eat_last_time;
	struct timeval	thread_time;
	size_t			eat_times;
}					t_philosopher;

typedef struct		s_philosophers
{
	t_params		params;
	t_philosopher	**philosophers;
}					t_philosophers;

int					print_error(t_errors error);
void				ft_putstr(const char *str);
int					ft_atoi(const char *c);
int					init(int argc, char **argv, t_philosophers *philosophers);
int					start(t_philosophers *p);
long long			cast_time(struct timeval time);
int					wait_till_death(t_philosophers *p);
void				*vicious_circle(void *arg);
int					clean(t_philosophers *p);
int					ft_sleep(size_t need, t_philosopher *phil);
int					print_status(t_philosopher *phil, struct timeval time,\
														char *status);
short int			is_error(int val);

#endif
