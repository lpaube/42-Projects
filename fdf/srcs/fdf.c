/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:14:48 by laube             #+#    #+#             */
/*   Updated: 2021/07/04 21:29:15 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	coord_to_point(t_map *map, t_point *point);
void	draw_point(t_fdf *fdf, t_map *map, t_point *point, int i);

void	rotate_xyz(t_fdf *fdf, t_map *map, t_cam *cam)
{
	int	i;
	int	j;
	int	trans_x;
	int	trans_y;
	int	tmp_x;
	int	tmp_y;
	t_point	mid_p;

	(void)tmp_x;
	(void)tmp_y;
	(void)mid_p;
	(void)trans_y;
	(void)trans_x;
	clear_img(fdf, map);
	color_point(map, map->point_og);
	i = 0;
	while (i < map->point_amt)
	{
		map->point[i] = map->point_og[i];
		i++;
	}
	mid_p = map->point[((map->height / 2) * map->width) + (map->width / 2)];
	trans_x = mid_p.x;
	trans_y = mid_p.y;
	
	i = 0;
	while (i < map->point_amt)
	{
		tmp_x = map->point[i].x - trans_x;
		tmp_y = map->point[i].y - trans_y;
		//Rotate Z
		map->point[i].x = tmp_x * cos(cam->gamma) + tmp_y * sin(cam->gamma);
		map->point[i].y = tmp_x * -sin(cam->gamma) + tmp_y * cos(cam->gamma);
		//Rotate Y
		map->point[i].x = tmp_x * cos(cam->beta) + (map->point_og[i].z * cam->z_scale) * -sin(cam->beta) + trans_x;
		map->point[i].z = tmp_x * sin(cam->beta) + (map->point_og[i].z * cam->z_scale) * cos(cam->beta);
		//Rotate X
		tmp_x = map->point[i].x;
		tmp_y = map->point[i].y;
		map->point[i].y = tmp_y * cos(cam->alpha) + (map->point_og[i].z * cam->z_scale) * sin(cam->alpha) + trans_y;
		map->point[i].z = tmp_y * -sin(cam->alpha) + (map->point_og[i].z * cam->z_scale) * cos(cam->alpha);
		//Movement
		i++;
	}
	if (cam->iso)
		iso(map->point, map);
	if (map->first == 1)
	{
		map->first = 0;
		cam->move_x = -(map->point[map->width * (map->height - 1)].x);
		cam->move_y = -(map->point[0].y);
	}
	j = 0;
	while (j < map->point_amt)
	{
		map->point[j].x += cam->move_x;
		map->point[j].y += cam->move_y;
		j++;
	}
	i = 0;
	while (i < map->point_amt)
			draw_point(fdf, map, map->point, i++);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}

int	mouse_press(int button, int x, int y, t_fdf *fdf)
{
	int	i;

	printf("mouse button: %d\n", button);
	//SCROLL TO ZOOM
	if (button == 4 && fdf->map->line_len < round(fdf->map->win_width / 8))
	{
		fdf->map->line_len = ceil(fdf->map->line_len * 1.1);
		i = 0;
		while (i < fdf->map->point_amt)
		{
			coord_to_point(fdf->map, &(fdf->map->point_og[i]));
			i++;
		}
		rotate_xyz(fdf, fdf->map, fdf->cam);
	}
	if (button == 5 && fdf->map->line_len > 3)
	{
		fdf->map->line_len = floor(fdf->map->line_len / 1.1);
		i = 0;
		while (i < fdf->map->point_amt)
		{
			coord_to_point(fdf->map, &(fdf->map->point_og[i]));
			i++;
		}
		rotate_xyz(fdf, fdf->map, fdf->cam);
	}
	//MOUSE CLICK AND HOLD
	if (button == 1)
	{
		fdf->cam->mouse_press = 1;
		fdf->cam->mouse_x = x;
		fdf->cam->mouse_y = y;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_fdf *fdf)
{
	(void)button;
	(void)x;
	(void)y;
	fdf->cam->mouse_press = 0;
	return (0);
}

int	mouse_move(int x, int y, t_fdf *fdf)
{
	double	inc;
	int		change_state;

	change_state = 0;
	inc = 0.01;
	if (fdf->cam->mouse_press)
	{
		if (fdf->cam->mouse_x != x)
		{
			fdf->cam->beta += inc * (fdf->cam->mouse_x - x);
			fdf->cam->mouse_x = x;
			change_state = 1;
		}
		if (fdf->cam->mouse_y != y)
		{
			fdf->cam->alpha -= inc * (fdf->cam->mouse_y - y);
			fdf->cam->mouse_y = y;
			change_state = 1;
		}
		if (change_state == 1)
			rotate_xyz(fdf, fdf->map, fdf->cam);
	}
	return (0);
}

int	key_press(int keycode, t_fdf *fdf)
{
	int		i;
	double	inc;

	(void)inc;
	printf("keycode: %d\n", keycode);
	i = 0;
	inc = 0.1;
	if (keycode == MAIN_ESC)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		exit(0);
	}
	if (keycode == ARROW_LEFT)
	{
		fdf->cam->beta += 1.5708;
		rotate_xyz(fdf, fdf->map, fdf->cam);
	}
	if (keycode == ARROW_RIGHT)
	{
		fdf->cam->beta -= 1.5708;
		rotate_xyz(fdf, fdf->map, fdf->cam);
	}
	if (keycode == ARROW_UP)
	{
		fdf->cam->alpha -= 1.5708;
		rotate_xyz(fdf, fdf->map, fdf->cam);
	}
	if (keycode == ARROW_DOWN)
	{
		fdf->cam->alpha += 1.5708;
		rotate_xyz(fdf, fdf->map, fdf->cam);
	}
	if (keycode == MAIN_W)
	{
		fdf->cam->move_y += 20;
		rotate_xyz(fdf, fdf->map, fdf->cam);
	}
	if (keycode == MAIN_S)
	{
		fdf->cam->move_y -= 20;
		rotate_xyz(fdf, fdf->map, fdf->cam);
	}
	if (keycode == MAIN_D)
	{
		fdf->cam->move_x -= 20;
		rotate_xyz(fdf, fdf->map, fdf->cam);
	}
	if (keycode == MAIN_A)
	{
		fdf->cam->move_x += 20;
		rotate_xyz(fdf, fdf->map, fdf->cam);
	}
	if (keycode == MAIN_LESS && fdf->cam->z_scale > 0.5)
	{
		fdf->cam->z_scale /= 1.1;
		rotate_xyz(fdf, fdf->map, fdf->cam);
	}
	if (keycode == MAIN_MORE && fdf->cam->z_scale < 30)
	{
		fdf->cam->z_scale *= 1.1;
		rotate_xyz(fdf, fdf->map, fdf->cam);
	}
	if (keycode == MAIN_I)
	{
		fdf->cam->iso = 1;
		fdf->cam->alpha = 0;
		fdf->cam->beta = 0;
		fdf->cam->gamma = 0;
		fdf->map->first = 1;
		get_line_len(fdf->map);
		while (i < fdf->map->point_amt)
		{
			coord_to_point(fdf->map, &(fdf->map->point_og[i]));
			i++;
		}
		rotate_xyz(fdf, fdf->map, fdf->cam);
	}
	if (keycode == MAIN_P)
	{
		fdf->cam->iso = 0;
		fdf->cam->alpha = 0;
		fdf->cam->beta = 0;
		fdf->cam->gamma = 0;
		fdf->map->first = 1;
		get_line_len(fdf->map);
		while (i < fdf->map->point_amt)
		{
			coord_to_point(fdf->map, &(fdf->map->point_og[i]));
			i++;
		}
		rotate_xyz(fdf, fdf->map, fdf->cam);
	}
	if (keycode == MAIN_B)
	{
		if (fdf->map->bg_color == 'b')
			fdf->map->bg_color = 'g';
		else if (fdf->map->bg_color == 'g')
			fdf->map->bg_color = 'w';
		else
			fdf->map->bg_color = 'b';
		rotate_xyz(fdf, fdf->map, fdf->cam);
	}
	return (0);
}

t_fdf	*fdf_init(t_map *map, t_cam *cam)
{
	t_fdf	*fdf;

	if (!(fdf = malloc(sizeof(t_fdf))))
		printf("EMPTY 1\n");
	if (!(fdf->mlx_ptr = mlx_init()))
		printf("EMPTY 2\n");
	if (!(fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, map->win_width, map->win_height, "Cool window!")))
		printf("EMPTY 3\n");
	if (!(fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, map->win_width, map->win_height)))
		printf("EMPTY 4\n");
	fdf->addr = mlx_get_data_addr(fdf->img_ptr, &(fdf->bits_per_pixel), &(fdf->line_length), &(fdf->endian));
	fdf->map = map;
	fdf->cam = cam;
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

// y and x begins at 0, like an index
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
	//printf("p1.row: %d | p1.col: %d | p2.row: %d | p2.col: %d | p1.color: %x | p2.color: %x\n", p1.row, p1.col, p2.row, p2.col, p1.color, p2.color);
	//printf("p1.x: %d | p1.y: %d | p1.z: %d | p2.x: %d | p2.y: %d | p2.z: %d\n", p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);

	if (p1.x < 0 || p1.y < 0 || p2.x < 0 || p2.y < 0)
	{
	//	printf("DDA: point x or y is smaller than 0\n");
		return (-1);
	}
	if (p1.x > fdf->map->win_width || p2.x > fdf->map->win_width || p1.y > fdf->map->win_height || p2.y > fdf->map->win_height)
	{
		//ft_putstr_fd("Points for line out of bounds!\n", 1);
		return (-1);
	}
	dda = get_dda(p1, p2);
	point_x = p1.x;
	point_y = p1.y;
	while (dda.steps >= 0)
	{
		//printf("dda:p1.color: %d\n", p1.color);
		ft_put_pixel(fdf, round(point_x), round(point_y), get_color(point_x, point_y, p1, p2));
		point_x += dda.sign_x * dda.inc_x;
		point_y += dda.sign_y * dda.inc_y;
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
	if (point[i].x > map->win_width || point[i].y > map->win_height)
	{
		return ;
	}
	if (i < map->point_amt)
	{
		//DRAWING POINTS
		//ft_put_pixel(fdf, point[i].x, point[i].y, point[i].color);
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

int main(int ac, char **av)
{
	t_fdf	*fdf;
	t_map	*map;
	t_cam	*cam;

	(void)ac;
	cam = cam_init();
	map = map_init(av);
	fdf = fdf_init(map, cam);
	rotate_xyz(fdf, fdf->map, fdf->cam);
	//Mouse presses
	mlx_hook(fdf->win_ptr, 4, 0, mouse_press, fdf);
	mlx_mouse_hook(fdf->win_ptr, mouse_press, fdf);
	//Mouse release
	mlx_hook(fdf->win_ptr, 5, 0, mouse_release, fdf);
	//Mouse movement
	mlx_hook(fdf->win_ptr, 6, 0, mouse_move, fdf);
	//Keyboard presses
	mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
	mlx_key_hook(fdf->win_ptr, key_press, fdf);
	mlx_loop(fdf->mlx_ptr);
}
