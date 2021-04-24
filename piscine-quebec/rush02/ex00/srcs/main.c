#include "rush.h"

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
	(void) dict;
	//int	zero;

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
	*/
	return (0);
}

int	main(int argc, char **argv)
{
	char *vinput;

	vinput = 0;
	if (argc >= 3)
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
	input_manip(vinput, create_dict("numbers.dict"));
}

