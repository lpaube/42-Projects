/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:14:48 by laube             #+#    #+#             */
/*   Updated: 2021/06/14 16:34:31 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

//#include <X11/Xlib.h>
//#include <sys/ipc.h>
//#include <sys/shm.h>
//#include <X11/extensions/XShm.h>

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int	esc_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	return (0);
}

int main(void)
{
	t_data	data;
	
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 800, "What a good window!");
	mlx_key_hook(data.win_ptr, esc_hook, &data);
	mlx_loop(data.mlx_ptr);
}
