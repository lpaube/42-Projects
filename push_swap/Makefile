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

#OBJS = 	check_error.o \
		commands_rotate.o \
		commands_swap.o \
		initialize.o \
		partition_a.o \
		partition_a2.o \
		partition_b.o \
		partition_utils.o \
		push_swap.o \
		solve_short.o \
		sort_arr.o \
		utils.o \

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
	@make re -C ./libft
	$(CC) $(OBJ_PATH) -Llibft -lft -o $(NAME)
	@echo "\\n\033[32;1m PUSH_SWAP HAS BEEN GENERATED \033[0m \\n"

$(OBJS): $(SRC_PATH)
	$(CC) $(CFLAGS) srcs/$(@:.o=.c) -o obj/$@

clean:
	@make clean -C ./libft
	@rm -rf $(OBJ_PATH) $(OBJ_DIR)
	@echo "\\n\033[32;1m CLEANED OBJECT FILES \033[0m \\n"

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)
	@echo "\\n\033[32;1m CLEANED PUSH_SWAP \033[0m \\n"

re: fclean all

.PHONY: all clean fclean re
