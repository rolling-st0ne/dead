/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vicious_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:42:07 by casteria          #+#    #+#             */
/*   Updated: 2020/10/30 00:08:53 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int			check_death(t_philosopher *phil)
{
	size_t			time;

	time = (size_t)((phil->thread_time.tv_sec - \
							phil->eat_last_time.tv_sec) * 1000
				+ (phil->thread_time.tv_usec - \
							phil->eat_last_time.tv_usec) * 0.001);
	if (time > phil->params->args.time_to_die)
	{
		print_status(phil, phil->thread_time, " died\n");
		return (DIED);
	}
	return (ALIVE);
}

static int			sleeep(t_philosopher *phil)
{
	int				status;

	status = 0;
	if (gettimeofday(&phil->thread_time, NULL))
		return (TIME);
	print_status(phil, phil->thread_time, " is sleeping\n");
	if (ft_sleep(phil->params->args.time_to_sleep, phil))
		return (TIME);
	status = check_death(phil);
	if (status)
		return (status);
	if (gettimeofday(&phil->thread_time, NULL))
		return (TIME);
	print_status(phil, phil->thread_time, " is thinking\n");
	return (status);
}

static int			eat(t_philosopher *phil)
{
	if (pthread_mutex_lock(&phil->left_hand->mutex))
		return (MUTEX_LOCK);
	if (pthread_mutex_lock(&phil->right_hand->mutex))
		return (MUTEX_LOCK);
	if (gettimeofday(&phil->thread_time, NULL))
		return (TIME);
	if (check_death(phil))
		return (DIED);
	print_status(phil, phil->thread_time, " has taken a fork\n");
	print_status(phil, phil->thread_time, " has taken a fork\n");
	print_status(phil, phil->thread_time, " is eating\n");
	if (gettimeofday(&phil->eat_last_time, NULL))
		return (TIME);
	if (ft_sleep(phil->params->args.time_to_eat, phil))
		return (TIME);
	if (pthread_mutex_unlock(&phil->right_hand->mutex))
		return (MUTEX_UNLOCK);
	if (pthread_mutex_unlock(&phil->left_hand->mutex))
		return (MUTEX_UNLOCK);
	if (++phil->eaten == \
		phil->params->args.number_of_times_each_philosopher_must_eat)
		return (FULL);
	return (SUCCESS);
}

void				*vicious_circle(void *arg)
{
	t_philosopher	*phil;

	phil = (t_philosopher *)arg;
	phil->ret_val = 0;
	if (gettimeofday(&phil->eat_last_time, NULL))
		phil->ret_val = TIME;
	else
	{
		while (ETERNITY_OF_PAINFUL_EXISTANCE)
		{
			if ((phil->ret_val = eat(phil)) || phil->params->stop_sign)
				break ;
			if ((phil->ret_val = sleeep(phil)) || phil->params->stop_sign)
				break ;
		}
	}
	return (NULL);
}
