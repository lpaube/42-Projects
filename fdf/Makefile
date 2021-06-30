NAME =		fdf

SRCS =		fdf.c \

OBJS =		$(SRCS:.c=.o)

SRC_DIR =	srcs/
OBJ_DIR =	obj/
INC_DIR =	includes/
LIBFT =		libft/


linux: 
	make re -C ./libft
	gcc -Wall -Wextra -Werror -g srcs/*.c -Imlx_linux -Lmlx_linux -Llibft -lft -lmlx -lX11 -lm -lz -lXext

test:
	gcc -Wall -Wextra -Werror -g mlx_tests/*.c -Imlx_linux -Lmlx_linux -Llibft -lft -lmlx -lX11 -lm -lz -lXext

mac:
	make re -C ./libft
	gcc -Wall -Wextra -Werror -g srcs/*.c -Imlx_mac -Lmlx_mac -lmlx -Llibft -lft -framework OpenGL -framework AppKit
