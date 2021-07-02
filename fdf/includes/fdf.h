/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:29:35 by laube             #+#    #+#             */
/*   Updated: 2021/07/01 23:29:45 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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
	double	alpha;
	double	beta;
	double	gamma;
	t_point	*point;
	t_point *point_og;
}				t_map;

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
t_point set_point(t_map *map, int z, int col, int row);
void	map_to_point(t_map *map, int fd, int i);
void	adjust_points(t_fdf	*fdf);
void 	iso(int *x, int *y, int *z, t_map *map);
void	trans_topleft(t_map *map, int id);

#endif
