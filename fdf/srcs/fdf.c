/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:14:48 by laube             #+#    #+#             */
/*   Updated: 2021/06/19 23:29:31 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_mac/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "../includes/fdf.h"
#include <math.h>

//#include <X11/Xlib.h>
//#include <sys/ipc.h>
//#include <sys/shm.h>
//#include <X11/extensions/XShm.h>

int	esc_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		exit(0);
	}
	return (0);
}

t_fdf	*fdf_init(t_map *map)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "Cool window!");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	fdf->map = map;
	return (fdf);
}

t_map	*map_init(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->width = 0;
	map->height = 0;
	return (map);
}

void	ft_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int	pxl_pos;

	pxl_pos = (y * fdf->line_length) + (x * (fdf->bits_per_pixel / 8));

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

int	get_pxl_pos(t_fdf *fdf, int x, int y)
{
	int	pxl_pos;

	pxl_pos = (y * fdf->line_length) + (x * (fdf->bits_per_pixel / 8));
	return (pxl_pos);
}

t_point get_point(int x, int y, int z, int color)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color = color;
	return (point);
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
	double	point_x;
	double	point_y;

	if (p1.x > WIDTH || p2.x > WIDTH || p1.y > HEIGHT || p2.y > HEIGHT)
	{
		ft_putstr_fd("Points for line out of bounds!\n", 1);
		return (-1);
	}
	dda = get_dda(p1, p2);
	point_x = p1.x;
	point_y = p1.y;
	while (dda.steps >= 0)
	{
		ft_put_pixel(fdf, round(point_x), round(point_y), p2.color);
		point_x += dda.sign_x * dda.inc_x;
		point_y += dda.sign_y * dda.inc_y;
		dda.steps--;
	}
	return (0);
}


void	draw_control(t_fdf *fdf)
{
	fdf->addr = mlx_get_data_addr(fdf->img_ptr, &fdf->bits_per_pixel, &fdf->line_length, &fdf->endian);
	draw_line_dda(fdf, get_point(0, 100000, 0, 0x0000FFFF), get_point(0, 10, 0, 0x0000FFFF));
	//draw_line_dda(fdf, get_point(10, 20, 0, 0x0000FFFF), get_point(100, 100, 0, 0x0000FFFF));
	//draw_line_dda(fdf, get_point(0, HEIGHT, 0, 0x0000FFFF), get_point(WIDTH, 0, 0, 0x0000FFFF));
	//draw_line_dda(fdf, get_point(400, 100, 0, 0x00FF0000), get_point(800, 100, 0, 0x00FF0000));
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}

int main(void)
{
	t_fdf	*fdf;
	t_map	*map;

	map = map_init();
	fdf = fdf_init(map);
//	events_control(fdf);
	draw_control(fdf);
	mlx_key_hook(fdf->win_ptr, esc_hook, fdf);
	mlx_loop(fdf->mlx_ptr);
}
