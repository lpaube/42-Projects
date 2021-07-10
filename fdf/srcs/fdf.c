/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:14:48 by laube             #+#    #+#             */
/*   Updated: 2021/07/09 16:57:17 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	close_window(t_fdf *fdf)
{
	free(fdf->map->point);
	free(fdf->cam);
	free(fdf->map->point_og);
	free(fdf->map);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	free(fdf);
	fscanf(stdin, "c");
	exit(0);
}

int	click_close(void *param)
{
	(void)param;
	exit(0);
}

void	hook_functions(t_fdf *fdf)
{
	mlx_hook(fdf->win_ptr, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win_ptr, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->win_ptr, 6, 0, mouse_move, fdf);
	mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, click_close, fdf);
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
	exit(1);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;
	t_map	*map;
	t_cam	*cam;

	errno = 0;
	if (ac != 2)
		terminate(ERR_ARGV);
	cam = cam_init();
	map = map_init(av);
	fdf = fdf_init(map, cam);
	hook_functions(fdf);
	update_p(fdf, fdf->map, fdf->cam);
	mlx_loop(fdf->mlx_ptr);
}
