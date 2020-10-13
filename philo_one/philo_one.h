/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:14:47 by casteria          #+#    #+#             */
/*   Updated: 2020/10/14 00:35:28 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include "pthread.h"
# include <unistd.h>
# include <stdio.h> // to_delete
# include <stdlib.h>
# include <sys/time.h>

# define STD_OUT 1
# define SUCCESS 0
# define FAIL -1
# define ETERNITY_OF_PAINFUL_EXISTANCE 1

typedef enum		e_errors
{
	BAD_ARGS = 1
}					t_errors;

typedef struct		s_args
{
	size_t			number_of_philosophers;
	size_t			time_to_die;
	size_t			time_to_sleep;
	size_t			number_of_times_each_philosopher_must_eat;
}					t_args;

typedef struct		s_philosopher
{
	pthread_t		id;
	pthread_mutex_t	mutex;
	int				index;
	int				err_status;
}					t_philosopher;

typedef struct		s_params
{
	t_args			args;
	size_t			forks;
	long long		s_time;
}					t_params;

typedef struct		s_philosophers
{
	t_params		params;
	t_philosopher	**philosophers;
}					t_philosophers;

typedef struct		s_thread_info
{
	t_philosopher	**philo;
	t_params		*params;
}					t_thread_info;

int					philo_one(int argc, char **argv);
int					print_error(t_errors error);
void				ft_putstr(const char *str);
int					ft_atoi(const char *c);
int					init(int argc, char **argv, t_philosophers *philosophers);
int					start(t_philosophers *p);
long long			get_time(void);
int					wait_till_death(t_philosophers *p);
void				*vicious_circle(void *arg);

#endif
