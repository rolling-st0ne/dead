/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vicious_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:42:07 by casteria          #+#    #+#             */
/*   Updated: 2020/10/18 20:20:29 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int			check_death(t_philosopher *phil)
{
	struct timeval	current_time;

	if ((gettimeofday(&current_time, NULL)))
		return (TIME);
//	printf("diff: %zu\n", cast_time(&current_time) - cast_time(&phil->eat_last_time));
	if (cast_time(&current_time) - cast_time(&phil->eat_last_time) > phil->params->args.time_to_die)
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
	size_t			current_time;

	status = 0;
	while (!(phil->left_hand->status == IS_FREE && phil->right_hand->status == IS_FREE)); //
	if ((status = check_death(phil)))
		return (status);
	phil->left_hand->status = IS_BUSY;
	phil->right_hand->status = IS_BUSY;
	if ((status = pthread_mutex_lock(&phil->left_hand->mutex)))
		return (MUTEX_LOCK);
	if ((status = pthread_mutex_lock(&phil->right_hand->mutex)))
		return (MUTEX_LOCK);
	current_time = get_proc_time(phil->params);
	print_status(phil, current_time, phil->index, "has taken a fork");
	print_status(phil, current_time, phil->index, "has taken a fork");
	print_status(phil, current_time, phil->index, "is eating");
	if (gettimeofday(&phil->eat_last_time, NULL))
		return (TIME);
	if (usleep(phil->params->args.time_to_eat * 1000))
		return (SLEEP);
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
	t_philosopher	*phil;

	phil = (t_philosopher *)arg;
	phil->ret_val = 0;
	if (gettimeofday(&phil->eat_last_time, NULL))
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
