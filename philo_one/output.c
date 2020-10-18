/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:37:59 by casteria          #+#    #+#             */
/*   Updated: 2020/10/18 02:43:49 by casteria         ###   ########.fr       */
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

void				print_status(t_philosopher *phil, long long time, int index, char *status)
{
	// to lock mutex that's already exists
	pthread_mutex_lock(&phil->params->output_mutex);
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(index);
	ft_putchar(' ');
	ft_putstr((const char *)status);
	ft_putchar('\n');
	pthread_mutex_unlock(&phil->params->output_mutex);//check how its worked
}
