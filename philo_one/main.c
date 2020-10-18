/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:18:44 by casteria          #+#    #+#             */
/*   Updated: 2020/10/18 03:28:05 by casteria         ###   ########.fr       */
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
	p->params.s_time = get_time();
	if (p->params.s_time == TIME)
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
	while (index < p->params.args.number_of_philosophers)
	{
		philosopher = p->philosophers[index++];
		status = pthread_join(philosopher->id, (void **)&philosopher->ret_val);
		if (status)
			return (THREAD_JOIN);
		if (philosopher->ret_val == NULL)
			return (MALLOC);
		else if (is_error(*philosopher->ret_val))
			return (*philosopher->ret_val);
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

// work with err_status in t_philosopher