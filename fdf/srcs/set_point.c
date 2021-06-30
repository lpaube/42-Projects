/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:48:31 by laube             #+#    #+#             */
/*   Updated: 2021/06/24 12:54:07 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x(int *y, int *z, double alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

t_camera	*camera_init(t_fdf *fdf)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	camera->zoom = ft_dmin(WIDTH / fdf->map->width / 2, HEIGHT / fdf->map->height / 2);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divisor = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	return (camera);
}

void iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x - previous_y) * sin(0.523599);
	/*
	if (*x < 0)
		*x = 0;
	if (*y < 0)
		*y = 0;
		*/
	printf("PRE: previous_x: %d | previous_y: %d | curr_x: %d | curr_y: %d\n", previous_x, previous_y, *x, *y);
}

void	adjust_points(t_fdf	*fdf)
{
	int	i;
	t_point	*p;

	i = 0;
	while (i < fdf->map->point_amt)
	{
		p = fdf->map->point;
		rotate_x(&p[i].y, &p[i].z, fdf->camera->alpha);
		rotate_y(&p[i].x, &p[i].z, fdf->camera->beta);
		rotate_z(&p[i].x, &p[i].y, fdf->camera->gamma);
		iso(&p[i].x, &p[i].y, p[i].z);
		p[i].x += WIDTH / 2 + fdf->camera->x_offset;
		p[i].y += (HEIGHT + fdf->map->height * fdf->camera->zoom) / 2;

		printf("POST: p.x: %d | p.y: %d\n", p[i].x, p[i].y);
		i++;
	}
}

void	coord_to_point(t_map *map, t_point *point)
{
	point->x = point->col * 30; //map->margin + (point->col * map->line_len);
	point->y = point->row * 30; //map->margin + (point->row * map->line_len);
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
			map->point[i] = set_point(map, ft_atoi(*row), curr_col, curr_row);
			curr_col++;
			row++;
			i++;
		}
		curr_row++;
	}
}
