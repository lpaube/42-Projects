/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:48:31 by laube             #+#    #+#             */
/*   Updated: 2021/07/04 13:00:24 by laube            ###   ########.fr       */
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

int	hex_to_dec(char *num)
{
	int	y = 0;
	int	dec = 0;
	int	x;
	int	i;

	i = ft_strlen(num) - 1;
	while (i >= 0)
	{
		if (num[i] >= '0' && num[i] <= '9')
		{
			x = num[i] - '0';
		}
		else
			x = ft_toupper(num[i] - 'A' + 10);
		dec = dec + x * pow(16, y);
		y++;
		i--;
	}
	return (dec);
}

int	get_explicit_hex(char *num)
{
	if (num[0] == '0' && (num[1] == 'x' || num[1] == 'X'))
		return (hex_to_dec(num + 2));
	else
		return (ft_atoi(num));
}

void	explicit_color(char *num, t_point *point)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (num[i] == ',')
		{
			point->expl_color = get_explicit_hex(num + i + 1);
			point->expl_color_set = 1;
			return ;
		}
		i++;
	}
	point->expl_color_set = 0;
	point->expl_color = 0;
}

// Sets all the properties of the t_points in the points array made by map_init
t_point set_point(t_map *map, char *num, int col, int row)
{
	t_point	point;
	int	z;

	z = ft_atoi(num);
	point.col = col;
	point.row = row;
	explicit_color(num, &point);
	point.z = z;
	coord_to_point(map, &point);
	if (z > map->big_z)
		map->big_z = z;
	if (z < map->small_z)
		map->small_z = z;
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
			map->point_og[i] = set_point(map, *row, curr_col, curr_row);
			curr_col++;
			row++;
			i++;
		}
		curr_row++;
	}
}
