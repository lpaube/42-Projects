#include <stdio.h>

typedef struct s_background
{
	int		width;
	int		height;
	char	bg_char;
	char	*matrix;
} t_background;


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	get_background(FILE *file, t_background *background)
{
	int	i;

	if (fscanf(file, "%d %d %c\n", &background->width, &background->height, &background->bg_char) != 3)
		return (1);
	if ((background->width <= 1 || background->width > 300) || (background->height <= 1 || background->height > 300))
		return (1);
	background->matrix = malloc(background->width * background->height);
	if (background->matrix == NULL)
		return (1);
	i = 0;
	while (i < background->width * background->height)
		background->matrix[i++] = background->bg_char;
	return (0);
}

int	exec_rect(FILE *file)
{
	t_background	background;

	if (get_background(file, &background))
		return (1);
	
}

int	main(int argc, char **argv)
{
	FILE	*file;

	if (argc != 2)
	{
		ft_putstr("Error: argument\n");
		return (1);
	}
	else
	{
		if (file = fopen(argv[1], "r") == NULL)
		{
			ft_putstr("Error: Operation file corrupted\n");
			return (1);
		}
		if (exec_rect(file)) == 1)
		{
			ft_putstr("Error: Operation file corrupted\n");
			return (1);
		}
	}
	return (0);
}