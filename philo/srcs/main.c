/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:07:05 by laube             #+#    #+#             */
/*   Updated: 2021/08/02 14:04:42 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

void	free_stuff(t_philos **philos)
{
	int	phils_num;
	int	i;

	i = 0;
	phils_num = (*philos)->configs->phils_num;
	free((*philos)->configs->forks);
	free((*philos)->configs->queue);
	free((*philos)->configs);
	free(*philos);
}

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
		return (printf("Error: # of args is %d: should be 5 or 6.\n", argc));
	if (ft_atoi(argv[1]) <= 1)
		return (printf("Error: # of philosophers must be greater than 1.\n"));
	if (ft_atoi(argv[2]) < 1)
		return (printf("Error: time_to_die cannot be less than 1.\n"));
	if (ft_atoi(argv[3]) < 1)
		return (printf("Error: time_to_eat cannot be less than 1.\n"));
	if (ft_atoi(argv[4]) < 1)
		return (printf("Error: time_to_sleep cannot be less than 1.\n"));
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (printf("Error: must_eat_times cannot be less than 1.\n"));
	philos = init_philos(argc, argv);
	init_threads(philos);
	destroy_mutex(philos->configs->phils_num, philos->configs->f_mutex);
	destroy_mutex(1, philos->configs->mutex);
	free_stuff(&philos);
}
