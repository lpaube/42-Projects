/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:45:03 by laube             #+#    #+#             */
/*   Updated: 2021/07/05 15:11:33 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	cam_zoom(int button, t_fdf *fdf)
{
	int	i;

	if (button == 4 && fdf->map->line_len < round(fdf->map->w_width / 8))
	{
		fdf->map->line_len = ceil(fdf->map->line_len * 1.1);
		i = 0;
		while (i < fdf->map->point_amt)
			coord_to_point(fdf->map, &(fdf->map->point_og[i++]));
	}
	if (button == 5 && fdf->map->line_len > 3)
	{
		fdf->map->line_len = floor(fdf->map->line_len / 1.1);
		i = 0;
		while (i < fdf->map->point_amt)
			coord_to_point(fdf->map, &(fdf->map->point_og[i++]));
	}
}

int	mouse_press(int button, int x, int y, t_fdf *fdf)
{
	//SCROLL TO ZOOM
	cam_zoom(button, fdf);
	//MOUSE CLICK AND HOLD TO ROTATE
	if (button == 1)
	{
		fdf->cam->mouse_press = 1;
		fdf->cam->mouse_x = x;
		fdf->cam->mouse_y = y;
	}
	update_p(fdf, fdf->map, fdf->cam);
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
	inc = 0.004;
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
