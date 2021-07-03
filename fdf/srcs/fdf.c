/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:14:48 by laube             #+#    #+#             */
/*   Updated: 2021/07/03 12:41:00 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	coord_to_point(t_map *map, t_point *point);
void	draw_point(t_fdf *fdf, t_map *map, t_point *point, int i);
void	ft_put_pixel(t_fdf *fdf, int x, int y, int color);

void	clear_img(t_fdf *fdf)
{
	int	i;
	int	color;

	i = 0;
	if (fdf->map->bg_color == 'w')
		color = 0x00FFFFFF;
	else if (fdf->map->bg_color == 'g')
		color = 0x00335555;
	else
		color = 0;
	while (i < (fdf->map->win_width * fdf->map->win_height))
	{
		ft_put_pixel(fdf, i % fdf->map->win_width, i / fdf->map->win_width, color);
		i++;
	}
}

void	rotate_xyz(t_fdf *fdf)
{
	int	i;
	int	trans_x;
	int	trans_y;
	int	tmp_x;
	int	tmp_y;
	t_point	mid_p;

	(void)tmp_x;
	(void)tmp_y;
	clear_img(fdf);
	i = 0;
	while (i < fdf->map->point_amt)
	{
		fdf->map->point[i] = fdf->map->point_og[i];
		i++;
	}
	iso(fdf->map->point, fdf->map);
	mid_p = fdf->map->point[((fdf->map->height / 2) * fdf->map->width) + (fdf->map->width / 2)];
	trans_x = mid_p.x;
	trans_y = mid_p.y;
	
	i = 0;
	while (i < fdf->map->point_amt)
	{
		tmp_x = fdf->map->point[i].x - trans_x;
		tmp_y = fdf->map->point[i].y - trans_y;
		//Rotate Z
		fdf->map->point[i].x = tmp_x * cos(fdf->map->gamma) + tmp_y * sin(fdf->map->gamma);
		fdf->map->point[i].y = tmp_x * -sin(fdf->map->gamma) + tmp_y * cos(fdf->map->gamma);
		//Rotate Y
		fdf->map->point[i].x = tmp_x * cos(fdf->map->beta) + fdf->map->point[i].z * -sin(fdf->map->beta) + trans_x;
		fdf->map->point[i].z = tmp_x * sin(fdf->map->beta) + fdf->map->point[i].z * cos(fdf->map->beta);
		//Rotate X
		tmp_x = fdf->map->point[i].x;
		tmp_y = fdf->map->point[i].y;
		fdf->map->point[i].y = tmp_y * cos(fdf->map->alpha) + fdf->map->point[i].z * sin(fdf->map->alpha) + trans_y;
		fdf->map->point[i].z = tmp_y * -sin(fdf->map->alpha) + fdf->map->point[i].z * cos(fdf->map->alpha);
		//Movement
		fdf->map->point[i].x += fdf->map->move_x;
		fdf->map->point[i].y += fdf->map->move_y;
		i++;
	}
	i = 0;
	while (i < fdf->map->point_amt)
	{
		if (fdf->map->iso)
			draw_point(fdf, fdf->map, fdf->map->point, i);
		else if (fdf->map->iso == 0)
			draw_point(fdf, fdf->map, fdf->map->point_og, i);
		i++;
	}
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
		rotate_xyz(fdf);
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
		rotate_xyz(fdf);
	}
	//MOUSE CLICK AND HOLD
	if (button == 1)
	{
		fdf->map->mouse_press = 1;
		fdf->map->mouse_x = x;
		fdf->map->mouse_y = y;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_fdf *fdf)
{
	(void)button;
	(void)x;
	(void)y;
	fdf->map->mouse_press = 0;
	return (0);
}

int	mouse_move(int x, int y, t_fdf *fdf)
{
	double	inc;
	int		change_state;

	change_state = 0;
	inc = 0.01;
	if (fdf->map->mouse_press)
	{
		if (fdf->map->mouse_x != x)
		{
			fdf->map->beta += inc * (fdf->map->mouse_x - x);
			fdf->map->mouse_x = x;
			change_state = 1;
		}
		if (fdf->map->mouse_y != y)
		{
			fdf->map->alpha -= inc * (fdf->map->mouse_y - y);
			fdf->map->mouse_y = y;
			change_state = 1;
		}
		if (change_state == 1)
			rotate_xyz(fdf);
	}
	return (0);
}

int	key_press(int keycode, t_fdf *fdf)
{
	double			inc;

	printf("keycode: %d\n", keycode);
	inc = 0.1;
	if (keycode == MAIN_ESC)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		exit(0);
	}
	if (keycode == ARROW_LEFT)
	{
		fdf->map->beta += inc;
		rotate_xyz(fdf);
	}
	if (keycode == ARROW_RIGHT)
	{
		fdf->map->beta -= inc;
		rotate_xyz(fdf);
	}
	if (keycode == ARROW_UP)
	{
		fdf->map->alpha -= inc;
		rotate_xyz(fdf);
	}
	if (keycode == ARROW_DOWN)
	{
		fdf->map->alpha += inc;
		rotate_xyz(fdf);
	}
	if (keycode == MAIN_W)
	{
		fdf->map->move_y += 20;
		rotate_xyz(fdf);
	}
	if (keycode == MAIN_S)
	{
		fdf->map->move_y -= 20;
		rotate_xyz(fdf);
	}
	if (keycode == MAIN_D)
	{
		fdf->map->move_x -= 20;
		rotate_xyz(fdf);
	}
	if (keycode == MAIN_A)
	{
		fdf->map->move_x += 20;
		rotate_xyz(fdf);
	}
	if (keycode == MAIN_LESS && fdf->map->z_scale > 0.5)
	{
		fdf->map->z_scale /= 1.1;
		rotate_xyz(fdf);
	}
	if (keycode == MAIN_MORE && fdf->map->z_scale < 20)
	{
		fdf->map->z_scale *= 1.1;
		rotate_xyz(fdf);
	}
	if (keycode == MAIN_I && fdf->map->iso != 1)
	{
		fdf->map->iso = 1;
		rotate_xyz(fdf);
	}
	if (keycode == MAIN_P && fdf->map->iso != 0)
	{
		fdf->map->iso = 0;
		rotate_xyz(fdf);
	}
	if (keycode == MAIN_B)
	{
		if (fdf->map->bg_color == 'b')
			fdf->map->bg_color = 'g';
		else if (fdf->map->bg_color == 'g')
			fdf->map->bg_color = 'w';
		else
			fdf->map->bg_color = 'b';
		rotate_xyz(fdf);
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
	if (!(fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, map->win_width, map->win_height, "Cool window!")))
		printf("EMPTY 3\n");
	if (!(fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, map->win_width, map->win_height)))
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
		ft_put_pixel(fdf, round(point_x), round(point_y), p2.color);
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
	//	printf("Point is smaller than 0 (OB) | p.x: %d | p.y: %d | i: %d\n", point[i].x, point[i].y, i);
		return ;
	}
	if (point[i].x > map->win_width || point[i].y > map->win_height)
	{
		//printf("Point is greater than 0 (OB) | p.x: %d | p.y: %d | i: %d\n", point[i].x, point[i].y, i);
		return ;
	}
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

/*
void	trans_topleft(t_map *map, int id)
{
	int	i;
	int	trans_left;
	int	trans_top;

	trans_left = map->point[map->width * (map->height - 1)].x;
	if (map->point[0].x > map->win_width)
		trans_left = map->point[0].x;
	trans_top = map->point[0].y;
	i = 0;
	while (i < map->point_amt)
	{
		// 1 executes first if; 2 executes both if; 3 executes last if
		if (id > 0 && id <= 2)
		{
			map->point[i].x -= trans_left;
			map->point[i].y -= trans_top;
		}
		if (id > 1)
		{
			map->point_og[i].x -= trans_left;
			map->point_og[i].y -= trans_top;
		}
		i++;
	}
}
*/

// Control function for drawing to an image
void	draw_control(t_map *map, t_fdf *fdf)
{
	// Attaches the initial map to top left corner
	iso(map->point, map);
	map->move_x += -map->point[map->width * (map->height - 1)].x;
	map->move_y += -map->point[0].y;
	rotate_xyz(fdf);
}

int main(int ac, char **av)
{
	t_fdf	*fdf;
	t_map	*map;

	(void)ac;
	map = map_init(av);
	fdf = fdf_init(map);
	draw_control(map, fdf);
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
