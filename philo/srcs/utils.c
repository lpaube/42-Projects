/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 22:01:26 by laube             #+#    #+#             */
/*   Updated: 2021/08/05 11:15:28 by laube            ###   ########.fr       */
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

unsigned int	get_time(void)
{
	struct timeval	time;
	unsigned int	milli_time;

	gettimeofday(&time, NULL);
	milli_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (milli_time);
}

void	destroy_mutex(int mutex_num, pthread_mutex_t *mutex)
{
	int	i;

	i = 0;
	while (i < mutex_num)
		pthread_mutex_destroy(&mutex[i++]);
}

void	print_msg(char c, unsigned int time, int id)
{
	if (c == 'f')
		printf("%d %d has taken a fork\n", time, id);
	else if (c == 'e')
		printf("%d %d is eating\n", time, id);
	else if (c == 's')
		printf("%d %d is sleeping\n", time, id);
	else if (c == 't')
		printf("%d %d is thinking\n", time, id);
	else if (c == 'd')
		printf("%d %d died\n", time, id);
}
