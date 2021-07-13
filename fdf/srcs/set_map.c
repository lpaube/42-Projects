/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 19:03:43 by laube             #+#    #+#             */
/*   Updated: 2021/07/13 19:37:57 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_line_len(t_map *map)
{
	int	len_x;
	int	len_y;

	map->margin = 0;
	if (map->width <= 1 || map->height <= 1)
		terminate(ERR_INVALID_MAP);
	len_x = (map->w_width - map->margin * 2) / (map->width - 1);
	len_y = (map->w_height - map->margin * 2) / (map->height - 1);
	if (len_x < len_y)
		map->line_len = len_x;
	else
		map->line_len = len_y;
	map->line_len = round(map->line_len / 1.3);
}

void	window_sizing(t_map *map)
{
	if (map->width <= 10)
	{
		map->w_width = 600;
		map->w_height = 400;
	}
	else if (map->width > 10 && map->width <= 50)
	{
		map->w_width = 1000;
		map->w_height = 800;
	}
	else
	{
		map->w_width = 1200;
		map->w_height = 800;
	}
}

void	increase_height(t_map *map, int gnl_ret, int tmp_width)
{
	if (gnl_ret > 0)
	{
		if (map->width != tmp_width)
			terminate(ERR_MAP_WIDTH);
		map->height++;
	}
}

int	map_dim_helper(char **table, int tmp_width, t_map *map)
{
	while (*(table))
	{
		tmp_width++;
		table++;
	}
	if (map->height == 0)
		map->width = tmp_width;
	return (tmp_width);
}

void	get_map_dim(char **av, t_map *map, int tmp_width)
{
	int		fd;
	char	*line;
	char	**table;
	int		gnl_ret;

	gnl_ret = 1;
	map->width = 0;
	map->height = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		terminate(ERR_MAP_OPEN);
	while (gnl_ret > 0)
	{
		gnl_ret = get_next_line(fd, &line);
		table = ft_split(line, ' ');
		tmp_width = map_dim_helper(table, tmp_width, map);
		increase_height(map, gnl_ret, tmp_width);
		tmp_width = 0;
		free_table(table);
		free(table);
		free(line);
	}
	window_sizing(map);
	close(fd);
}
