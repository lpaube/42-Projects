/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:46:19 by laube             #+#    #+#             */
/*   Updated: 2021/08/04 14:17:09 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

int	*init_forks(int	num)
{
	int	i;
	int	*forks;

	forks = malloc(sizeof(int) * num);
	i = 0;
	while (i < num)
		forks[i++] = 1;
	return (forks);
}

pthread_mutex_t	*init_mutex(int	num)
{
	pthread_mutex_t	*mutex;
	int				i;

	mutex = malloc(sizeof(pthread_mutex_t) * num);
	i = 0;
	while (i < num)
	{
		pthread_mutex_init(&mutex[i++], NULL);
	}
	return (mutex);
}

int	*init_queue(t_configs *conf)
{
	int	*queue;
	int	i;

	i = 0;
	queue = malloc(sizeof(int) * conf->phils_num);
	while (i < conf->phils_num)
		queue[i++] = -1;
	return (queue);
}

t_configs	*init_configs(int argc, char **argv)
{
	t_configs	*configs;
	int			i;

	i = 0;
	configs = malloc(sizeof(t_configs));
	configs->phils_num = ft_atoi(argv[1]);
	configs->die_time = ft_atoi(argv[2]);
	configs->eat_time = ft_atoi(argv[3]);
	configs->sleep_time = ft_atoi(argv[4]);
	configs->eat_num = 0;
	configs->eat_num_active = 0;
	configs->gameover = 0;
	configs->start_time = get_time();
	configs->f_mutex = init_mutex(configs->phils_num);
	configs->mutex = init_mutex(1);
	configs->forks = init_forks(configs->phils_num);
	configs->queue = init_queue(configs);
	if (argc == 6)
	{
		configs->eat_num = ft_atoi(argv[5]);
		configs->eat_num_active = 1;
	}
	return (configs);
}
