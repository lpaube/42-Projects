/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:47:57 by laube             #+#    #+#             */
/*   Updated: 2021/07/05 11:27:34 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*fdf_init(t_map *map, t_cam *cam)
{
	t_fdf	*fdf;
	void	*img;

	fdf = malloc(sizeof(t_fdf));
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = N_WIN(fdf->mlx_ptr, map->w_width, map->w_height, "LP's FDF");
	fdf->img_ptr = N_IMG(fdf->mlx_ptr, map->w_width, map->w_height);
	img = fdf->img_ptr;
	fdf->addr = D_ADDR(img, &(fdf->px_bits), &(fdf->ln_len), &(fdf->endian));
	fdf->map = map;
	fdf->cam = cam;
	return (fdf);
}

t_cam	*cam_init(void)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	cam->z_scale = 4;
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	cam->move_x = 0;
	cam->move_y = 0;
	cam->mouse_press = 0;
	cam->mouse_x = 0;
	cam->mouse_y = 0;
	cam->iso = 1;
	return (cam);
}

t_map	*map_init(char **av)
{
	int		fd;
	int		i;
	t_map	*map;

	map = malloc(sizeof(t_map));
	i = 0;
	get_map_dim(av, map);
	get_line_len(map);
	fd = open(av[1], O_RDONLY);
	// Mallocs memory for array of points
	map->point_amt = map->width * map->height;
	map->point = malloc(sizeof(t_point) * map->point_amt);
	map->point_og = malloc(sizeof(t_point) * map->point_amt);
	map->bg_color = 'b';
	map->first = 1;
	map->big_z = 1;
	map->small_z = -1;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		terminate(ERR_MAP_OPEN);
	map_to_point(map, fd, i);
	close(fd);
	return (map);
}
