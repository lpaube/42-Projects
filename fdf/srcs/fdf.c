/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:14:48 by laube             #+#    #+#             */
/*   Updated: 2021/06/30 21:12:47 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

	if (!(fdf = malloc(sizeof(t_fdf))))
		printf("EMPTY 1\n");
	if (!(fdf->mlx_ptr = mlx_init()))
		printf("EMPTY 2\n");
	if (!(fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "Cool window!")))
		printf("EMPTY 3\n");
	if (!(fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT)))
		printf("EMPTY 4\n");
	fdf->addr = mlx_get_data_addr(fdf->img_ptr, &(fdf->bits_per_pixel), &(fdf->line_length), &(fdf->endian));
	fdf->map = map;
	return (fdf);
}

void	terminate(char *s)
{
	if (errno == 0)
	{
		ft_putstr_fd(s, 2);
		ft_putchar_fd('\n', 2);
	}
	else
		perror(s);
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

// Drawing a line using the algo Digital Differential Analyzer
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
	printf("p1.row: %d | p1.col: %d | p2.row: %d | p2.col: %d | p1.color: %x | p2.color: %x\n", p1.row, p1.col, p2.row, p2.col, p1.color, p2.color);
	printf("p1.x: %d | p1.y: %d | p1.z: %d | p2.x: %d | p2.y: %d | p2.z: %d\n", p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);

	if (p1.x < 0 || p1.y < 0 || p1.z < 0 || p2.x < 0 || p2.y < 0 || p2.z < 0)
		return (-1);
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

void	draw_point(t_fdf *fdf, t_map *map, t_point *point, int i)
{
	if (point[i].x < 0 || point[i].y < 0 || point[i].z < 0)
		return ;
	if (point[i].x > WIDTH || point[i].y > HEIGHT)
		return ;
	if (i < map->point_amt)
	{
		//DRAWING POINTS
		ft_put_pixel(fdf, point[i].x, point[i].y, point[i].color);
		
		//DRAWING LINES
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

// Control function for drawing to an image
void	draw_control(t_map *map, t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < map->point_amt)
	{
		//printf("DRAWING: p.x: %d | p.y: %d\n", fdf->map->point[i].x, fdf->map->point[i].y);
		iso(&(fdf->map->point[i].x), &(fdf->map->point[i].y), &(fdf->map->point[i].z), fdf->map);
		i++;
	}
	i = 0;
	while (i < map->point_amt)
	{
		draw_point(fdf, map, map->point, i);
		i++;
	}
	//draw_line_dda(fdf, fdf->map->point[0], fdf->map->point[1]);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}

int main(int ac, char **av)
{
	t_fdf	*fdf;
	t_map	*map;

	(void)ac;
	map = map_init(av);
	fdf = fdf_init(map);
	draw_control(map, fdf);
	mlx_key_hook(fdf->win_ptr, esc_hook, fdf);
	mlx_loop(fdf->mlx_ptr);
}
