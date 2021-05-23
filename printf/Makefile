CC = gcc
NAME = libftprintf.a
CFLAG = -Wall -Werror -Wextra -c

SRCS =	srcs/c_control.c \
		srcs/d_control.c \
		srcs/flags_print.c \
		srcs/ft_printf.c \
		srcs/misc.c \
		srcs/p_control.c \
		srcs/s_control.c \
		srcs/triage.c \
		srcs/u_control.c \
		srcs/x_control.c \

OBJS =	c_control.o \
		d_control.o \
		flags_print.o \
		ft_printf.o \
		misc.o \
		p_control.o \
		s_control.o \
		triage.o \
		u_control.o \
		x_control.o \

LIB_PATH = ./libft
INCLUDES = ./includes

all: $(NAME)

$(NAME):
	make re -C $(LIB_PATH)
	$(CC) $(CFLAG) $(SRCS) -I$(INCLUDES)
	ar rc $(NAME) $(OBJS) $(LIB_PATH)/*.o
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)
	make clean -C $(LIB_PATH)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
