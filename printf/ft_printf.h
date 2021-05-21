/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:07:28 by laube             #+#    #+#             */
/*   Updated: 2021/05/20 23:10:12 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEX_TAB "0123456789abcdef"
# define FMT_TAB "cspdiuxX%"

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
// TO DELETE
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "libft.h"

struct s_fmt
{
	int		width;
	int		precision;
	int		pad_zero;
	int		left_justify;
	int		start;
	int		*curr_pos;
	const char	*fmt;
	int		fmt_len;
	char	type;
};

int	ft_printf(const char *fmt, ...);


# endif
