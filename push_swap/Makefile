NAME = push_swap

SRCS = 	srcs/check_error.c \
		srcs/commands_rotate.c \
		srcs/commands_swap.c \
		srcs/initialize.c \
		srcs/partition_a.c \
		srcs/partition_a2.c \
		srcs/partition_b.c \
		srcs/partition_utils.c \
		srcs/push_swap.c \
		srcs/solve_short.c \
		srcs/sort_arr.c \
		srcs/utils.c \

OBJS = 	check_error.o \
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

INCLUDES = ./includes
LIBFT = ./libft
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	make re -C ./libft
	$(CC) $(OBJS) -Llibft -lft -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
