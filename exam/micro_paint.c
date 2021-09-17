#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_bg
{
	int		width;
	int		height;
	char	bg_char;
	char	*matrix;
} t_bg;

typedef struct	s_rect
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	rect_char;
}	t_rect;

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

int	get_bg(FILE *file, t_bg *bg)
{
	int	i;

	if (fscanf(file, "%d %d %c\n", &bg->width, &bg->height, &bg->bg_char) != 3)
		return (1);
	if ((bg->width <= 1 || bg->width > 300) || (bg->height <= 1 || bg->height > 300))
		return (1);
	bg->matrix = malloc(bg->width * bg->height);
	if (bg->matrix == NULL)
		return (1);
	i = 0;
	while (i < bg->width * bg->height)
		bg->matrix[i++] = bg->bg_char;
	return (0);
}

int	is_in_rect(float x, float y, t_rect *rect)
{
	if (x < rect->x || x > rect->x + rect->width)
		return (0);
	if (y < rect->y || y > rect->y + rect->height)
		return (0);
	if (x - rect->x < 1 || (rect->x + rect->width) - x < 1)
		return (2);
	if (y - rect->y < 1 || (rect->y + rect->height) - y < 1)
		return (2);
	return (1);
}

void	draw_pixel(t_bg *bg, t_rect *rect, int x, int y)
{
	int	is_in;

	is_in = is_in_rect((float)x, (float)y, rect);
	if (is_in == 2 || (is_in == 1 && rect->type == 'R'))
		bg->matrix[x + (y * bg->width)] = rect->rect_char;
	return ;
}

int	draw_control(t_bg *bg, t_rect *rect)
{
	int	i;
	int	j;

	if (rect->x <= 0 || rect->y <= 0 || (rect->type != 'r' && rect->type != 'R'))
		return (1);
	i = 0;
	while (i < bg->width)
	{
		j = 0;
		while (j < bg->height)
		{
			draw_pixel(bg, rect, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	exec_rect(FILE *file)
{
	t_bg	bg;
	t_rect		rect;

	if (get_bg(file, &bg))
		return (1);
	while (fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.width, &rect.height, &rect.rect_char) == 6)
	{
		if (draw_control(&bg, &rect))
			return (1);
	}
	free(bg.matrix);
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
		if ((file = fopen(argv[1], "r")) == NULL)
		{
			ft_putstr("Error: Operation file corrupted\n");
			return (1);
		}
		if (exec_rect(file) == 1)
		{
			ft_putstr("Error: Operation file corrupted\n");
			return (1);
		}
	}
	return (0);
}