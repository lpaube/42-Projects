/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:29:35 by laube             #+#    #+#             */
/*   Updated: 2021/07/13 12:09:22 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MENU_WIDTH	50
# include "key_codes_mac.h"
//# include "./key_codes_linux.h"
# include "../libft/libft.h"
# include "error_message.h"
# include "../libft/get_next_line.h"
# include "../mlx_mac/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	row;
	int	col;
	int	expl_color;
	int	expl_color_set;
}	t_point;

typedef struct s_map
{
	int		w_width;
	int		w_height;
	int		width;
	int		height;
	int		point_amt;
	int		line_len;
	int		margin;
	int		first;
	int		big_z;
	int		small_z;
	char	bg_color;
	t_point	*point;
	t_point	*point_og;
}				t_map;

typedef struct s_cam
{
	double	z_scale;
	double	alpha;
	double	beta;
	double	gamma;
	int		move_x;
	int		move_y;
	int		mouse_press;
	int		mouse_x;
	int		mouse_y;
	int		iso;
}				t_cam;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		px_bits;
	int		ln_len;
	int		endian;
	t_map	*map;
	t_cam	*cam;
}				t_fdf;

typedef struct s_dda
{
	double	delta_x;
	double	delta_y;
	double	steps;
	double	inc_x;
	double	inc_y;
	int		sign_x;
	int		sign_y;
}				t_dda;

t_map	*map_init(char **av);
t_cam	*cam_init(void);
t_fdf	*fdf_init(t_map *map, t_cam *cam);
void	terminate(char *s);
void	map_to_point(t_map *map, int fd, int i);
void	coord_to_point(t_map *map, t_point *point);
void	get_map_dim(char **av, t_map *map);
t_point	set_point(t_map *map, char *num, int col, int row);
void	iso(t_point *point, t_map *map);
void	get_line_len(t_map *map);
void	ft_put_pixel(t_fdf *fdf, int x, int y, int color);
void	clear_img(t_fdf *fdf, t_map *map);
void	color_point(t_map *map, t_point *point);
int		get_color(int curr_x, int curr_y, t_point p1, t_point p2);
int		key_press(int keycode, t_fdf *fdf);
int		mouse_press(int button, int x, int y, t_fdf *fdf);
int		mouse_release(int button, int x, int y, t_fdf *fdf);
int		mouse_move(int x, int y, t_fdf *fdf);
void	update_p(t_fdf *fdf, t_map *map, t_cam *cam);
void	draw_point(t_fdf *fdf, t_map *map, t_point *point, int i);
void	close_window(t_fdf *fdf);

#endif
