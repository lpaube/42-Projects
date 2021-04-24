#include "rush.h"
t_dict	*create_dict(char *path)
{
	char	*dict_str;
	char	**dict_tbl;

	dict_str = dict_to_str(path);
	dict_tbl = dict_to_table(dict_str);

	return (0);
}

char	*dict_to_str(char *path)
{
	int	counter;
	int	fd;
	char	c;
	char	*str;

	counter = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
 	while (read(fd, &c, 1))
		counter++;
	str = malloc((counter + 1) * sizeof(char));
	if (close(fd) == -1)
		return (0);
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	counter = 0;
	while (read(fd, &(str[counter]), 1))
		counter++;
	str[counter] = '\0';
	return (str);
}

char	**dict_to_table(char *str)
{
	int		i;
	int		counter;
	char	**table;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			counter++;
	}
	table = malloc(counter * (sizeof(char *)));
	ft_strsplit(table, str, "\n");
}
