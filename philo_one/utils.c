/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:35:51 by casteria          #+#    #+#             */
/*   Updated: 2020/10/13 21:47:43 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

long long		get_time(void)
{
	long long		milliseconds;
	struct timeval	tv;
	int				status;

	status = 0;
	status = gettimeofday(&tv, NULL);
	if (status)
		return (FAIL);
	milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (milliseconds);
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

void			ft_putstr(const char *str)
{
	char		*ptr;

	ptr = (char *)str;
	while (ptr && *ptr)
		write(STD_OUT, ptr++, 1);
}
