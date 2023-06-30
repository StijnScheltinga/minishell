SOURCES		:=	main.c token.c token_utils.c
BUILD		:=	build
VPATH		:=	src/ src/input src/token
OBJECTS		:=	$(addprefix $(BUILD)/, $(SOURCES:.c=.o))
NAME		:=	minishell
FLAGS		:=	
CC			:=	gcc
HEADER		:=	inc/main.h libft/libft.h inc/token.h
LIBFT		:=	libft/libft.a
LIB_DIR		:=	libft
LIBS		:=	-lreadline

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	@printf "Compiling $(NAME)\n"
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(LIBFT) $(LIBS)

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

TEST_SRC 		:= tests/unit_tests.c src/token/token.c src/token/token_utils.c
TEST_OBJECTS	:= unit_tests.o token.o token_utils.o

test: $(BUILD) $(LIBFT) $(HEADER)
	$(CC) -g $(FLAGS) -c $(TEST_SRC)
	$(CC) $(FLAGS) -o test $(TEST_OBJECTS) $(LIBFT) $(LIBS)
	rm -rf $(TEST_OBJECTS);

test_clean: fclean
	rm -rf $(TEST_OBJECTS) test;

re: fclean all

.PHONY: all test clean fclean re test_clean