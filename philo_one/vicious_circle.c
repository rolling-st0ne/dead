/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vicious_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:42:07 by casteria          #+#    #+#             */
/*   Updated: 2020/10/16 01:48:47 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int			eat(t_philosopher *phil)
{
	int				status;

	status = 0;
	(void)phil;
//	if (p->params.forks < 2)
	return (0);
}

void				*vicious_circle(void *arg)
{
	int				status;
	t_philosopher	*phil;

	status = 0;
	phil = (t_philosopher *)arg;
	while (ETERNITY_OF_PAINFUL_EXISTANCE)
	{
		status = eat(phil);
	}
	printf("OK, ama philo number %d\n", phil->index);
	pthread_exit(NULL);
	return (NULL);
}
