SRCS	= srcs/ft_display_file.c
OBJS	= ${SRCS:.c=.o}
NAME	= ft_display_file
GCC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}	

${NAME}:	${OBJS}
			${GCC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
