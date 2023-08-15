SOURCES		:=	main.c token.c token_utils.c \
				token_list.c parser.c cmd_table.c \
				parser_utils.c io_redirection.c cd.c echo.c \
				env.c exit.c export.c \
				pwd.c unset.c builtin.c \
				execute.c execve.c pipes.c \
				grammar.c grammar_error.c history.c \
				env_init.c env_utils.c redirect.c \
				create_token.c
BUILD		:=	build
VPATH		:=	src/ src/input src/token src/parser src/builtins src/execute src/error src/env
OBJECTS		:=	$(addprefix $(BUILD)/, $(SOURCES:.c=.o))
NAME		:=	minishell
FLAGS		:=	-fsanitize=address
CC			:=	gcc
HEADER		:=	inc/main.h libft/libft.h inc/token.h inc/parser.h inc/builtin.h inc/execute.h inc/execve.h inc/pipes.h inc/redirect.h inc/env_init.h inc/env_utils.h
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
				   src/parser/parser.c src/parser/cmd_table.c src/parser/parser_utils.c src/parser/grammar.c src/error/grammar_error.c src/parser/io_redirection.c \
				   src/token/create_token.c src/env/env_init.c src/env/env_utils.c
TEST_OBJECTS	:= unit_tests.o lexer_unit_tests.o parser_unit_tests.o token.o token_utils.o token_list.o parser.o cmd_table.o \
				   parser_utils.o grammar.o grammar_error.o io_redirection.o create_token.o env_init.o env_utils.o

test: $(BUILD) $(LIBFT) $(HEADER)
	$(CC) -g $(FLAGS) -c $(TEST_SRC)
	$(CC) $(FLAGS) -o test $(TEST_OBJECTS) $(LIBFT) $(LIBS)
	rm -rf $(TEST_OBJECTS);

test_clean: fclean
	rm -rf $(TEST_OBJECTS) test;

re: fclean all

.PHONY: all test clean fclean re test_clean