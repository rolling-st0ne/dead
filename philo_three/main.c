/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:18:44 by casteria          #+#    #+#             */
/*   Updated: 2020/10/31 18:14:21 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
		phil->id = fork();
		if (phil->id == 0)
			vicious_circle((void *)phil);
		index++;
	}
	waitpid(-1, &status, 0);
	return (status);
}

int						wait_till_death(t_philosophers *p)
{
	size_t				index;
	t_philosopher		*phil;

	index = 0;
	while (index < p->params.args.number_of_philosophers)
	{
		phil = p->philosophers[index];
		kill(phil->id, SIGINT);
		index++;
	}
	return (SUCCESS);
}

int						main(int argc, char **argv)
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
	exec_failed = usleep(100000);
	clean(&philosophers);
	return (exec_failed ? print_error(exec_failed) : SUCCESS);
}
