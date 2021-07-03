/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:48:31 by laube             #+#    #+#             */
/*   Updated: 2021/07/03 17:08:49 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void iso(t_point *point, t_map *map)
{
	double	tmp_x;
	double	tmp_y;
	int		i;

	i = 0;
	while (i < map->point_amt)
	{
		tmp_x = point[i].x;
		tmp_y = point[i].y;

		point[i].x = (tmp_x - tmp_y) * cos(0.523599);
		point[i].y = -point[i].z + (tmp_x + tmp_y) * sin(0.523599);
		i++;
	}
}

void	coord_to_point(t_map *map, t_point *point)
{
	(void)map;
	point->x = map->margin + (point->col * map->line_len);
	point->y = map->margin + (point->row * map->line_len);
}

// Sets all the properties of the t_points in the points array made by map_init
t_point set_point(t_map *map, int z, int col, int row)
{
	t_point	point;

	point.col = col;
	point.row = row;
	point.z = z;
	coord_to_point(map, &point);
	if (z > map->big_z)
		map->big_z = z;
	if (z < map->small_z)
		map->small_z = z;
	switch (row)
	{
		case 0:
			point.color = 0x00FFFF55;
			break;
		case 1:
			point.color = 0x00FFDD55;
			break;
		case 2:
			point.color = 0x00FFBB55;
			break;
		case 3:
			point.color = 0x00FF9955;
			break;
		case 4:
			point.color = 0x00FF7755;
			break;
		case 5:
			point.color = 0x00FF5555;
			break;
		case 6:
			point.color = 0x00FF3355;
			break;
		case 7:
			point.color = 0x00FF1155;
			break;
		default:
			point.color = 0x00EE0055;
	}
	return (point);
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
	curr_row = 0;
	while (gnl_ret)
	{
		curr_col = 0;
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret < 0)
			terminate(ERR_MAP_READ);
		row = ft_split(line, ' ');
		while (*row)
		{
			//map->point[i] = set_point(map, ft_atoi(*row), curr_col, curr_row);
			map->point_og[i] = set_point(map, ft_atoi(*row), curr_col, curr_row);
			curr_col++;
			row++;
			i++;
		}
		curr_row++;
	}
}
