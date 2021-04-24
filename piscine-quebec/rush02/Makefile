SRCS	= $(wildcard ./srcs/*.c)
OBJS	= ${SRCS:.c=.o}
INCL	= includes
NAME	= rush-02
GCC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${GCC} -I${INCL} ${CFLAGS} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS}
			${GCC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
