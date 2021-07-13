/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:47:57 by laube             #+#    #+#             */
/*   Updated: 2021/07/13 12:18:03 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*fdf_init(t_map *map, t_cam *cam)
{
	t_fdf	*fdf;
	void	*img;

	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
		terminate(ERR_FDF);
	fdf->map = map;
	fdf->cam = cam;
	fdf->mlx_ptr = mlx_init();
	if (fdf->mlx_ptr == NULL)
		terminate(ERR_MLX);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,
			map->w_width, map->w_height, "LP's FDF");
	if (fdf->win_ptr == NULL)
		terminate(ERR_WIN);
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, map->w_width, map->w_height);
	if (fdf->img_ptr == NULL)
		terminate(ERR_IMG);
	img = fdf->img_ptr;
	fdf->addr = mlx_get_data_addr(img, &(fdf->px_bits),
			&(fdf->ln_len), &(fdf->endian));
	if (fdf->addr == NULL)
		terminate(ERR_ADDR);
	return (fdf);
}

t_cam	*cam_init(void)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (cam == NULL)
		terminate(ERR_CAM);
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

void	map_init_helper(t_map *map)
{
	map->point = malloc(sizeof(t_point) * map->point_amt);
	if (map->point == NULL)
		terminate(ERR_POINT);
	map->point_og = malloc(sizeof(t_point) * map->point_amt);
	if (map->point_og == NULL)
		terminate(ERR_POINT_OG);
}

t_map	*map_init(char **av)
{
	int		fd;
	int		i;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		terminate(ERR_MAP);
	get_map_dim(av, map);
	get_line_len(map);
	map->point_amt = map->width * map->height;
	map_init_helper(map);
	map->bg_color = 'b';
	map->first = 1;
	map->big_z = 1;
	map->small_z = -1;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		terminate(ERR_MAP_OPEN);
	i = -1;
	map_to_point(map, fd, i);
	close(fd);
	return (map);
}
