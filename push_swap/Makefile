NAME =		push_swap
OBJ_DIR =	obj/
SRC_DIR =	srcs/
LIBFT =		libft/
INCLUDES =	includes/

SRCS = 	check_error.c \
		commands_rotate.c \
		commands_swap.c \
		initialize.c \
		partition_a.c \
		partition_a2.c \
		partition_b.c \
		partition_utils.c \
		push_swap.c \
		solve_short.c \
		sort_arr.c \
		utils.c \

CC =		gcc
CFLAGS =	-Wall -Werror -Wextra -I$(INCLUDES) -c
OBJS =		$(SRCS:.c=.o)

SRC_PATH =	$(addprefix srcs/, $(SRCS))
OBJ_PATH =	$(addprefix obj/, $(OBJS))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo Created: Object directory

$(NAME): $(OBJS)
	@make re --no-print-directory -C ./libft
	@$(CC) $(OBJ_PATH) -Llibft -lft -o $(NAME)
	@echo "\\n\033[32;1m PUSH_SWAP HAS BEEN GENERATED \033[0m \\n"

$(OBJS): $(SRC_PATH)
	@echo "Created: obj/$@\033[1A\033[M"
	@$(CC) $(CFLAGS) srcs/$(@:.o=.c) -o obj/$@

clean:
	@make clean --no-print-directory -C ./libft
	@rm -rf $(OBJ_PATH) $(OBJ_DIR)
	@echo "\033[34;1m CLEANED OBJECT FILES \033[0m"

fclean: clean
	@make fclean --no-print-directory -C ./libft
	@rm -f $(NAME)
	@echo "\033[34;1m CLEANED PUSH_SWAP \033[0m"

re: fclean all

.PHONY: all clean fclean re
