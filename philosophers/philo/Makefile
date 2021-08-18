NAME =		philo
OBJS_DIR =	objs
SRCS_DIR =	srcs

SRCS =		main.c init.c action.c utils.c init2.c routine.c

OBJS =		$(SRCS:.c=.o)

SRCS_FULL =	$(addprefix srcs/, $(SRCS))
OBJS_FULL =	$(addprefix objs/, $(OBJS))

CC =		gcc
CFLAGS =	-pthread -Wall -Werror -Wextra -g -c

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo Created: Object directory

$(NAME): $(OBJS_FULL)
	@$(CC) -pthread $(OBJS_FULL) -o $(NAME)
	@echo "\\n\033[32;1m PHILO HAS BEEN GENERATED \033[0m \\n"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) $< -o $@
	@echo "Created: $@"

clean:
	@rm -rf $(OBJS_FULL) $(OBJS_DIR)
	@echo "\033[34;1m CLEANED OBJECT FILES \033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[34;1m CLEANED PHILO \033[0m"

re: fclean all

.PHONY: all clean fclean re
