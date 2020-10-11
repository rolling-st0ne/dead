/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:14:47 by casteria          #+#    #+#             */
/*   Updated: 2020/10/12 02:31:34 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include "pthread.h"
# include <unistd.h>
# include <stdio.h> // to_delete

# define STD_OUT 1
# define SUCCESS 0
# define FAIL -1

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
}					t_philosopher;

typedef struct		s_philosophers
{
	t_args			params;
	t_philosopher	**philosophers;

}					t_philosophers;

int					philo_one(int argc, char **argv);
int					print_error(t_errors error);
void				ft_putstr(const char *str);
int					ft_atoi(const char *c);
int					init(int argc, char **argv, t_philosophers philosophers);

#endif
