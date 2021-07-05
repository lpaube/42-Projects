/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:36:02 by laube             #+#    #+#             */
/*   Updated: 2021/07/05 17:35:12 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	key_translation(int keycode, t_fdf *fdf)
{
	if (keycode == MAIN_W)
		fdf->cam->move_y += 20;
	if (keycode == MAIN_S)
		fdf->cam->move_y -= 20;
	if (keycode == MAIN_D)
		fdf->cam->move_x -= 20;
	if (keycode == MAIN_A)
		fdf->cam->move_x += 20;
}

void	key_rotation(int keycode, t_fdf *fdf)
{
	if (keycode == ARROW_LEFT)
		fdf->cam->beta += 1.5708;
	if (keycode == ARROW_RIGHT)
		fdf->cam->beta -= 1.5708;
	if (keycode == ARROW_UP)
		fdf->cam->alpha -= 1.5708;
	if (keycode == ARROW_DOWN)
		fdf->cam->alpha += 1.5708;
	if (keycode == MAIN_LESS && fdf->cam->z_scale > 0.5)
		fdf->cam->z_scale /= 1.1;
	if (keycode == MAIN_MORE && fdf->cam->z_scale < 30)
		fdf->cam->z_scale *= 1.1;
}

void	key_projection(int keycode, t_fdf *fdf)
{
	int	i;

	if (keycode == MAIN_I)
	{
		fdf->cam->iso = 1;
		fdf->cam->alpha = 0;
		fdf->cam->beta = 0;
		fdf->cam->gamma = 0;
		fdf->map->first = 1;
		get_line_len(fdf->map);
	}
	if (keycode == MAIN_P)
	{
		fdf->cam->iso = 0;
		fdf->cam->alpha = 0;
		fdf->cam->beta = 0;
		fdf->cam->gamma = 0;
		fdf->map->first = 1;
		get_line_len(fdf->map);
	}
	i = 0;
	while (i < fdf->map->point_amt)
		coord_to_point(fdf->map, &(fdf->map->point_og[i++]));
}

int	key_press(int keycode, t_fdf *fdf)
{
	if (keycode == MAIN_ESC)
		close_window(fdf);
	key_rotation(keycode, fdf);
	key_translation(keycode, fdf);
	if (keycode == MAIN_I || keycode == MAIN_P)
		key_projection(keycode, fdf);
	if (keycode == MAIN_B)
	{
		if (fdf->map->bg_color == 'b')
			fdf->map->bg_color = 'g';
		else if (fdf->map->bg_color == 'g')
			fdf->map->bg_color = 'w';
		else
			fdf->map->bg_color = 'b';
	}
	update_p(fdf, fdf->map, fdf->cam);
	return (0);
}
