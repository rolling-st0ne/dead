/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 00:26:57 by casteria          #+#    #+#             */
/*   Updated: 2020/10/22 22:17:32 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int			analyze_input_data(int argc, char **argv)
{
	int				index;

	if (argc < 5 || argc > 6)
		return (BAD_ARGS);
	index = 1;
	while (index < argc)
	{
		if (ft_atoi(argv[index]) <= 0)
			return (BAD_ARGS);
		index++;
	}
	if (ft_atoi(argv[1]) < 2)
		return (BAD_ARGS);
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
	philosophers->params.args.time_to_eat = ft_atoi(argv[3]);
	philosophers->params.args.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philosophers->params.args.number_of_times_each_philosopher_must_eat = \
			ft_atoi(argv[5]);
	else
		philosophers->params.args.number_of_times_each_philosopher_must_eat = -1;
	return (status);
}

static int			create_philosopher(t_philosophers *p, int index)
{
	t_philosopher	**phil;

	phil = &p->philosophers[index];
	*phil = (t_philosopher *)malloc(sizeof(t_philosopher));
	// (*philosopher)->err_status = malloc(sizeof(int));
	if (*phil == NULL)
		return (MALLOC);
	(*phil)->params = &p->params;
	(*phil)->index = ++index;
	(*phil)->ret_val = 0;
	(*phil)->eaten = 0;
	assign_forks(p, index);
	(*phil)->eat_times = 0;
	return (SUCCESS);
}

static int			set_philosophers(t_philosophers *philosophers)
{
	int				index;
	int				count;
	int				status;

	status = 0;
	count = philosophers->params.args.number_of_philosophers;
	philosophers->philosophers = malloc(sizeof(t_philosopher*) * (count + 1));
	if (philosophers->philosophers == NULL)
		return (MALLOC);
	index = 0;
	while (index < count)
	{
		if ((status = create_philosopher(philosophers, index)))
			return (status);
		index++;
	}
	philosophers->philosophers[index] = NULL;
	return (SUCCESS);
}

int					init(int argc, char **argv, t_philosophers *philosophers)
{
	int				status;

	philosophers->philosophers = NULL;
	philosophers->params.forks = NULL;
	status = get_data(argc, argv, philosophers);
	if (status)
		return (status);
//	philosophers->params.forks = philosophers->params.args.number_of_philosophers;
	set_forks(philosophers);
	status = set_philosophers(philosophers);
	pthread_mutex_init(&philosophers->params.output_mutex, NULL); // output mutex
	return (status);
}
