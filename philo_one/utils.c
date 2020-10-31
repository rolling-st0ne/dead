/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:35:51 by casteria          #+#    #+#             */
/*   Updated: 2020/10/30 20:48:11 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

long long		cast_time(struct timeval tv)
{
	return ((long long)(tv.tv_sec * 1000 + tv.tv_usec / 1000));
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

int				ft_sleep(size_t need, t_philosopher *phil)
{
	struct timeval	cur;

	if (gettimeofday(&cur, NULL))
		return (TIME);
	while (cast_time(cur) - cast_time(phil->thread_time) <= (long long)need)
	{
		if (usleep(100))
			return (SLEEP);
		if (gettimeofday(&cur, NULL))
			return (TIME);
	}
	return (SUCCESS);
}
