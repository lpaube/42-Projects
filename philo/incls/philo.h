/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:55:24 by laube             #+#    #+#             */
/*   Updated: 2021/07/30 23:40:48 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct	s_configs
{
	unsigned int	start_time;
	int	phils_num;
	int	forks_num;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	eat_num;
	int	eat_num_active;
	pthread_mutex_t	mutex;
	int	*forks; // 0: in use | 1: available
}				t_configs;

typedef struct	s_philos
{
	int			id; // starts at 0
	char		state; // e: eating | t: thinking | s: sleeping | d: dead
	int			holds_left;
	int			holds_right;
	unsigned int	state_time;
	t_configs	*configs;
}				t_philos;

# endif
