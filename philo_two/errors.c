/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:26:14 by casteria          #+#    #+#             */
/*   Updated: 2020/10/30 02:03:36 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

short int	is_error(int val)
{
	if ((val >= BAD_ARGS && val <= SLEEP) || val == FAIL)
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
	else if (error == SEM_OPEN)
		ft_putstr("Error.\nSemaphore open failed.\n");
	else if (error == SEM_CLOSE)
		ft_putstr("Error.\nSemaphore close failed.\n");
	else if (error == SEM_UNLINK)
		ft_putstr("Error.\nSemaphore unlink failed.\n");
	else if (error == SEM_POST)
		ft_putstr("Error.\nSemaphore post failed.\n");
	else if (error == SEM_WAIT)
		ft_putstr("Error.\nSemaphore wait failed.\n");
	else if (error == TIME)
		ft_putstr("Error.\nTime get failed.\n");
	else if (error == SLEEP)
		ft_putstr("Error.\nSleep failed.\n");
	return (error);
}
