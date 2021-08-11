/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:11:12 by laube             #+#    #+#             */
/*   Updated: 2021/08/11 13:01:56 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// y and x begins at 0, like an index
void	ft_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int	pxl_pos;

	if (x >= fdf->map->w_width || y >= fdf->map->w_height)
		return ;
	pxl_pos = (y * fdf->ln_len) + (x * (fdf->px_bits / 8));
	if (fdf->endian == 1)
	{
		fdf->addr[pxl_pos + 0] = (color >> 24);
		fdf->addr[pxl_pos + 1] = (color >> 16) & 0xFF;
		fdf->addr[pxl_pos + 2] = (color >> 8) & 0xFF;
		fdf->addr[pxl_pos + 3] = (color) & 0xFF;
	}
	else if (fdf->endian == 0)
	{
		fdf->addr[pxl_pos + 0] = (color) & 0xFF;
		fdf->addr[pxl_pos + 1] = (color >> 8) & 0xFF;
		fdf->addr[pxl_pos + 2] = (color >> 16) & 0xFF;
		fdf->addr[pxl_pos + 3] = (color >> 24);
	}
}

t_dda	get_dda(t_point p1, t_point p2)
{
	t_dda	dda;

	dda.sign_x = 1;
	dda.sign_y = 1;
	if (p1.x > p2.x)
		dda.sign_x = -1;
	if (p1.y > p2.y)
		dda.sign_y = -1;
	dda.delta_x = ft_abs(p2.x - p1.x);
	dda.delta_y = ft_abs(p2.y - p1.y);
	dda.steps = ft_dmax(dda.delta_x, dda.delta_y);
	dda.inc_x = dda.delta_x / dda.steps;
	dda.inc_y = dda.delta_y / dda.steps;
	return (dda);
}

int	draw_line_dda(t_fdf *fdf, t_point p1, t_point p2)
{
	t_dda	dda;
	double	px;
	double	py;
	int		w_w;
	int		w_h;

	w_w = fdf->map->w_width;
	w_h = fdf->map->w_height;
	if (p1.x < 0 || p1.y < 0 || p2.x < 0 || p2.y < 0)
		return (-1);
	if (p1.x > w_w || p2.x > w_w || p1.y > w_h || p2.y > w_h)
		return (-1);
	dda = get_dda(p1, p2);
	px = p1.x;
	py = p1.y;
	while (dda.steps >= 0)
	{
		ft_put_pixel(fdf, round(px), round(py), get_color(px, py, p1, p2));
		px += dda.sign_x * dda.inc_x;
		py += dda.sign_y * dda.inc_y;
		dda.steps--;
	}
	return (0);
}

void	draw_point(t_fdf *fdf, t_map *map, t_point *point, int i)
{
	if (point[i].x < 0 || point[i].y < 0)
	{
		return ;
	}
	if (point[i].x > map->w_width || point[i].y > map->w_height)
	{
		return ;
	}
	if (i < map->point_amt)
	{
		if (point[i].row < map->height - 1)
		{
			draw_line_dda(fdf, point[i], point[i + map->width]);
		}
		if (point[i].col < map->width - 1)
		{
			draw_line_dda(fdf, point[i], point[i + 1]);
		}
	}
}
