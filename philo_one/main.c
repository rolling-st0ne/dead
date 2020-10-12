/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:18:44 by casteria          #+#    #+#             */
/*   Updated: 2020/10/12 03:21:26 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			main(int argc, char **argv)
{
	t_philosophers	philosophers;
	int				exec_failed;

	exec_failed = 0;
	exec_failed = init(argc, argv, &philosophers);
	if (exec_failed)
		return (exec_failed);
//	exec_failed = vicious_circle(philosophers);
	
	return (SUCCESS);
}