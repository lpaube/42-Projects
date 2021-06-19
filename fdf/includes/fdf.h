/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:29:35 by laube             #+#    #+#             */
/*   Updated: 2021/06/18 21:04:05 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# define HEIGHT	1080
# define WIDTH	1920
# define ABS(a)	(a) < 0 ? -(a) : (a)

typedef struct	s_map
{
	int	width;
	int	height;
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

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

#endif
