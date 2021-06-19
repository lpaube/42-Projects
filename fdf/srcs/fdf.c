/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:14:48 by laube             #+#    #+#             */
/*   Updated: 2021/06/18 21:15:06 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_mac/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "../includes/fdf.h"

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
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 800, "Cool window!");
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

void	color_to_pixel(t_fdf *fdf, int x, int y, int color)
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

int	draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	double	delta_x;
	double	delta_y;

	delta_x = ABS(p2.x - p1.x);
	delta_y = ABS(p2.y - p1.y);
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

void	draw_control(t_fdf *fdf)
{
	fdf->addr = mlx_get_data_addr(fdf->img_ptr, &fdf->bits_per_pixel, &fdf->line_length, &fdf->endian);
	draw_line(fdf, get_point(0, 0, 0, 0x0000FFFF), get_point(300, 300, 0, 0x0000FFFF));
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
