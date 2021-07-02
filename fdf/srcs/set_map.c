/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 19:03:43 by laube             #+#    #+#             */
/*   Updated: 2021/07/02 14:29:22 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_map_dim(char **av, t_map *map)
{
	int		fd;
	char	*line;
	char	**table;
	int		gnl_ret;

	gnl_ret = 1;
	map->width = 0;
	map->height = 0;
	fd = open(av[1], O_RDONLY);
	while (gnl_ret > 0)
	{
		gnl_ret = get_next_line(fd, &line);
		if (map->height == 0)
		{
			table = ft_split(line, ' ');
			while (*table)
			{
				map->width++;
				table++;
			}
		}
		if (gnl_ret > 0)
			map->height++;
	}
	close(fd);
	// Assign window sizing
	if (map->width <= 10)
	{
		map->win_width = 600;
		map->win_height = 400;
	}
	else if (map->width > 10 && map->width <= 50)
	{
		map->win_width = 1000;
		map->win_height = 800;
	}
	else
	{
		map->win_width = 1400;
		map->win_height = 800;
	}
}

void	get_line_len(t_map *map)
{
	int	len_x;
	int	len_y;

	map->margin = 0;
	len_x = (map->win_width - map->margin * 2) / (map->width - 1);
	len_y = (map->win_height - map->margin * 2) / (map->height - 1);
	if (len_x < len_y)
		map->line_len = len_x;
	else
		map->line_len = len_y;
	map->line_len = round(map->line_len / 1.3);
}

t_map	*map_init(char **av)
{
	int		fd;
	int		i;
	t_map	*map;

	map = malloc(sizeof(t_map));
	i = 0;
	get_map_dim(av, map);
	get_line_len(map);
	map->alpha = 0;
	map->gamma = 0;
	fd = open(av[1], O_RDONLY);
	
	// Mallocs memory for array of points
	map->point_amt = map->width * map->height;
	map->point = malloc(sizeof(t_point) * map->point_amt);
	map->point_og = malloc(sizeof(t_point) * map->point_amt);
	map->z_scale = 3.0;
	map->move_x = 0;
	map->move_y = 0;
	map->mouse_press = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		terminate(ERR_MAP_OPEN);
	// Puts map into dots
	map_to_point(map, fd, i);
	close(fd);
	return (map);
}
