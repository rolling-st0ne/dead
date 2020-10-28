/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:37:59 by casteria          #+#    #+#             */
/*   Updated: 2020/10/28 20:02:09 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void			ft_putchar(char c)
{
	write(STD_OUT, &c, 1);
}

void				ft_putstr(const char *str)
{
	char		*ptr;

	ptr = (char *)str;
	while (ptr && *ptr)
		write(STD_OUT, ptr++, 1);
}

static void			ft_putnbr(int n)
{
	if (n == INT_MIN)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
	}
	else if (n < 10)
	{
		ft_putchar((char)(n + '0'));
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar((char)(n % 10 + '0'));
	}
}

void				print_status(t_philosopher *phil, struct timeval time, \
													int index, char *status)
{
	size_t			cur;

	if (!phil->params->stop_sign)
	{
		pthread_mutex_lock(&phil->params->output_mutex);
		cur = (size_t)((time.tv_sec - phil->params->s_time.tv_sec) * 1000
					+ (time.tv_usec - phil->params->s_time.tv_usec) * 0.001);
		ft_putnbr(cur);
		ft_putchar(' ');
		ft_putnbr(index);
		ft_putchar(' ');
		ft_putstr((const char *)status);
		ft_putchar('\n');
		pthread_mutex_unlock(&phil->params->output_mutex);
	}
}
