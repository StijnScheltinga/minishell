SOURCES		:=	main.c token.c token_utils.c token_list.c parser.c cmd_table.c
BUILD		:=	build
VPATH		:=	src/ src/input src/token src/parser
OBJECTS		:=	$(addprefix $(BUILD)/, $(SOURCES:.c=.o))
NAME		:=	minishell
FLAGS		:=	
CC			:=	gcc
HEADER		:=	inc/main.h libft/libft.h inc/token.h inc/parser.h
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
	rm -rf $(OBJECTS) $(NAME) $(BUILD) test
	$(MAKE) -C $(LIB_DIR) fclean
	@printf "Fcleaned ✅\n"

TEST_SRC 		:= tests/unit_tests.c tests/lexer_unit_tests.c tests/parser_unit_tests.c src/token/token.c src/token/token_utils.c src/token/token_list.c \
				   src/parser/parser.c src/parser/cmd_table.c
TEST_OBJECTS	:= unit_tests.o lexer_unit_tests.o parser_unit_tests.o token.o token_utils.o token_list.o parser.o cmd_table.o

test: $(BUILD) $(LIBFT) $(HEADER)
	$(CC) -g $(FLAGS) -c $(TEST_SRC)
	$(CC) $(FLAGS) -o test $(TEST_OBJECTS) $(LIBFT) $(LIBS)
	rm -rf $(TEST_OBJECTS);

test_clean: fclean
	rm -rf $(TEST_OBJECTS) test;

re: fclean all

.PHONY: all test clean fclean re test_clean