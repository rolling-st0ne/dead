/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vicious_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:42:07 by casteria          #+#    #+#             */
/*   Updated: 2020/10/18 03:34:31 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int			check_death(t_philosopher *phil)
{
	long long		current_time;

	current_time = get_time();
	if (current_time == TIME)
		return (TIME);
	if (current_time - phil->eat_last_time > (long long)phil->params->args.time_to_die * 1000)
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
	return (status);
}

static int			eat(t_philosopher *phil)
{
	int				status;

	status = 0;
	while (!(phil->left_hand->status == IS_FREE && phil->right_hand->status == IS_FREE))
		if ((status = check_death(phil)))
			return (status);
	phil->left_hand->status = IS_BUSY;
	phil->right_hand->status = IS_BUSY;
	if ((status = pthread_mutex_lock(&phil->left_hand->mutex)))
		return (MUTEX_LOCK);
	if ((status = pthread_mutex_lock(&phil->right_hand->mutex)))
		return (MUTEX_LOCK);
	print_status(phil, get_proc_time(phil->params), phil->index, "has taken a fork");
	print_status(phil, get_proc_time(phil->params), phil->index, "has taken a fork");
	print_status(phil, get_proc_time(phil->params), phil->index, "is eating");
	if (usleep(phil->params->args.time_to_eat * 1000))
		return (SLEEP);
	if ((phil->eat_last_time = get_time()) == TIME)
		return (TIME);
	if ((status = pthread_mutex_unlock(&phil->right_hand->mutex)))
		return (MUTEX_UNLOCK);
	if ((status = pthread_mutex_unlock(&phil->left_hand->mutex)))
		return (MUTEX_UNLOCK);
	phil->left_hand->status = IS_FREE;
	phil->right_hand->status = IS_FREE;	
 // check how much philosopher eat
	return (status);
}

void				*vicious_circle(void *arg)
{
	int				*status;
	t_philosopher	*phil;

	if (!(status = malloc(sizeof(int))))
		pthread_exit(NULL);
	*status = 0;
	phil = (t_philosopher *)arg;
	while (ETERNITY_OF_PAINFUL_EXISTANCE)
	{
		if ((*status = eat(phil)))
		{
			printf("lol, u died %d\n", *status);
			pthread_exit(status);
		}
		if ((*status = sleeep(phil)))
			pthread_exit(status);
		if ((*status = repeat(phil)))
			pthread_exit(status);
		/*
		status = eat(phil);
		status = sleeep(phil);
		status = repeat(phil);
		*/
	}
	pthread_exit(NULL);
	return (NULL);
} // to set status return
