/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 00:15:15 by casteria          #+#    #+#             */
/*   Updated: 2020/10/31 16:41:33 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void			free_philosophers(t_philosopher **darray)
{
	size_t			index;

	index = 0;
	while (darray[index])
	{
		free(darray[index]);
		index++;
	}
	free(darray);
}

int					clean(t_philosophers *p)
{
	if (p->philosophers)
		free_philosophers(p->philosophers);
	if (sem_close(p->params.forks))
		return (SEM_CLOSE);
	if (sem_unlink("/forks"))
		return (SEM_UNLINK);
	if (sem_close(p->params.eating))
		return (SEM_CLOSE);
	if (sem_unlink("/eating"))
		return (SEM_UNLINK);
	return (SUCCESS);
}
