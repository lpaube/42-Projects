/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 21:10:08 by laube             #+#    #+#             */
/*   Updated: 2021/07/05 11:24:47 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	clear_img(t_fdf *fdf, t_map *map)
{
	int	i;
	int	clr;

	i = 0;
	if (map->bg_color == 'w')
		clr = 0x00AA8888;
	else if (map->bg_color == 'g')
		clr = 0x00224444;
	else
		clr = 0x0015202B;
	while (i < (map->w_width * map->w_height))
	{
		ft_put_pixel(fdf, i % map->w_width, i / map->w_width, clr);
		i++;
	}
}

void	color_point(t_map *map, t_point *point)
{
	int	i;
	int	max_z;
	int	maxc; //255 when z is max
	int	minc; //255 when z is min

	max_z = map->big_z - map->small_z;

	i = 0;
	while (i < map->point_amt)
	{
		minc = 255 - round(((double)point[i].z - map->small_z) / max_z * 255);
		maxc = round(((double)point[i].z - map->small_z) / max_z * 255);
		if (map->bg_color == 'w')
			point[i].color = 0 << 24 | 0 << 16 | maxc << 8 | maxc;
		else if (map->bg_color == 'g')
			point[i].color = 0 << 24 | maxc << 16 | minc << 8 | minc;
		else
			point[i].color = 0 << 24 | 225 << 16 | maxc << 8 | maxc;
		if (point[i].expl_color_set == 1)
			point[i].color = point[i].expl_color;
		i++;
	}
}

//Next 3 functions are for gradient coloring of lines
double	percent(int start, int end, int curr)
{
	double	placement;
	double	distance;

	placement = curr - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

int	get_light(int start, int end, double perc)
{
	return ((int)((1 - perc) * start + perc * end));
}

int	get_color(int curr_x, int curr_y, t_point p1, t_point p2)
{
	int		red;
	int		green;
	int		blue;
	double	perc;

	if (p2.x - p1.x > p2.y - p1.y)
		perc = percent(p1.x, p2.x, curr_x);
	else
		perc = percent(p1.y, p2.y, curr_y);
	red = get_light((p1.color >> 16) & 0xFF, (p2.color >> 16) & 0xFF, perc);
	green = get_light((p1.color >> 8) & 0xFF, (p2.color >> 8) & 0xFF, perc);
	blue = get_light(p1.color & 0xFF, p2.color & 0xFF, perc);
	return ((red << 16) | (green << 8) | blue);
}
