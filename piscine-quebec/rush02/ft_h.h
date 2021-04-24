#ifndef FT_H
#define FT_H
#include "ft_h.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// STRUCTS
typedef struct	s_dict
{
	char *value;
	char *wrt;
}				t_dict;

typedef struct	s_trio
{
	char	*hundred_units;
	char	*hundred;
	char	*dozen;
	char	*unit;
}				t_trio;

// PROTOTYPES
char	*format_string(char *str);
void	ft_free_split(char **tab);
int		ft_is_charset(char *src, int pos, char *charset);
int		ft_wrdlen(char *str, int pos, char *charset);
char	*ft_strdup(char *src, int pos, int size);
int		ft_strlen(char *str);
char	**ft_split_mod(char *str, char *charset);
char	**ft_split(char *str, char *charset);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_is_good(t_trio *trio);

//TRIO PROTOTYPES
char	*ft_strndup_buff(char *s1, int n, int buffer_extension);
char	*ft_strcat(char *dest, char *src);
char	*format_string(char *str);
t_trio	*trio_to_struct(char *str);
void	free_trio(t_trio *trio);

//DISPLAY PROTOTYPES
int	ft_display_zero(int n, struct s_dict *dict);
void	ft_display_hundred_units(char *str, struct s_dict *dict, int *f);
void	ft_display_hundred(char *str, struct s_dict *dict, int *f);
void	ft_display_dozen(char *str, struct s_dict *dict, int *f);
void	ft_display_unit(char *str, struct s_dict *dict, int *f);

#endif
