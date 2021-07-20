NAME =			pipex

SRC_DIR =		srcs
OBJ_DIR =		objs

SRCS =			pipex.c utils.c
OBJS =			$(SRCS:.c=.o)

SRCS_PATH =		$(addprefix $(SRC_DIR)/, $(SRCS))
OBJS_PATH =		$(addprefix $(OBJ_DIR)/, $(OBJS))

CC =			gcc
CFLAGS =		-Wall -Werror -Wextra -g

$(NAME): $(OBJ_DIR) $(OBJS_PATH)
	@make re --no-print-directory -C ./libft
	@$(CC) $(OBJS_PATH) -Llibft -lft -o $(NAME)
	@echo "\\n\033[32;1m PIPEX HAS BEEN GENERATED \033[0m \\n"
	
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Created: Object directory"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Created: $@\033[1A\033[M"

all: $(NAME)

clean:
	@make clean --no-print-directory -C ./libft
	@rm -rf $(OBJS_PATH) $(OBJ_DIR)
	@echo "\033[34;1m CLEANED OBJECT FILES \033[0m"

fclean: clean
	@make fclean --no-print-directory -C ./libft
	@rm -f $(NAME)
	@echo "\033[34;1m CLEANED PIPEX \033[0m"

re: fclean all

.PHONY: all clean fclean re
