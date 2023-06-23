SOURCES		=	main.c token.c
VPATH		=	src/ src/input src/token
BUILD		=	build
OBJECTS		=	$(addprefix $(BUILD)/, $(SOURCES:.c=.o))
NAME		=	minishell
FLAGS		=	-Wall -Werror -Wextra
CC			=	gcc
HEADER		=	inc/main.h libft/libft.h
LIBFT		=	libft/libft.a
LIB_DIR		=	libft
LIBS		=	-lreadline

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	@printf "Compiling $(NAME)\n"
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(PTHREAD) $(LIBFT) $(LIBS)

$(BUILD)/%.o: %.c $(HEADER) | $(BUILD)
	@printf "Compiling $<\n"
	$(CC) -g $(FLAGS) -c $< -o $@

$(BUILD):
	@mkdir -p $(BUILD)

$(LIBFT):
	make -C $(LIB_DIR)

clean:
	rm -rf $(OBJECTS) $(BUILD)
	$(MAKE) -C $(LIB_DIR) clean
	@printf "Cleaned ✅\n"

fclean:
	rm -rf $(OBJECTS) $(NAME) $(BUILD)
	$(MAKE) -C $(LIB_DIR) fclean
	@printf "Fcleaned ✅\n"


re: fclean all