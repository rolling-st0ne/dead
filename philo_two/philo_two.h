/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:14:47 by casteria          #+#    #+#             */
/*   Updated: 2020/10/08 23:47:29 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include "pthread.h"
# include <unistd.h>
# include <stdio.h> // to_delete

# define STD_OUT 1
# define SUCCESS 0

typedef enum		e_errors
{
	BAD_ARGS = 1
}					t_errors;

int				philo_one(int argc, char **argv);
int				print_error(t_errors error);
void			ft_putstr(const char *str);

#endif
