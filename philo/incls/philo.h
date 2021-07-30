/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:55:24 by laube             #+#    #+#             */
/*   Updated: 2021/07/30 16:36:13 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

typedef struct	s_configs
{
	int	phils_num;
	int	forks_num;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	eat_num;
	int	eat_num_active;
	int	*forks; // 0: available | 1: in use
}				t_configs;

typedef struct	s_philos
{
	int			id;
	char		state; // e: eating | t: thinking | s: sleeping | d: dead
	int			holds_left;
	int			holds_right;
	t_configs	*configs;
}				t_philos;

# endif
