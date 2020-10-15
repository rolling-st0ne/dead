/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 00:15:15 by casteria          #+#    #+#             */
/*   Updated: 2020/10/16 01:16:59 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void			free_philosophers(t_philosopher **darray)
{
	size_t			index;

	index = 0;
	while (darray[index])
	{
	//	if (darray[index]->err_status)
	//	free(darray[index]->err_status);
		free(darray[index]);
		index++;
	}
	free(darray);
}

static void			free_forks(t_fork **forks)
{
	size_t			index;

	index = 0;
	while (forks[index])
	{
		pthread_mutex_destroy(&forks[index]->mutex); // still reachable leaks
		free(forks[index]);
		index++;
	}
	free(forks);
}

int					clean(t_philosophers *p)
{
	if (p->philosophers)
		free_philosophers(p->philosophers);
	if (p->params.forks)
		free_forks(p->params.forks);
	return (SUCCESS);
}
