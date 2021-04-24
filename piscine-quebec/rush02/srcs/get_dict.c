/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 10:42:14 by laube             #+#    #+#             */
/*   Updated: 2021/03/27 16:02:21 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// TO OPEN THE DICTIONARY, AND PUT ITS CONTENT IN OUR BUFFER FILESTR
char	*openfile(char *path)
{
	int	dict;
	int	nbchars;
	int	i;
	char	currchar;
	char	*filestr;

	if ((dict = open(path, O_RDONLY)) < 0)
	{
		return (0);
	}
	nbchars = 0;
	while (read(dict, &currchar, 1))
		nbchars++;
	filestr = malloc(sizeof(char) * (nbchars + 1));
	close(dict);
	dict = open(path, O_RDONLY);
	i = 0;
	while (read(dict, filestr + i, 1))
		i++;
	close(dict);
	filestr[nbchars] = '\0';
	return (filestr);
}

// TO SEPARATE OUR BUFFER OF DICTIONARY INTO INDIVIDUAL LINES
char	**to_lines(char *path)
{
	char	**lines;
	char *filestr;

	filestr = openfile(path);
	//Using ft_split from ft_split.c
	lines = ft_split(filestr, "\n");
	return (lines);
}

// TO GET NUMBER OF LINES
int	get_number_of_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
		i++;
	return (i);
}

// COPIED COPIED COPIED
char			*ft_rmv_spaces(char *str)
{
	int		i;
	char	*tab;
	int		j;
	int		k;

	if (!(tab = malloc(sizeof(*tab) * (ft_strlen(str) + 2))))
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] == 32)
		i++;
	j = ft_strlen(str);
	while (j >= 0 && str[j] == 32)
		j++;
	k = 0;
	while (k < j - i + 1)
	{
		tab[k] = str[i + k];
		k++;
	}
	tab[k] = '\0';
	return (tab);
}

t_dict			*ft_dict_parsing(int size, char **dict)
{
	int		i;
	t_dict	*dict_sct;
	char	**split_value;

	dict_sct = malloc(sizeof(*dict_sct) * (size + 1));
	i = 0;
	while (i < size)
	{
		split_value = ft_split_mod(dict[i], ":");
		if (split_value == 0)
			continue ;
		dict_sct[i].value = ft_rmv_spaces(split_value[0]);
		dict_sct[i].wrt = ft_rmv_spaces(split_value[1]);
		ft_free_split(split_value);
		i++;
	}
	dict_sct[i].value = 0;
	return (dict_sct);
}

int				ft_dictmaxlen(t_dict *dict)
{
	int i;
	int max;
	int length;

	i = 0;
	max = 0;
	while (dict[i].value)
	{
		length = ft_strlen(dict[i].value);
		if (length > max)
			max = length;
		i++;
	}
	return (max + 2);
}
// END OF COPY COPY COPY
//
// SETTING UP THE DICTIONNARY (CALLING OTHER DICT FUNCTIONS)
t_dict			*ft_dict_setup(char *dict_path)
{
	t_dict	*dict_sct;
	char	**dict_sub;
	int		dict_length;

	dict_sub = to_lines(dict_path);
	dict_length = get_number_of_lines(dict_sub);
	dict_sct = ft_dict_parsing(dict_length, dict_sub);
	free(dict_sub);
	return (dict_sct);
}

// CONVERT THE INPUT *CHAR TO TEXT *CHAR
void	convert_to_text(char *number ,t_dict *dict)
{
	char	*nb;
	int		i;
	int		size;
	int		f;
	t_trio	*trio;

	i = 0;
	f = 0;
	nb = format_string(number);
	size = ft_strlen(nb) / 3;
	while (i < size)
	{
		trio = trio_to_struct(nb);
		ft_display_hundred_units(trio->hundred_units, dict, &f);
		ft_display_hundred(trio->hundred, dict, &f);
		ft_display_dozen(trio->dozen, dict, &f);
		ft_display_unit(trio->unit, dict, &f);
		if (i != size - 1 && ft_is_good(trio) == 1)
			ft_display_zero(size - 1 - i, dict);
		free_trio(trio);
		i++;
		nb += 3;
	}
}

// ADDING ZEROS (why though?)
char	*format_string(char *str)
{
	int	zeroes_to_add;
	char	*formatted_string;
	int	i;

	i = 0;
	// What zeores to add?
	zeroes_to_add = (3 - ft_strlen(str) % 3) % 3;
	formatted_string = malloc(ft_strlen(str) + 1 + zeroes_to_add);
	while (zeroes_to_add--)
		formatted_string[i++] = '0';
	formatted_string[i] = '\0';
	return (ft_strcat(formatted_string, str));
}

// IS FT GOOD? (I don't know what this does exactly)
int		ft_is_good(t_trio *trio)
{
	if (trio->hundred_units == 0 && trio->unit == 0 && trio->dozen == 0)
		return (0);
	return (1);
}
 

/*
// MAIN FUNCTION
int main(void)
{
	t_dict	*test;
	test = ft_dict_setup("numbers.dict");
	convert_to_text("9", test);
	//printf("value: %s | wrt: %s", (test[30]).value, (test[30]).wrt);
}
*/
char	*ft_number_is_valid(char *str)
{
	int negative;
	char *input;

	negative = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str == '0' && *(str + 1) != '\0')
		str++;
	input = str;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	if (negative == -1)
		return (0);
	return (input);
}

int input_manip(char *vinput, t_dict *dict)
{
	int	zero;

	if (vinput == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	/*
	else if (dict == 0 || ft_strlen(vinput) > ft_maxdict(vinput))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	*/
	else
	{
		if (*vinput == '0')
		{
			zero = 0;
			ft_display_unit(vinput, dict, &zero);
		}
		else
			convert_to_text(vinput, dict);
		write(1, "\n", 1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char *vinput;

	vinput = 0;
	if (argc > 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
	{
		vinput = ft_number_is_valid(argv[1]);
	}
	input_manip(vinput, ft_dict_setup("numbers.dict"));
}

