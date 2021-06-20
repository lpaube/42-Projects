/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:29:35 by laube             #+#    #+#             */
/*   Updated: 2021/06/20 19:43:37 by laube            ###   ########.fr       */
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

# define HEIGHT	800
# define WIDTH	1200

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
	int	width;
	int	height;
	int	point_amt;
	int	line_len;
	int	margin;
	t_point	*point;
}	t_map;

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
}	t_fdf;


typedef struct	s_dda
{
	double	delta_x;
	double	delta_y;
	double	steps;
	double	inc_x;
	double	inc_y;
	int		sign_x;
	int		sign_y;
}	t_dda;

t_point set_point(t_map *map, int z, int col, int row);
void	map_init(t_map *map, char **av);
void	terminate(char *s);

#endif