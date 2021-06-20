/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:14:48 by laube             #+#    #+#             */
/*   Updated: 2021/06/20 16:32:58 by laube            ###   ########.fr       */
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

void	fdf_init(t_fdf *fdf, t_map *map)
{
	fdf = malloc(sizeof(t_fdf));
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "Cool window!");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	fdf->map = map;
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

void	map_init(t_map *map, char **av)
{
	int		fd;
	int		gnl_ret;
	char	*line;
	char	**row;
	int		i;
	int		curr_row;
	int		curr_col;

	i = 0;
	map = malloc(sizeof(t_map));
	get_map_dim(av, map);
	gnl_ret = 1;
	fd = open(av[1], O_RDONLY);
	
	// Puts map into dots
	curr_row = 1;
	map->point_amt = map->width * map->height;
	map->point = malloc(sizeof(t_point) * map->point_amt);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		terminate(ERR_MAP_OPEN);
	while (gnl_ret)
	{
		curr_col = 1;
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret < 0)
			terminate(ERR_MAP_READ);
		row = ft_split(line, ' ');
		while (*row)
		{
			map->point[i] = get_point(ft_atoi(*row), curr_col, curr_row);
			curr_col++;
			row++;
		}
		curr_row++;
	}
	close(fd);
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

t_point get_point(int z, int col, int row)
{
	t_point	point;

	printf("z: %d | col: %d | row: %d\n", z, col, row);
	point.z = z;

	return (point);
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

// Control function for drawing to an image
void	draw_control(t_fdf *fdf)
{
	fdf->addr = mlx_get_data_addr(fdf->img_ptr, &fdf->bits_per_pixel, &fdf->line_length, &fdf->endian);
	//draw_line_dda(fdf, fdf->map->point[0], fdf->map->point[1]);
	//mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}

int main(int ac, char **av)
{
	t_fdf	*fdf;
	t_map	*map;

	map_init(map, av);
	fdf_init(fdf, map);
	//draw_control(fdf);
	//mlx_key_hook(fdf->win_ptr, esc_hook, fdf);
	//mlx_loop(fdf->mlx_ptr);
}
