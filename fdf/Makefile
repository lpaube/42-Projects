NAME =		fdf

SRCS =		fdf.c \

OBJS =		$(SRCS:.c=.o)

SRC_DIR =	srcs/
OBJ_DIR =	obj/
INC_DIR =	includes/
LIBFT =		libft/


$(NAME): $(OBJS)
	@make re

gcc fdf.c -L/usr/local/lib/ -lmlx -lX11 -lm -lz -lXext
