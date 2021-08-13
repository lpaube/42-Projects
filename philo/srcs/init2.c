/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:16:44 by laube             #+#    #+#             */
/*   Updated: 2021/08/13 12:44:01 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

void	*init_philos(int argc, char **argv)
{
	t_philos	*philos;
	t_configs	*configs;
	int			i;

	configs = init_configs(argc, argv);
	philos = malloc(sizeof(t_philos) * configs->phils_num);
	configs->philos = philos;
	i = 0;
	while (i < configs->phils_num)
	{
		philos[i].state = 't';
		philos[i].id = i;
		philos[i].holds_left = 0;
		philos[i].holds_right = 0;
		philos[i].state_time = 0;
		philos[i].ate_num = 0;
		philos[i].last_meal_time = get_time();
		philos[i].configs = configs;
		i++;
	}
	return (philos);
}

int	init_threads(t_philos *philos)
{
	pthread_t	*tid;
	int			i;

	tid = malloc(sizeof(tid) * philos->configs->phils_num);
	i = 0;
	while (i < philos->configs->phils_num)
	{
		pthread_create(&tid[i], NULL, &routine, &philos[i]);
		i++;
	}
	i = 0;
	while (i < philos->configs->phils_num)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	free(tid);
	return (0);
}
