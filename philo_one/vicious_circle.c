/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vicious_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:42:07 by casteria          #+#    #+#             */
/*   Updated: 2020/10/14 00:37:58 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"


static int			eat(t_thread_info *p)
{
	int				status;

	status = 0;
	(void)p;
//	if (p->params.forks < 2)
	return (0);
}

static int			try_not_to_die(t_thread_info *p)
{
	int				status;

	status = 0;
	printf("time: %lld\n", get_time() - p->params->s_time);
	eat(p);
//	sleeep(p);
//	repeat(p);
//	while (eat(p)
	return (0);
}

void				*vicious_circle(void *arg)
{
	int				status;

	status = 0;
	while (ETERNITY_OF_PAINFUL_EXISTANCE)
		try_not_to_die(((t_thread_info *)arg));
	pthread_exit(NULL);
	return (NULL);
}
