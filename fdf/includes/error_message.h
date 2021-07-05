/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 13:55:07 by laube             #+#    #+#             */
/*   Updated: 2021/07/05 16:56:16 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGE_H
# define ERROR_MESSAGE_H

# define ERR_MAP_OPEN		"Returned invalid file descriptor"
# define ERR_MAP_READ		"get_next_line returned '-1'"
# define ERR_ARGV			"Correct usage: ./fdf <MAP_FILE>"
# define ERR_FDF			"Could not allocate memory for structure fdf"
# define ERR_MAP			"Could not allocate memory for map"
# define ERR_CAM			"Could not allocate memory for camera"
# define ERR_MLX			"Could not allocate memory for mlx"
# define ERR_WIN			"Could not allocate memory for window"
# define ERR_IMG			"Could not allocate memory for img"
# define ERR_ADDR			"Could not allocate memory for pixels address"
# define ERR_POINT			"Could not allocate memory for points"
# define ERR_POINT_OG		"Could not allocate memory for points_og"
# define ERR_MAP_WIDTH		"ERROR: The map has varying width. It must have the same width for each line."
# define ERR_INVALID_MAP	"ERROR: Invalid map"

# endif
