/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:18:44 by casteria          #+#    #+#             */
/*   Updated: 2020/10/18 16:10:46 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int						start(t_philosophers *p)
{
	size_t				index;
	t_philosopher		*phil;
	int					status;

	index = 0;
	status = 0;
	status = gettimeofday(&p->params.s_time, NULL);
	if (status)
		return (TIME);
	while (index < p->params.args.number_of_philosophers)
	{
		phil = p->philosophers[index];
		status = pthread_create(&p->philosophers[index]->id, NULL, vicious_circle, phil);
		if (status)
			return (THREAD_INIT);
		index++;
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
	while (ETERNITY_OF_PAINFUL_EXISTANCE)
	{
		philosopher = p->philosophers[index++];
		if (philosopher->ret_val)
			return (philosopher->ret_val);
		if (index == p->params.args.number_of_philosophers)
			index = 0;
	}
	return (status);
}

int						main(int argc, char **argv) // helgrind
{
	t_philosophers	philosophers;
	int				exec_failed;

	exec_failed = 0;
	exec_failed = init(argc, argv, &philosophers);
	if (exec_failed)
		return (print_error(exec_failed) + clean(&philosophers));
	exec_failed = start(&philosophers);
	if (exec_failed)
		return (print_error(exec_failed) + clean(&philosophers));
	exec_failed = wait_till_death(&philosophers);
	clean(&philosophers);
	return (exec_failed ? print_error(exec_failed) : SUCCESS); //do i actualy need index in forks?
}

// seg fault if bad args (in clean)