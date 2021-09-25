#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_board {
	int	width;
	int	height;
	char bg_char;
	char *matrix;
} t_board;

typedef struct s_rect {
	char type;
	float x;
	float y;
	float width;
	float height;
	char rect_char;
} t_rect;

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	get_board(FILE *file, t_board *board)
{
	int ret;
	int	i;

	ret = fscanf(file, "%d %d %c\n", &board->width, &board->height, &board->bg_char);
	if (ret != 3)
		return (1);
	if (board->width <= 0 || board->width > 300 || board->height <= 0 || board->height > 300)
		return (1);
	board->matrix = malloc(board->width * board->height);
	i = 0;
	while (i < board->width * board->height)
	{
		board->matrix[i] = board->bg_char;
		i++;
	}
	return (0);
}

int	is_in_board(t_board *board, t_rect *rect, int x, int y)
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

void	draw_rect(t_board *board, t_rect *rect)
{
	int	is_in;
	int	i;
	int j;

	i = 0;
	while (i < board->width)
	{
		j = 0;
		while (j < board->height)
		{
			is_in = is_in_board(board, rect, i, j);
			if (is_in == 2 || (is_in == 1 && rect->type == 'R'))
			{
				board->matrix[(j * board->width) + i] = rect->rect_char;
			}
			j++;
		}
		i++;
	}
}

void draw_board(t_board *board)
{
	int	i;
	int j;

	i = 0;
	while (i < board->height)
	{
		j = 0;
		while (j < board->width)
		{
			write(1, &board->matrix[(i * board->width) + j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	rect_control(FILE *file, t_board *board, t_rect *rect)
{
	int	ret;

	ret = fscanf(file, "%c %f %f %f %f %c\n", &rect->type, &rect->x, &rect->y, &rect->width, &rect->height, &rect->rect_char);
	while (ret == 6)
	{
		if (rect->width <= 0 || rect->height <= 0 || (rect->type != 'r' && rect->type != 'R'))
			return (1);
		draw_rect(board, rect);
		ret = fscanf(file, "%c %f %f %f %f %c\n", &rect->type, &rect->x, &rect->y, &rect->width, &rect->height, &rect->rect_char);
	}
	if (ret == -1)
	{
		draw_board(board);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	FILE *file;
	t_rect	rect;
	t_board	board;

	if (argc != 2)
	{
		ft_putstr("Error: argument\n");
		return (1);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		ft_putstr("Error: Operation file corrupted\n");
		return (1);
	}
	if (get_board(file, &board) == 1)
	{
		ft_putstr("Error: Operation file corrupted\n");
		return (1);
	}
	if (rect_control(file, &board, &rect) == 1)
	{
		ft_putstr("Error: Operation file corrupted\n");
		return (1);
	}
	free(board.matrix);
	return (0);
}