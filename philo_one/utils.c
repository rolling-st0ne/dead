/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:35:51 by casteria          #+#    #+#             */
/*   Updated: 2020/10/08 23:38:46 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			ft_putstr(const char *str)
{
	char		*ptr;

	ptr = (char *)str;
	while (ptr && *ptr)
		write(STD_OUT, ptr++, 1);
}