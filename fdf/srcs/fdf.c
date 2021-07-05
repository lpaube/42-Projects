/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:14:48 by laube             #+#    #+#             */
/*   Updated: 2021/07/05 11:57:14 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	coord_to_point(t_map *map, t_point *point);
void	draw_point(t_fdf *fdf, t_map *map, t_point *point, int i);

void	update_p(t_fdf *fdf, t_map *map, t_cam *cam)
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
	if (button == 4 && fdf->map->line_len < round(fdf->map->w_width / 8))
	{
		fdf->map->line_len = ceil(fdf->map->line_len * 1.1);
		i = 0;
		while (i < fdf->map->point_amt)
		{
			coord_to_point(fdf->map, &(fdf->map->point_og[i]));
			i++;
		}
		update_p(fdf, fdf->map, fdf->cam);
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
		update_p(fdf, fdf->map, fdf->cam);
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
			update_p(fdf, fdf->map, fdf->cam);
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
		update_p(fdf, fdf->map, fdf->cam);
	}
	if (keycode == ARROW_RIGHT)
	{
		fdf->cam->beta -= 1.5708;
		update_p(fdf, fdf->map, fdf->cam);
	}
	if (keycode == ARROW_UP)
	{
		fdf->cam->alpha -= 1.5708;
		update_p(fdf, fdf->map, fdf->cam);
	}
	if (keycode == ARROW_DOWN)
	{
		fdf->cam->alpha += 1.5708;
		update_p(fdf, fdf->map, fdf->cam);
	}
	if (keycode == MAIN_W)
	{
		fdf->cam->move_y += 20;
		update_p(fdf, fdf->map, fdf->cam);
	}
	if (keycode == MAIN_S)
	{
		fdf->cam->move_y -= 20;
		update_p(fdf, fdf->map, fdf->cam);
	}
	if (keycode == MAIN_D)
	{
		fdf->cam->move_x -= 20;
		update_p(fdf, fdf->map, fdf->cam);
	}
	if (keycode == MAIN_A)
	{
		fdf->cam->move_x += 20;
		update_p(fdf, fdf->map, fdf->cam);
	}
	if (keycode == MAIN_LESS && fdf->cam->z_scale > 0.5)
	{
		fdf->cam->z_scale /= 1.1;
		update_p(fdf, fdf->map, fdf->cam);
	}
	if (keycode == MAIN_MORE && fdf->cam->z_scale < 30)
	{
		fdf->cam->z_scale *= 1.1;
		update_p(fdf, fdf->map, fdf->cam);
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
		update_p(fdf, fdf->map, fdf->cam);
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
		update_p(fdf, fdf->map, fdf->cam);
	}
	if (keycode == MAIN_B)
	{
		if (fdf->map->bg_color == 'b')
			fdf->map->bg_color = 'g';
		else if (fdf->map->bg_color == 'g')
			fdf->map->bg_color = 'w';
		else
			fdf->map->bg_color = 'b';
		update_p(fdf, fdf->map, fdf->cam);
	}
	return (0);
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

int main(int ac, char **av)
{
	t_fdf	*fdf;
	t_map	*map;
	t_cam	*cam;

	(void)ac;
	cam = cam_init();
	map = map_init(av);
	fdf = fdf_init(map, cam);
	update_p(fdf, fdf->map, fdf->cam);
	//Mouse presses
	mlx_hook(fdf->win_ptr, 4, 0, mouse_press, fdf);
//	mlx_mouse_hook(fdf->win_ptr, mouse_press, fdf);
	//Mouse release
	mlx_hook(fdf->win_ptr, 5, 0, mouse_release, fdf);
	//Mouse movement
	mlx_hook(fdf->win_ptr, 6, 0, mouse_move, fdf);
	//Keyboard presses
	mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
//	mlx_key_hook(fdf->win_ptr, key_press, fdf);
	mlx_loop(fdf->mlx_ptr);
}
