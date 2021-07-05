/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:29:35 by laube             #+#    #+#             */
/*   Updated: 2021/07/04 21:32:30 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//# include "./key_codes_mac.h"
# include "./key_codes_linux.h"
# include "../libft/libft.h"
# include "./error_message.h"
# include "../libft/get_next_line.h"
# include "../mlx_mac/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>

typedef struct	s_point
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

typedef struct	s_map
{
	int	win_width;
	int	win_height;
	int	width;
	int	height;
	int	point_amt;
	int	line_len;
	int	margin;
	int	first;
	int	big_z;
	int	small_z;
	char	bg_color;
	t_point	*point;
	t_point *point_og;
}				t_map;

typedef struct	s_cam
{
	
	double	z_scale;
	double	alpha;
	double	beta;
	double	gamma;
	int	move_x;
	int	move_y;
	int	mouse_press;
	int	mouse_x;
	int	mouse_y;
	int	iso;
}				t_cam;

typedef struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	*map;
	t_cam	*cam;
}				t_fdf;


typedef struct	s_dda
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
void	terminate(char *s);
t_point set_point(t_map *map, char *num, int col, int row);
void	map_to_point(t_map *map, int fd, int i);
void 	iso(t_point *point, t_map *map);
void	get_line_len(t_map *map);
void	ft_put_pixel(t_fdf *fdf, int x, int y, int color);
void	clear_img(t_fdf *fdf, t_map *map);
void	color_point(t_map *map, t_point *point);
int		get_color(int curr_x, int curr_y, t_point p1, t_point p2);

#endif
