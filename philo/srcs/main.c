/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:07:05 by laube             #+#    #+#             */
/*   Updated: 2021/07/30 16:33:04 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int	ft_atoi(const char *str)
{
	int	curr_num;
	int	state;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	state = 1;
	curr_num = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			state = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		curr_num = (curr_num * 10) + (*str - '0');
		str++;
	}
	return (curr_num * state);
}


int	*init_forks(int	num)
{
	int	i;
	int	*forks;

	forks = malloc(sizeof(int) * num);
	i = 0;
	while (i < num)
		forks[i++] = 0;
	return (forks);
}

t_configs	*init_configs(int argc, char **argv)
{
	t_configs	*configs;
	int			i;

	i = 0;
	configs = malloc(sizeof(t_configs));
	configs->phils_num = ft_atoi(argv[1]);
	configs->forks_num = configs->phils_num + 1;
	configs->die_time = ft_atoi(argv[2]);
	configs->eat_time = ft_atoi(argv[3]);
	configs->sleep_time = ft_atoi(argv[4]);
	configs->eat_num = 0;
	configs->eat_num_active = 0;
	configs->forks = init_forks(configs->phils_num + 1);
	if (argc == 6)
	{
		configs->eat_num = ft_atoi(argv[5]);
		configs->eat_num_active = 1;
	}
	return (configs);
}

void	*init_philos(int argc, char **argv)
{
	t_philos	*philos;
	t_configs	*configs;
	int			i;

	configs = init_configs(argc, argv);
	philos = malloc(sizeof(t_philos) * configs->phils_num);
	i = 0;
	while (i < configs->phils_num)
	{
		philos[i].state = 't';
		philos[i].id = i;
		philos[i].holds_left = 0;
		philos[i].holds_right = 0;
		philos[i].configs = configs;
		i++;
	}
	return (philos);
}

void	*routine(void *philo)
{
	printf("id of philo: %d\n", ((struct s_philos *)philo)->id);
	return (NULL);
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
	return (0);
}

int	main(int argc, char **argv)
{
	t_philos	*philos;

	if (argc != 5 && argc != 6)
		return (printf("Number of args is %d: should be 5 or 6\n", argc));
	philos = init_philos(argc, argv);
	init_threads(philos);
}
