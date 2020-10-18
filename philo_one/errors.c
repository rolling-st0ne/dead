/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:26:14 by casteria          #+#    #+#             */
/*   Updated: 2020/10/18 05:15:28 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

short int	is_error(int val)
{
	if ((val >= BAD_ARGS && val <= SLEEP) || val == FAIL) // do i need it?
		return (TRUE);
	return (FALSE);
}

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
	else if (error == MUTEX_LOCK)
		ft_putstr("Error.\nMutex lock failed.\n");
	else if (error == MUTEX_UNLOCK)
		ft_putstr("Error.\nMutex unlock failed.\n");
	return (error);
}