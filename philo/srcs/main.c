/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:07:05 by laube             #+#    #+#             */
/*   Updated: 2021/07/31 00:06:54 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

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
		forks[i++] = 1;
	return (forks);
}

unsigned int	get_time(void)
{
	struct timeval	time;
	unsigned int	milli_time;

	gettimeofday(&time, NULL);
	milli_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (milli_time);
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
	configs->start_time = get_time();
	pthread_mutex_init(&configs->mutex, NULL);
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
	t_configs	*conf;
	t_philos	*phil;

	phil = (struct s_philos *)philo;
	conf = phil->configs;

	while (1)
	{
		pthread_mutex_lock(&conf->mutex);

		// To eat
		if (phil->state == 't' && conf->forks[phil->id])
		{
			if (conf->forks[(phil->id + 1) % conf->phils_num])
			{
				conf->forks[phil->id] = 0;
				conf->forks[(phil->id + 1) % conf->phils_num] = 0;
				printf("%d %d has taken the left and right fork\n", get_time() - conf->start_time, phil->id + 1);
				phil->state = 'e';
				printf("%d %d is eating\n", get_time() - conf->start_time, phil->id + 1);
				phil->state_time = get_time();
			}
		}
		// To sleep
		if (phil->state == 'e' && get_time() - phil->state_time >= conf->eat_time)
		{
			conf->forks[phil->id] = 1;
			conf->forks[(phil->id + 1) % conf->phils_num] = 1;
			phil->state = 's';
			printf("%d %d is sleeping\n", get_time() - conf->start_time, phil->id + 1);
		}
		pthread_mutex_unlock(&conf->mutex);
	}
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
	pthread_mutex_destroy(&philos->configs->mutex);
}
