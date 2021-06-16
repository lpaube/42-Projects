/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:29:35 by laube             #+#    #+#             */
/*   Updated: 2021/06/15 19:02:03 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

typedef struct	s_map
{
	int	width;
	int	height;
}	t_map;

#endif
