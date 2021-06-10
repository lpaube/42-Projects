/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:07:56 by laube             #+#    #+#             */
/*   Updated: 2021/06/10 15:40:28 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	atoi_long(const char *str)
{
	long	curr_num;
	int		state;

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

int	atoi_err(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != 0)
		return (1);
	if (atoi_long(str) > 2147483647 || atoi_long(str) < -2147483648)
		return (1);
	return (0);
}

int	**argv_to_arr(int argc, char **argv)
{
	int	**arr_ptr;
	int	*arr;
	int	i;

	arr = malloc((argc - 1) * sizeof(int));
	i = 0;
	arr_ptr = &arr;
	while (i < argc - 1)
	{
		arr[i] = ft_atoi(argv[i]);
		i++;
	}
	return (arr_ptr);
}

int	check_errors(int argc, char **argv)
{
	int	i;
	int	j;
	int	**arr;

	while (i < argc - 1)
		if (atoi_err(argv[i++]))
			return (1);
	i = 0;
	arr = argv_to_arr(argc, argv);
	while (i < argc - 2)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if ((*arr)[i] == (*arr)[j])
			{
				free(*arr);
				return (1);
			}
			j++;
		}
		i++;
	}
	free(*arr);
	return (0);
}