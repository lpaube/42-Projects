/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:48:31 by laube             #+#    #+#             */
/*   Updated: 2021/07/09 16:34:04 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	coord_to_point(t_map *map, t_point *point)
{
	point->x = map->margin + (point->col * map->line_len);
	point->y = map->margin + (point->row * map->line_len);
}

int	hex_to_dec(char *num)
{
	int	y;
	int	dec;
	int	x;
	int	i;

	y = 0;
	dec = 0;
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

void	explicit_color(char *num, t_point *point)
{
	int	i;
	int	hex;

	hex = 0;
	i = 0;
	while (num[i])
	{
		if (num[i] == ',')
		{
			if (num[0] == '0' && (num[1] == 'x' || num[1] == 'X'))
				point->expl_color = hex_to_dec(num + 2);
			else
				point->expl_color = ft_atoi(num);
			point->expl_color_set = 1;
			return ;
		}
		i++;
	}
	point->expl_color_set = 0;
	point->expl_color = 0;
}

// Sets all the properties of the t_points in the points array made by map_init
t_point	set_point(t_map *map, char *num, int col, int row)
{
	t_point	point;
	int		z;

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
	map->point_og = malloc(map->point_amt *sizeof(*(map->point_og)));
	map->point = malloc(map->point_amt *sizeof(*(map->point)));
	while (gnl_ret)
	{
		curr_col = 0;
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret < 0)
			terminate(ERR_MAP_READ);
		row = ft_split(line, ' ');
		while (*row)
		{
			map->point_og[i] = set_point(map, *row, curr_col, curr_row);
			free(*(row++));
			curr_col++;
			i++;
		}
		free(line);
		curr_row++;
	}
	free(row);
}
