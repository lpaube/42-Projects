/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:18:43 by laube             #+#    #+#             */
/*   Updated: 2021/05/06 14:52:00 by laube            ###   ########.fr       */
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

/*	GENERATED PROTOTYPES (PROTOTYPICAL) 	*/
void	test_ft_putendl_fd(void);
void	test_ft_putstr_fd(void);
void	test_ft_putchar_fd(void);
void	test_ft_split(void);
void	test_ft_strtrim(void);
char	*ft_strtrim(char const *s1, char const *set);
void	test_ft_strjoin(void);
void	test_ft_substr(void);
int	ft_isascii(int c);
void	test_ft_tolower(void);
void	test_ft_toupper(void);
void	test_ft_isprint(void);
void	test_ft_isascii(void);
void	test_ft_isalnum(void);
int	ft_toupper(int c);
int	ft_tolower(int c);
int	ft_isprint(int c);
int	isascii(int c);
int	ft_isalnum(int c);
void	test_ft_isdigit(void);
int	ft_isdigit(int c);
void	test_ft_isalpha(void);
int	ft_isalpha(int c);
void	test_ft_atoi(void);
int	ft_atoi(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	test_ft_strncmp(void);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
