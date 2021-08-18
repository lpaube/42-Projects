/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:14:08 by laube             #+#    #+#             */
/*   Updated: 2021/08/18 01:26:32 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

void	*routine(void *philo)
{
	t_configs	*conf;
	t_philos	*phil;

	phil = (struct s_philos *)philo;
	conf = phil->configs;
	while (1)
	{
		pthread_mutex_lock(conf->mutex);
		if (conf->gameover == 1)
		{
			pthread_mutex_unlock(conf->mutex);
			return (NULL);
		}
		to_eat(conf, phil);
		to_sleep(conf, phil);
		to_think(conf, phil);
		to_die(conf, phil);
		pthread_mutex_unlock(conf->mutex);
	}
	return (NULL);
}

void	get_in_queue(t_philos *phil, t_configs *conf)
{
	int	i;

	i = 0;
	while (i < conf->phils_num)
	{
		if (phil->id == conf->queue[i])
			return ;
		else if (conf->queue[i] == -1)
		{
			conf->queue[i] = phil->id;
			return ;
		}
		i++;
	}
}

int	check_queue(t_philos *phil, t_configs *conf)
{
	int	i;
	int	id;

	i = 0;
	while (i < conf->phils_num && conf->queue[i] != -1)
	{
		id = conf->queue[i];
		if (id == phil->id)
		{
			while (i < conf->phils_num - 1)
			{
				conf->queue[i] = conf->queue[i + 1];
				i++;
			}
			conf->queue[i] = -1;
			return (1);
		}
		if (conf->forks[id] && conf->forks[(id + 1) % conf->phils_num])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
