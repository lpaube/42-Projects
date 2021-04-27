/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:18:43 by laube             #+#    #+#             */
/*   Updated: 2021/04/26 23:08:10 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/* NEED TO DELETE (unallaowed) */
#include <stdio.h>
#include <limits.h>

void	*ft_memset(void *b, int c, size_t len);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strnew(size_t size);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
int		ft_strlen(const char *s);
int		ft_strequ(char const *s1, char const *s2);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstr(char const *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr(int n);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putendl(char const *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_memdel(void **ap);
void	*ft_memalloc(size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
