/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:18:44 by casteria          #+#    #+#             */
/*   Updated: 2020/10/08 23:41:30 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (print_error(BAD_ARGS));
	(void)argv;
	return (SUCCESS);
}