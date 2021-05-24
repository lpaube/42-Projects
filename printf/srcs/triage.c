/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:31:56 by laube             #+#    #+#             */
/*   Updated: 2021/05/24 10:57:16 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_triage_flags(struct s_fmt *s_flag, va_list *ap)
{
	while (s_flag->fmt[s_flag->curr_pos])
	{
		while (s_flag->fmt[s_flag->curr_pos] == ' ')
		{
			ft_putchar_fd(' ', 1);
			s_flag->curr_pos++;
		}
		if (s_flag->fmt[s_flag->curr_pos] == '-')
			s_flag->left_justify = 1;
		if (ft_isdigit(s_flag->fmt[s_flag->curr_pos]))
		{
			if (s_flag->fmt[s_flag->curr_pos] == '0')
			{
				if (s_flag->left_justify == 0)
						s_flag->pad_zero = '0';
			}
			else if (ft_isdigit(s_flag->fmt[s_flag->curr_pos]))
				s_flag->width = get_width(s_flag);
		}
		if (s_flag->fmt[s_flag->curr_pos] == '*')
		{
			
			s_flag->width = va_arg(*ap, int);
			if (s_flag->width < 0)
			{
				s_flag->left_justify = 1;
				s_flag->pad_zero = ' ';
				s_flag->width = -(s_flag->width);
			}
		}
		if (s_flag->fmt[s_flag->curr_pos] == '.')
			s_flag->precision = get_precision(s_flag, ap);
		if (s_flag->fmt[s_flag->curr_pos] == s_flag->type)
			return (1);
		s_flag->curr_pos++;
	}
	return (0);
}

void	ft_triage_struct(va_list *ap, int *i, const char *fmt)
{
	char			*str_holder;
	int				tmp;
	struct s_fmt	flag;

	str_holder = 0;
	tmp = *i;
	flag.width = 0;
	flag.precision = -1;
	flag.pad_zero = ' ';
	flag.left_justify = 0;
	flag.start = *i;
	flag.curr_pos = *i;
	flag.fmt = fmt;
	flag.type = 0;
	while (fmt[tmp] && !str_holder)
	{
		str_holder = ft_strchr(FMT_TAB, fmt[tmp++]);
	}
	if (str_holder[0])
		flag.type = str_holder[0];
	if (ft_triage_flags(&flag, ap) == 1)
	{
		ft_triage(flag.type, ap, &flag);
	}
	*i = flag.curr_pos;
}

void	ft_triage(char c, va_list *ap, struct s_fmt *flag)
{
	if (c == 'c')
		c_val_control(ap, flag);
	else if (c == 's')
		s_val_control(ap, flag);
	else if (c == 'p')
		p_val_control(ap, flag);
	else if (c == 'd' || c == 'i')
		d_val_control(ap, flag);
	else if (c == 'u')
		u_val_control(ap, flag);
	else if (c == 'x' || c == 'X')
		x_val_control(ap, flag);
	else if (c == '%')
		s_val_control(ap, flag);
	else
		return ;
}
