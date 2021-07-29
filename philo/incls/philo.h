/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:55:24 by laube             #+#    #+#             */
/*   Updated: 2021/07/29 00:12:12 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

typedef struct	s_philos
{
	char	state; // e: eating | t: thinking | s: sleeping
	int		holds_left;
	int		holds_right;
}				t_philos;

typedef struct	s_configs
{
	int	phil_num;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	eat_num;
	int	eat_num_active;
	t_philos	*philos; 
}				t_configs;

# endif
