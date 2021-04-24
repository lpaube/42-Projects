#ifndef CAT_H
# define CAT_H

# include <sys/errno.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	read_stdin(void);
int		ft_cat(int argc, char **argv);

#endif
