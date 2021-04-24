#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str);
char	*ft_strdup(char *dest, char *src);

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct	s_stock_str	*arr;
	int	i;
	
	arr = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!arr)
		return (0);
	i = 0;
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(arr[i].copy, av[i]); 
		i++;
	}
	arr[i].str = 0;
	return (arr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *dest, char *src)
{
	int	i;

	i = 0;
	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	while (src[i])
	{
		printf("src[i]: %c\n", src[i]);
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	printf("Dest: %s\n", dest);
	return (dest);
}
