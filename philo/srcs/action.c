/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:55:31 by laube             #+#    #+#             */
/*   Updated: 2021/08/01 00:50:03 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

void	get_in_queue(t_philos *phil)
{
	int	i;
	int	tmp;
	int *queue;

	queue = phil->configs->queue;
	i = 0;
	while (i < phil->configs->phils_num)
	{
		if (phil->id == queue[i++])
			return ;
	}
	i = phil->configs->phils_num - 1;
	while (i > 0)
	{
		queue[i] = queue[i - 1];
		i--;
	}
	queue[0] = phil->id;
}

int	check_queue(t_philos *phil)
{

}

void	to_eat(t_configs *conf, t_philos *phil)
{
	if (phil->state == 't')
	{
		pthread_mutex_lock(&conf->f_mutex[phil->id]);
		pthread_mutex_lock(&conf->f_mutex[(phil->id + 1) % conf->phils_num]);
		if (conf->forks[phil->id] && conf->forks[(phil->id + 1) % conf->phils_num])
		{
			if (check_queue(phil) == 0)
				return ;
			conf->forks[phil->id] = 0;
			printf("%d %d has taken a fork\n", get_time() - conf->start_time, phil->id + 1);
			conf->forks[(phil->id + 1) % conf->phils_num] = 0;
			printf("%d %d has taken a fork\n", get_time() - conf->start_time, phil->id + 1);
			phil->state = 'e';
			phil->ate_num++;
			printf("%d %d is eating\n", get_time() - conf->start_time, phil->id + 1);
			phil->last_meal_time = get_time();
		}
		else
			get_in_queue(phil);
		pthread_mutex_unlock(&conf->f_mutex[phil->id]);
		pthread_mutex_unlock(&conf->f_mutex[(phil->id + 1) % conf->phils_num]);
		if (meal_quota(conf))
		{
			conf->gameover = 1;
			return ;
		}
	}
}

void	to_sleep(t_configs *conf, t_philos *phil)
{
	if (phil->state == 'e' && get_time() - phil->last_meal_time >= conf->eat_time)
	{
		conf->forks[phil->id] = 1;
		conf->forks[(phil->id + 1) % conf->phils_num] = 1;
		phil->state = 's';
		printf("%d %d is sleeping\n", get_time() - conf->start_time, phil->id + 1);
		phil->state_time = get_time();
	}
}

void	to_think(t_configs *conf, t_philos *phil)
{
	if (phil->state == 's' && get_time() - phil->state_time >= conf->sleep_time)
	{
		phil->state = 't';
		printf("%d %d is thinking\n", get_time() - conf->start_time, phil->id + 1);
	}
}

void	to_die(t_configs *conf, t_philos *phil)
{
	if (get_time() - phil->last_meal_time >= conf->die_time)
	{
		phil->state = 'd';
		conf->gameover = 1;
		printf("%d %d died\n", get_time() - conf->start_time, phil->id + 1);
	}
}

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
