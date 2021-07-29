/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:07:05 by laube             #+#    #+#             */
/*   Updated: 2021/07/29 00:37:38 by laube            ###   ########.fr       */
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

t_philos	*init_philos(int phil_num)
{
	t_philos	*philos;
	int			i;

	philos = malloc(sizeof(t_philos) * phil_num);
	i = 0;
	while (i < phil_num)
	{
		philos[i].state = 't';
		philos[i].holds_left = 0;
		philos[i].holds_right = 0;
		i++;
	}
	return (philos);
}

t_configs	*init_configs(int argc, char **argv)
{
	t_configs	*configs;
	int			i;

	i = 0;
	configs = malloc(sizeof(t_configs));
	configs->phil_num = ft_atoi(argv[1]);
	configs->die_time = ft_atoi(argv[2]);
	configs->eat_time = ft_atoi(argv[3]);
	configs->sleep_time = ft_atoi(argv[4]);
	configs->eat_num = 0;
	configs->eat_num_active = 0;
	configs->philos = init_philos(ft_atoi(argv[1]));
	if (argc == 6)
	{
		configs->eat_num = ft_atoi(argv[5]);
		configs->eat_num_active = 1;
	}
	return (configs);
}

void	*routine(void *nothing)
{
	printf("threadID: %p\n", pthread_self());
	return (NULL);
}

int	init_threads(t_configs *configs)
{
	int	i;
	pthread_t tid;

	i = 0;
	while (i < configs->phil_num)
	{
		if (pthread_create(&tid, NULL, &routine, NULL) != 0)
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_configs	*configs;

	
	if (argc != 5 && argc != 6)
		return (printf("Number of args is %d: should be 5 or 6\n", argc));
	configs = init_configs(argc, argv);
	init_threads(configs);
}
