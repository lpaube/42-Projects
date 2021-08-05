/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:55:31 by laube             #+#    #+#             */
/*   Updated: 2021/08/05 11:15:38 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

void	perform_eat(t_configs *conf, t_philos *phil)
{
	conf->forks[phil->id] = 0;
	print_msg('f', get_time() - conf->start_time, phil->id + 1);
	conf->forks[(phil->id + 1) % conf->phils_num] = 0;
	print_msg('f', get_time() - conf->start_time, phil->id + 1);
	phil->state = 'e';
	phil->ate_num++;
	print_msg('e', get_time() - conf->start_time, phil->id + 1);
	phil->last_meal_time = get_time();
}

void	to_eat(t_configs *conf, t_philos *phil)
{
	if (phil->state == 't')
	{
		pthread_mutex_lock(&conf->f_mutex[phil->id]);
		pthread_mutex_lock(&conf->f_mutex[(phil->id + 1) % conf->phils_num]);
		if (conf->forks[phil->id]
			&& conf->forks[(phil->id + 1) % conf->phils_num])
		{
			if (check_queue(phil, conf) == 1)
				perform_eat(conf, phil);
		}
		else
			get_in_queue(phil, conf);
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
	if (phil->state == 'e' && get_time()
		- phil->last_meal_time >= conf->eat_time)
	{
		conf->forks[phil->id] = 1;
		conf->forks[(phil->id + 1) % conf->phils_num] = 1;
		phil->state = 's';
		print_msg('s', get_time() - conf->start_time, phil->id + 1);
		phil->state_time = get_time();
	}
}

void	to_think(t_configs *conf, t_philos *phil)
{
	if (phil->state == 's' && get_time()
		- phil->state_time >= conf->sleep_time)
	{
		phil->state = 't';
		print_msg('t', get_time() - conf->start_time, phil->id + 1);
	}
}

void	to_die(t_configs *conf, t_philos *phil)
{
	if (get_time() - phil->last_meal_time >= conf->die_time)
	{
		phil->state = 'd';
		conf->gameover = 1;
		print_msg('d', get_time() - conf->start_time, phil->id + 1);
	}
}
