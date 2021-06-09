/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:18:54 by laube             #+#    #+#             */
/*   Updated: 2021/05/24 16:59:12 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	to_pad(struct s_fmt *flag)
{
	int	tmp;

	tmp = 0;
	while (flag->width > flag->fmt_len + tmp)
	{
		ft_putchar_fd(flag->pad_zero, 1);
		(*flag->ret)++;
		tmp++;
	}
}

void	print_precision(struct s_fmt *flag)
{
	if (flag->precision < flag->fmt_len && flag->prec_on == 1)
		flag->pad_zero = ' ';
	while (flag->precision > flag->fmt_len)
	{
		ft_putchar_fd('0', 1);
		(*flag->ret)++;
		flag->fmt_len++;
	}
}

int	get_width(struct s_fmt *s_flag)
{
	char	*width_str;
	char	*start_width;
	int		counter;
	int		holder;
	int		width;

	holder = s_flag->curr_pos;
	counter = 0;
	while (ft_isdigit(s_flag->fmt[holder++]))
		counter++;
	width_str = ft_calloc(counter + 1, sizeof(char));
	start_width = width_str;
	while (ft_isdigit(s_flag->fmt[s_flag->curr_pos]))
	{
		*width_str = s_flag->fmt[s_flag->curr_pos++];
		width_str++;
	}
	width = ft_atoi((const char *)start_width);
	free(start_width);
	start_width = NULL;
	return (width);
}

int	get_precision(struct s_fmt *s_flag, va_list *ap)
{
	int		counter;
	char	*pr;
	int		precision;
	int		i;

	s_flag->prec_on = 1;
	precision = 0;
	i = 0;
	s_flag->curr_pos++;
	if (s_flag->fmt[s_flag->curr_pos] == '*')
		return (va_arg(*ap, int));
	counter = mod_strlen(&(s_flag->fmt[s_flag->curr_pos]));
	if (!counter)
		return (0);
	pr = ft_calloc(mod_strlen(&(s_flag->fmt[s_flag->curr_pos])), sizeof(char));
	while (i < counter)
	{
		pr[i] = s_flag->fmt[s_flag->curr_pos];
		i++;
		pr[i] = 0;
		s_flag->curr_pos++;
	}
	precision = ft_atoi(pr);
	free(pr);
	return (precision);
}
