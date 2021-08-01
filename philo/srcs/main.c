/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:07:05 by laube             #+#    #+#             */
/*   Updated: 2021/07/31 22:02:14 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

int	meal_quota(t_configs *conf)
{
	int	i;

	i = 0;
	while (i < conf->phils_num)
	{
		if (conf->philos[i].ate_num < conf->eat_num || !conf->eat_num_active)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_philos	*philos;

	if (argc != 5 && argc != 6)
		return (printf("Number of args is %d: should be 5 or 6\n", argc));
	philos = init_philos(argc, argv);
	init_threads(philos);
	destroy_mutex(philos->configs->phils_num, philos->configs->f_mutex);
	destroy_mutex(1, philos->configs->mutex);
}
