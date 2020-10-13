/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:18:44 by casteria          #+#    #+#             */
/*   Updated: 2020/10/14 00:36:47 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int						start(t_philosophers *p)
{
	size_t				index;
	t_philosopher		*phil;
	int					status;
	t_thread_info		info;

	index = 0;
	status = 0;
	p->params.s_time = get_time();
	if (p->params.s_time == FAIL)
		return (FAIL);
	while (index < p->params.args.number_of_philosophers)
	{
		phil = p->philosophers[index++];
		info.params = &p->params;
		info.philo = &phil;
		status = pthread_create(&phil->id, NULL, vicious_circle, &info);
		if (status != 0)
			return (status);
	}
	return (status);
}

int						wait_till_death(t_philosophers *p)
{
	size_t				index;
	t_philosopher		*philosopher;
	int					status;

	index = 0;
	status = 0;
	while (index < p->params.args.number_of_philosophers)
	{
		philosopher = p->philosophers[index++];
		status = pthread_join(philosopher->id, (void **)&philosopher->err_status);
		if (status != 0)
			return (status);
	}
	return (status);
}

int						main(int argc, char **argv)
{
	t_philosophers	philosophers;
	int				exec_failed;

	exec_failed = 0;
	exec_failed = init(argc, argv, &philosophers);
	if (exec_failed)
		return (exec_failed);
	exec_failed = start(&philosophers);
	if (exec_failed)
		return (exec_failed);
	exec_failed = wait_till_death(&philosophers);
	return (exec_failed ? exec_failed : SUCCESS);
}
