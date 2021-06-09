LIBFT = ./libft/libft.a

NAME = libft.a

SRCS =	srcs/ft_printf.c \
		srcs/c_control.c \
		srcs/d_control.c \
		srcs/flags_print.c \
		srcs/misc.c \
		srcs/p_control.c \
		srcs/s_control.c \
		srcs/triage.c \
		srcs/u_control.c \
		srcs/x_control.c \

SURPL_O = ft_printf.o \
		c_control.o \
		d_control.o \
		flags_print.o \
		misc.o \
		p_control.o \
		s_control.o \
		triage.o \
		u_control.o \
		x_control.o \

CC = gcc

CFLAGS = -Wall -Werror -Wextra -c

INCLUDES = -I./include

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make re -C ./libft
	cp libft/libft.a ./$(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	make clean -C ./libft
	/bin/rm -f $(SURPL_O)
	/bin/rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
