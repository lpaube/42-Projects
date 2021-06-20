NAME =		fdf

SRCS =		fdf.c \

OBJS =		$(SRCS:.c=.o)

SRC_DIR =	srcs/
OBJ_DIR =	obj/
INC_DIR =	includes/
LIBFT =		libft/


linux: 
	gcc -g srcs/*.c -Imlx_linux -Lmlx_linux -Llibft -lft -lmlx -lX11 -lm -lz -lXext

mac:
	gcc -g srcs/*.c -Imlx_mac -Lmlx_mac -lmlx -framework OpenGL -framework AppKit
