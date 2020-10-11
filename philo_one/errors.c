/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:26:14 by casteria          #+#    #+#             */
/*   Updated: 2020/10/08 23:43:10 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			print_error(t_errors error)
{
	if (error == BAD_ARGS)
		ft_putstr("Error.\nWrong number of arguments.\n");
	return (error);
}