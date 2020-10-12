/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 00:26:57 by casteria          #+#    #+#             */
/*   Updated: 2020/10/12 03:32:49 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int			analyze_input_data(int argc, char **argv)
{
	size_t			index;

	if (argc < 5 || argc > 6)
		return (print_error(BAD_ARGS));
	index = 0;
	while (argv[index])
	{
		if (ft_atoi(argv[index]) <= 0)
			return (print_error(BAD_ARGS));
		index++;
	}
	if (ft_atoi(argv[2]) < 2)
		return (print_error(BAD_ARGS));
	return (SUCCESS);
}

static int			get_data(int argc, char **argv, \
												t_philosophers *philosophers)
{
	int				status;

	status = analyze_input_data(argc, argv);
	if (status != SUCCESS)
		return (status);
	philosophers->params.number_of_philosophers = ft_atoi(argv[1]);
	philosophers->params.time_to_die = ft_atoi(argv[2]);
	philosophers->params.time_to_sleep = ft_atoi(argv[3]);
	if (argv[4])
		philosophers->params.number_of_times_each_philosopher_must_eat = \
			ft_atoi(argv[4]);
	else
		philosophers->params.number_of_times_each_philosopher_must_eat = -1;
	return (status);
}

static int			create_philosopher(t_philosopher *philosopher)
{
	philosopher = malloc(sizeof(t_philosopher));
	if (philosopher == NULL)
		return (FAIL);
}

static int			set_philosophers(t_philosophers *philosophers)
{
	size_t			index;
	int				count;

	count = philosophers->params.number_of_philosophers;
	philosophers->philosophers = malloc(sizeof(t_philosopher*) * (count + 1));
	if (philosophers->philosophers == NULL)
		return (FAIL);
	index = 0;
	while (index < count)
		if (create_philosopher(philosophers->philosophers[index++]) == FAIL)
			return (FAIL);
	philosophers->philosophers[index] = NULL;
}

int					init(int argc, char **argv, t_philosophers *philosophers)
{
	int				status;

	status = get_data(argc, argv, philosophers);
	if (status)
		return (status);
	status = set_philosophers(philosophers);
	return (status);
}
