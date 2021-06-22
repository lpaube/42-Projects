/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:48:31 by laube             #+#    #+#             */
/*   Updated: 2021/06/21 22:54:00 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	coord_to_point(t_map *map, t_point *point)
{
	point->x = map->margin + point->col * map->line_len;
	point->y = map->margin + point->row * map->line_len;
}

// Sets all the properties of the t_points in the points array made by map_init
t_point set_point(t_map *map, int z, int col, int row)
{
	int		i;
	t_point	point;

	i = 0;
	point.col = col;
	point.row = row;
	point.z = z;
	coord_to_point(map, &point);
	point.color = 0x0000FFFF;
	return (point);
}
