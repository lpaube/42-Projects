/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:07:28 by laube             #+#    #+#             */
/*   Updated: 2021/05/17 21:58:08 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
// TO DELETE
#include <stdio.h>
#include <string.h>

/* JUNK PROTOTYPES. WILL NEED TO ADD THE LIBRARY PROPERLY IN MAKEFILE */
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);

int	ft_printf(const char *fmt, ...);


# endif
