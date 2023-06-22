SOURCES		=	input.c
VPATH		=	src/ src/input src/token
BUILD		=	build
OBJECTS		=	$(addprefix $(BUILD)/, $(SOURCES:.c=.o))
NAME		=	minishell
FLAGS		=	-Wall -Werror -Wextra
CC			=	gcc
HEADER		=	inc/main.h libft/libft.h
LIB			=	libft/libft.a
LIB_DIR		=	libft

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB)
	@printf "Compiling $(NAME)\n"
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(PTHREAD) $(LIB)

$(BUILD)/%.o: %.c $(HEADER) | $(BUILD)
	@printf "Compiling $<\n"
	$(CC) -g $(FLAGS) -c $< -o $@

$(BUILD):
	@mkdir -p $(BUILD)

$(LIB):
	@make -C $(LIB_DIR)

clean:
	@rm -rf $(OBJECTS) $(BUILD)
	@$(MAKE) -C $(LIB_DIR) clean
	@printf "Cleaned ✅\n"

fclean:
	@rm -rf $(OBJECTS) $(NAME) $(BUILD)
	@$(MAKE) -C $(LIB_DIR) fclean
	@printf "Fcleaned ✅\n"


re: fclean all