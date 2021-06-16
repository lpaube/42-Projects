/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:14:48 by laube             #+#    #+#             */
/*   Updated: 2021/06/15 22:55:45 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/fdf.h"

//#include <X11/Xlib.h>
//#include <sys/ipc.h>
//#include <sys/shm.h>
//#include <X11/extensions/XShm.h>

int	esc_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		exit(0);
	}
	return (0);
}


t_fdf	fdf_init(void)
{
	t_fdf	*fdf;

	fdf->mlx_ptr = mlx.init();
	fdf->win_ptr = mlx_new_window(mlx_ptr, 1000, 800, "Cool window!");
}

t_map	map_init(void)
{
	t_map	*map;

	map->width = 0;
	map->height = 0;
}

int main(void)
{
	t_fdf	*fdf;
	t_map	*map;

	map = map_init();
	fdf = fdf_init();
	mlx_key_hook(fdf->win_ptr, esc_hook, fdf);
	mlx_loop(fdf->mlx_ptr);
}
