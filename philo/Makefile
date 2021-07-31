NAME =		philo
OBJS_DIR =	objs
SRCS_DIR =	srcs

SRCS =		main.c \

OBJS =		$(SRCS:.c=.o)

SRCS_FULL =	$(addprefix srcs/, $(SRCS))
OBJS_FULL =	$(addprefix objs/, $(OBJS))

CC =		gcc
CFLAGS =	-pthread -g -c#-Wall -Werror -Wextra -c -pthread -g

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo Created: Object directory

$(NAME): $(OBJS_FULL)
	@$(CC) $(OBJS_FULL) -o $(NAME)
	@echo "\\n\033[32;1m PHILO HAS BEEN GENERATED \033[0m \\n"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "Created: $@"
	@$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -rf $(OBJS_FULL) $(OBJS_DIR)
	@echo "\033[34;1m CLEANED OBJECT FILES \033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[34;1m CLEANED FDF \033[0m"

re: fclean all

.PHONY: all clean fclean re
