/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:35:51 by casteria          #+#    #+#             */
/*   Updated: 2020/10/12 01:18:33 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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