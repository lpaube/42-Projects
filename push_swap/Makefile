NAME = push_swap
SRCS = srcs/check_error.c \
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

INCLUDES = ./includes
LIBFT = ./libft
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I $(INCLUDES) -L $(LIBFT) -lft
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make re -C ./libft
	$(CC) $< -o $@

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $<

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
