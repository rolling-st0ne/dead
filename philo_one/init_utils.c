/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 23:51:16 by casteria          #+#    #+#             */
/*   Updated: 2020/10/19 19:19:22 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int			create_fork(t_fork **fork, int index)
{
	int				status;

	status = 0;
	*fork = malloc(sizeof(t_fork));
	if (!(*fork))
		return (MALLOC);
	(*fork)->index = index;
	(*fork)->status = IS_FREE;
	status = pthread_mutex_init(&(*fork)->mutex, NULL);
	if (status)
		return (MUTEX_INIT);
	return (status);
}

int					set_forks(t_philosophers *p)
{
	int				status;
	size_t			count;
	size_t			index;

	status = 0;
	count = p->params.args.number_of_philosophers;
	p->params.forks = malloc((count + 1) * sizeof(t_fork *));
	if (!p->params.forks)
		return (MALLOC);
	index = 0;
	while (index < count)
	{
		status = create_fork(&p->params.forks[index], index);
		if (status)
			return (status);
		index++;
	}
	p->params.forks[index] = NULL;
	return (status);
}

void				assign_forks(t_philosophers *p, int index)
{
	t_philosopher	*phil;
	size_t			count;

	count = 0;
	count = p->params.args.number_of_philosophers;
	phil = p->philosophers[index - 1];
	if (index == 1)
	{
		phil->left_hand = p->params.forks[count - 1];
		phil->right_hand = p->params.forks[0];
	}
	else
	{
		phil->left_hand = p->params.forks[index - 2];
		phil->right_hand = p->params.forks[index - 1];
	}
}
