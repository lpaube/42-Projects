NAME =		fdf
OBJS_PATH =	objs
SRCS_PATH =	srcs
LIBFT =		libft

SRCS =		fdf.c \
			coloring.c \
			draw.c \
			init.c \
			key_control.c \
			mouse_controls.c \
			set_map.c \
			set_point.c \
			update_point.c \
			utils.c \

CC =		gcc
CFLAGS =	-Wall -Werror -Wextra -c -g
INCLUDES =	-Imlx_mac -Iincludes
LIBS =		-Lmlx_mac -lmlx -Llibft -lft -framework OpenGL -framework AppKit
OBJS =		$(SRCS:.c=.o)

SRCS_FULL =	$(addprefix srcs/, $(SRCS))
OBJS_FULL =	$(addprefix objs/, $(OBJS))

all: $(OBJS_PATH) $(NAME)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)
	@echo Created: Object directory

$(NAME): $(OBJS_FULL)
	@make re --no-print-directory -C ./libft
	@$(CC) $(OBJS_FULL) $(LIBS) -o $(NAME)
	@echo "\\n\033[32;1m FDF HAS BEEN GENERATED \033[0m \\n"

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@echo "Created: $@\033[1A\033[M"
	@$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	@make clean --no-print-directory -C ./libft
	@rm -rf $(OBJS_FULL) $(OBJS_PATH) 
	@echo "\033[34;1m CLEANED OBJECT FILES \033[0m"

fclean: clean
	@make fclean --no-print-directory -C ./libft
	@rm -f $(NAME)
	@echo "\033[34;1m CLEANED FDF \033[0m"

re: fclean all

.PHONY: all clean fclean re

#linux: 
#	make re -C ./libft
#	gcc -Wall -Wextra -Werror -g srcs/*.c -Imlx_linux -Lmlx_linux -Llibft -lft -lmlx -lX11 -lm -lz -lXext
#
#test-linux:
#	make re -C ./libft
#	gcc -Wall -Wextra -Werror -g mlx_tests/*.c -Imlx_linux -Lmlx_linux -Llibft -lft -lmlx -lX11 -lm -lz -lXext
#
#test-mac:
#	make re -C ./libft
#	gcc -Wall -Wextra -Werror -g mlx_tests/*.c -Imlx_mac -Lmlx_mac -lmlx -Llibft -lft -framework OpenGL -framework AppKit
#
#mac:
#	make re -C ./libft
#	gcc -Wall -Wextra -Werror -g srcs/*.c libft/*.c -Imlx_mac -Lmlx_mac -lmlx -Ilibft -framework OpenGL -framework AppKit
