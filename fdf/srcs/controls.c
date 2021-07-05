/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:36:02 by laube             #+#    #+#             */
/*   Updated: 2021/07/05 11:54:31 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
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
		fdf->cam->beta += 1.5708;
	if (keycode == ARROW_RIGHT)
		fdf->cam->beta -= 1.5708;
	if (keycode == ARROW_UP)
		fdf->cam->alpha -= 1.5708;
	if (keycode == ARROW_DOWN)
		fdf->cam->alpha += 1.5708;
	if (keycode == MAIN_W)
		fdf->cam->move_y += 20;
	if (keycode == MAIN_S)
		fdf->cam->move_y -= 20;
	if (keycode == MAIN_D)
		fdf->cam->move_x -= 20;
	if (keycode == MAIN_A)
		fdf->cam->move_x += 20;
	if (keycode == MAIN_LESS && fdf->cam->z_scale > 0.5)
		fdf->cam->z_scale /= 1.1;
	if (keycode == MAIN_MORE && fdf->cam->z_scale < 30)
		fdf->cam->z_scale *= 1.1;
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
	}
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
*/
