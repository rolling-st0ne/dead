/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 00:26:57 by casteria          #+#    #+#             */
/*   Updated: 2020/10/13 23:08:53 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int			analyze_input_data(int argc, char **argv)
{
	int				index;

	if (argc < 5 || argc > 6)
		return (print_error(BAD_ARGS));
	index = 1;
	while (index < argc)
	{
		if (ft_atoi(argv[index]) <= 0)
			return (print_error(BAD_ARGS));
		index++;
	}
	if (ft_atoi(argv[1]) < 2)
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
	philosophers->params.args.number_of_philosophers = ft_atoi(argv[1]);
	philosophers->params.args.time_to_die = ft_atoi(argv[2]);
	philosophers->params.args.time_to_sleep = ft_atoi(argv[3]);
	if (argv[4])
		philosophers->params.args.number_of_times_each_philosopher_must_eat = \
			ft_atoi(argv[4]);
	else
		philosophers->params.args.number_of_times_each_philosopher_must_eat = -1;
	return (status);
}

static int			create_philosopher(t_philosopher **philosopher, int index)
{
	*philosopher = (t_philosopher *)malloc(sizeof(t_philosopher));
	if (*philosopher == NULL)
		return (FAIL);
	(*philosopher)->index = ++index;
	return (SUCCESS);
}

static int			set_philosophers(t_philosophers *philosophers)
{
	int				index;
	int				count;

	count = philosophers->params.args.number_of_philosophers;
	philosophers->philosophers = malloc(sizeof(t_philosopher*) * (count + 1));
	if (philosophers->philosophers == NULL)
		return (FAIL);
	index = 0;
	while (index < count)
	{
		if (create_philosopher(&philosophers->philosophers[index], index) == FAIL)
			return (FAIL);
		index++;
	}
	philosophers->philosophers[index] = NULL;
	return (SUCCESS);
}

int					init(int argc, char **argv, t_philosophers *philosophers)
{
	int				status;

	status = get_data(argc, argv, philosophers);
	if (status)
		return (status);
	philosophers->params.forks = philosophers->params.args.number_of_philosophers;
	status = set_philosophers(philosophers);
	return (status);
}
