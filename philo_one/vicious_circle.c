/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vicious_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:42:07 by casteria          #+#    #+#             */
/*   Updated: 2020/10/13 00:36:52 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int						wait_till_death(t_philosophers *p)
{
	size_t				index;
	t_philosopher		*philosopher;
	int					status;

	index = 0;
	status = 0;
	while (index < p->params.number_of_philosophers)
	{
		philosopher = p->philosophers[index++];
		status = pthread_join(philosopher->id, (void **)&philosopher->err_status);
		if (status != 0)
			return (status);
	}
	return (status);
}

static void				*vicious_circle(void *arg)
{
	(void)arg;
	// eternal cycle of pain
	
	pthread_exit(0);
	return (NULL);
}

int						start(t_philosophers *p)
{
	size_t				index;
	t_philosopher		*phil;
	int					status;

	index = 0;
	status = 0;
	while (index < p->params.number_of_philosophers)
	{
		phil = p->philosophers[index++];
		status = pthread_create(&phil->id, NULL, vicious_circle, &p);
		if (status != 0)
			return (status);
	}
	return (status);
}
