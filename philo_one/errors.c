/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:26:14 by casteria          #+#    #+#             */
/*   Updated: 2020/10/16 00:12:18 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			print_error(t_errors error)
{
	if (error == BAD_ARGS)
		ft_putstr("Error.\nBad args.\n");
	else if (error == FAIL)
		ft_putstr("Error.\nSomething went wrong.\n");
	else if (error == MALLOC)
		ft_putstr("Error.\nMalloc failed.\n");
	else if (error == MUTEX_INIT)
		ft_putstr("Error.\nMutex init failed.\n");
	else if (error == TIME)
		ft_putstr("Error.\nTime get failed.\n");
	else
		print_error(FAIL);
	
	return (error);
}