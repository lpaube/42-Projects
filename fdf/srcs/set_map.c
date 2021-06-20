/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 19:03:43 by laube             #+#    #+#             */
/*   Updated: 2021/06/20 19:43:14 by laube            ###   ########.fr       */
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
		map->height++;
	}
	close(fd);
}

void	get_line_len(t_map *map)
{
	int	len_x;
	int	len_y;
	int	line_len;

	map->margin = 10;
	len_x = (WIDTH - map->margin) / (map->width - 1);
	len_y = (HEIGHT - map->margin) / (map->height - 1);
	if (len_x < len_y)
		line_len = len_x;
	else
		line_len = len_y;
}

// Makes array of points with correct number relative to num of points on map
void	map_to_point(t_map *map, int fd, int i)
{
	int		gnl_ret;
	int		curr_col;
	int		curr_row;
	char	**row;
	char	*line;

	gnl_ret = 1;
	curr_row = 1;
	while (gnl_ret)
	{
		curr_col = 1;
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret < 0)
			terminate(ERR_MAP_READ);
		row = ft_split(line, ' ');
		while (*row)
		{
			map->point[i] = set_point(map, ft_atoi(*row), curr_col, curr_row);
			curr_col++;
			row++;
		}
		curr_row++;
	}
}

void	map_init(t_map *map, char **av)
{
	int		fd;
	int		i;
	int		curr_row;
	int		curr_col;

	i = 0;
	map = malloc(sizeof(t_map));
	get_map_dim(av, map);
	get_line_len(map);
	fd = open(av[1], O_RDONLY);
	
	// Mallocs memory for array of points
	map->point_amt = map->width * map->height;
	map->point = malloc(sizeof(t_point) * map->point_amt);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		terminate(ERR_MAP_OPEN);
	// Puts map into dots (without x and y coords)
	map_to_point(map, fd, i);
	close(fd);

}
