NAME =		fdf

SRCS =		fdf.c \

OBJS =		$(SRCS:.c=.o)

SRC_DIR =	srcs/
OBJ_DIR =	obj/
INC_DIR =	includes/
LIBFT =		libft/


linux: 
	gcc srcs/fdf.c -L/usr/local/lib/ -Iincludes -lmlx -lX11 -lm -lz -lXext

mac:
	gcc srcs/fdf.c -Imlx_mac -Lmlx_mac -lmlx -framework OpenGL -framework AppKit
