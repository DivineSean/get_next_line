NAME        = lib/libgnl.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INC_DIR     = include
SRC_DIR     = src
OBJ_DIR     = obj
LIB_DIR     = lib

SRCS        = get_next_line_bonus.c \
              get_next_line_utils_bonus.c

OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

GREEN       = \033[0;32m
YELLOW      = \033[0;33m
CYAN        = \033[0;36m
RESET       = \033[0m

all: $(NAME) program

$(NAME): $(OBJS) | $(LIB_DIR)
	@ar -cr $(NAME) $(OBJS)
	@echo "$(GREEN)libgnl.a built$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/get_next_line_bonus.h | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
	@echo "$(CYAN)compiled $<$(RESET)"

program: $(NAME)
	@$(CC) $(CFLAGS) -I $(INC_DIR) main.c -L $(LIB_DIR) -lgnl -o program
	@echo "$(GREEN)program built$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIB_DIR):
	@mkdir -p $(LIB_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)objects cleaned$(RESET)"

fclean: clean
	@rm -rf $(LIB_DIR) program
	@echo "$(YELLOW)library cleaned$(RESET)"

re: fclean all

.PHONY: all clean fclean re
