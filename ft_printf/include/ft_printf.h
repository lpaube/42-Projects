/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:07:28 by laube             #+#    #+#             */
/*   Updated: 2021/05/24 17:15:54 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
// TO DELETE
#include <stdio.h>
#include <string.h>
#include <limits.h>

# define HEX_TAB "0123456789abcdef"
# define FMT_TAB "cspdiuxXaAbBCDeEfFgGhHIjJkKlLmMnNoOPqQrRsStTUvVyYzZ%"

struct s_fmt
{
	int		width;
	int		precision;
	int		prec_on;
	char	pad_zero;
	int		left_justify;
	int		start;
	int		curr_pos;
	const char	*fmt;
	int		fmt_len;
	char	type;
	int		*ret;
};

int		ft_printf(const char *fmt, ...);
void	ft_triage(char c, va_list *ap, struct s_fmt *flag);
void	c_val_control(va_list *ap, struct s_fmt *flag);
void	d_val_pos(struct s_fmt *flag, int tmp_len, char *val_str);
void	d_val_neg(struct s_fmt *flag, int tmp_len, char *val_str);
void	d_val_control(va_list *ap, struct s_fmt *flag);
void	to_pad(struct s_fmt *flag);
void	print_precision(struct s_fmt *flag);
int		get_width(struct s_fmt *s_flag);
int		get_precision(struct s_fmt *s_flag, va_list *ap);
int		mod_strlen(const char *str);
int		p_val_len(unsigned char *buff, int init_len);
void	p_val(unsigned char *buff, int i, struct s_fmt *flag);
void	p_val_control(va_list *ap, struct s_fmt *flag);
void	ft_putnstr_fd(char *s, int fd, int len);
void	s_val_control(va_list *ap, struct s_fmt *flag);
int		ft_triage_flags(struct s_fmt *s_flag, va_list *ap);
void	ft_triage_struct(va_list *ap, int *i, const char *fmt, int *ret);
void	u_val_control(va_list *ap, struct s_fmt *flag);
void	ft_dtohex(unsigned int num, int *rm_zeros, char cap, struct s_fmt *fg);
int		x_val_len(unsigned int val);
void	x_val_control(va_list *ap, struct s_fmt *flag);
void	x_val(char c, struct s_fmt *flag, unsigned int val);
int		free_it(void **mem, int free_state);
void	int_val_control(char *val_str, struct s_fmt *flag);






# endif
