/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:55:24 by laube             #+#    #+#             */
/*   Updated: 2021/07/31 23:19:18 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct s_configs t_configs;
typedef struct s_philos t_philos;

struct	s_configs
{
	unsigned int	start_time;
	int	phils_num;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	eat_num;
	int	eat_num_active;
	int	gameover;
	pthread_mutex_t	*f_mutex;
	pthread_mutex_t	*mutex;
	int	*forks; // 0: in use | 1: available
	int	*queue;
	t_philos	*philos;
};

struct	s_philos
{
	int			id; // starts at 0
	char		state; // e: eating | t: thinking | s: sleeping | d: dead
	int			holds_left;
	int			holds_right;
	int			ate_num;
	unsigned int	state_time;
	unsigned int	last_meal_time;
	t_configs	*configs;
};

int	init_threads(t_philos *philos);
void	*init_philos(int argc, char **argv);
int	ft_atoi(const char *str);
unsigned int	get_time(void);
void	*routine(void *philo);
void	destroy_mutex(int mutex_num, pthread_mutex_t *mutex);
int	meal_quota(t_configs *conf);

# endif
