/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:14:23 by laube             #+#    #+#             */
/*   Updated: 2021/07/05 17:53:10 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	iso(t_point *point, t_map *map)
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

void	update_movements(t_map *map, t_cam *cam)
{
	int	i;

	if (cam->iso)
		iso(map->point, map);
	if (map->first == 1)
	{
		map->first = 0;
		cam->move_x = -(map->point[map->width * (map->height - 1)].x);
		cam->move_y = -(map->point[0].y);
	}
	i = 0;
	while (i < map->point_amt)
	{
		map->point[i].x += cam->move_x;
		map->point[i].y += cam->move_y;
		i++;
	}
}

void	update_rotations(t_map *map, t_cam *cam, t_point mid_p)
{
	int	i;
	int	tmp_x;
	int	tmp_y;
	int	trans_x;
	int	trans_y;

	trans_x = mid_p.x;
	trans_y = mid_p.y;
	i = 0;
	while (i < map->point_amt)
	{
		tmp_x = map->point[i].x - trans_x;
		tmp_y = map->point[i].y - trans_y;
		map->point[i].x = tmp_x * cos(cam->gamma) + tmp_y * sin(cam->gamma);
		map->point[i].y = tmp_x * -sin(cam->gamma) + tmp_y * cos(cam->gamma);
		map->point[i].x = tmp_x * cos(cam->beta) + (map->point_og[i].z * cam->z_scale) * -sin(cam->beta) + trans_x;
		map->point[i].z = tmp_x * sin(cam->beta) + (map->point_og[i].z * cam->z_scale) * cos(cam->beta);
		tmp_x = map->point[i].x;
		tmp_y = map->point[i].y;
		map->point[i].y = tmp_y * cos(cam->alpha) + (map->point_og[i].z * cam->z_scale) * sin(cam->alpha) + trans_y;
		map->point[i].z = tmp_y * -sin(cam->alpha) + (map->point_og[i].z * cam->z_scale) * cos(cam->alpha);
		i++;
	}
}

void	update_p(t_fdf *fdf, t_map *map, t_cam *cam)
{
	int	i;
	t_point	mid_p;

	clear_img(fdf, map);
	color_point(map, map->point_og);
	i = 0;
	while (i < map->point_amt)
	{
		map->point[i] = map->point_og[i];
		i++;
	}
	mid_p = map->point[((map->height / 2) * map->width) + (map->width / 2)];
	update_rotations(map, cam, mid_p);
	update_movements(map, cam);
	i = 0;
	while (i < map->point_amt)
		draw_point(fdf, map, map->point, i++);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}
