/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:35:51 by casteria          #+#    #+#             */
/*   Updated: 2020/10/18 16:53:47 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

size_t			cast_time(struct timeval *tv)
{
	size_t		milliseconds;
	milliseconds = (size_t)(tv->tv_sec * 1000 + tv->tv_usec / 1000);
	return (milliseconds);
}

size_t			get_proc_time(t_params *params)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL))
		return (TIME);
	return (cast_time(&current_time) - cast_time(&params->s_time));
}

static int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int		ft_is_space(const char *c)
{
	if (*c == '\n' || *c == '\t' || *c == '\r' || *c == '\v' ||
			*c == '\f' || *c == ' ')
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *c)
{
	int					sign;
	unsigned long long	result;

	sign = 1;
	result = 0;
	while (ft_is_space(c))
		c++;
	if (*c == '-')
		sign = -1;
	if (*c == '-' || *c == '+')
		c++;
	while (ft_isdigit(*c) != 0)
	{
		result = (unsigned long long)result * 10 + *c - '0';
		if (result * 10 < result)
			return ((sign == 1) ? -1 : 0);
		c++;
	}
	return ((int)result * sign);
}
