/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vicious_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:42:07 by casteria          #+#    #+#             */
/*   Updated: 2020/10/19 23:25:06 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int			check_death(t_philosopher *phil)
{
	long long		current_time;

	current_time = phil->thread_time;
	if (current_time == TIME)
		return (TIME);
	if (current_time - phil->eat_last_time > (long long)phil->params->args.time_to_die)
	{
		print_status(phil, get_proc_time(phil->params), phil->index, "died");
		return (DIED);
	}
	return (ALIVE);
}

static int			repeat(t_philosopher *phil)
{
	int				status;

	status = 0;
	status = check_death(phil);
	if (status)
		return (status);
	print_status(phil, get_proc_time(phil->params), phil->index, "is thinking");
	return (status);
}

static int			sleeep(t_philosopher *phil)
{
	int				status;

	status = 0;
	print_status(phil, get_proc_time(phil->params), phil->index, "is sleeping");
	status = usleep(phil->params->args.time_to_sleep * 1000);
	phil->thread_time = get_proc_time(phil->params);
	return (status);
}

static int			eat(t_philosopher *phil)
{
	int				status;
	status = 0;

	if (pthread_mutex_lock(&phil->left_hand->mutex))
		return (MUTEX_LOCK);
	if (pthread_mutex_lock(&phil->right_hand->mutex))
		return (MUTEX_LOCK); // check death here
	phil->thread_time = get_proc_time(phil->params);
	if (check_death(phil))
		return (DIED);
	print_status(phil, phil->thread_time, phil->index, "has taken a fork");
	print_status(phil, phil->thread_time, phil->index, "has taken a fork");
	print_status(phil, phil->thread_time, phil->index, "is eating");
	if ((phil->eat_last_time = phil->thread_time) == TIME)
		return (TIME);
	if (usleep(phil->params->args.time_to_eat * 1000))
		return (SLEEP);
	phil->thread_time = get_proc_time(phil->params);
	if (pthread_mutex_unlock(&phil->right_hand->mutex))
		return (MUTEX_UNLOCK);
	if (pthread_mutex_unlock(&phil->left_hand->mutex))
		return (MUTEX_UNLOCK);
 // check how much philosopher eat
	return (status);
}

void				*vicious_circle(void *arg)
{
	t_philosopher	*phil;

	phil = (t_philosopher *)arg;
	phil->ret_val = 0;
	if ((phil->eat_last_time = get_time()) == TIME)
	{
		phil->ret_val = TIME;
		pthread_exit(NULL);
	}
	while (ETERNITY_OF_PAINFUL_EXISTANCE)
	{
		if ((phil->ret_val = eat(phil)))
			pthread_exit(NULL);
		if ((phil->ret_val = sleeep(phil)))
			pthread_exit(NULL);
		if ((phil->ret_val = repeat(phil)))
			pthread_exit(NULL);
	}
	return (NULL);
} // to set status return
