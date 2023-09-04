SOURCES		:=	main.c token.c token_utils.c \
				token_list.c cmd_table.c \
				parser_utils.c io_redirection.c cd.c echo.c \
				env.c exit.c export.c \
				pwd.c unset.c builtin.c \
				execute.c execve.c \
				grammar.c grammar_error.c history.c \
				env_init.c env_utils.c redirect.c \
				create_token.c expansions.c execve_error.c \
				signals_init.c export_error.c quotes.c \
				delimiter.c signals_exec.c cleanup.c
BUILD		:=	build
VPATH		:=	src/ src/input src/token src/parser src/builtins src/execute src/error src/env src/expander src/signals
OBJECTS		:=	$(addprefix $(BUILD)/, $(SOURCES:.c=.o))
NAME		:=	minishell
FLAGS		:=	-fsanitize=address -I$(shell brew --prefix readline)/include
CC			:=	gcc 
HEADER		:=	inc/main.h libft/libft.h inc/token.h inc/parser.h inc/builtin.h inc/execute.h inc/execve.h inc/redirect.h inc/env_init.h inc/env_utils.h inc/expansions.h inc/signals.h inc/delimiter.h
LIBFT		:=	libft/libft.a
LIB_DIR		:=	libft
LIBS		:=	-lreadline -L$(shell brew --prefix readline)/lib

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	@printf "Compiling $(NAME)\n"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(LIBFT) $(LIBS)

$(BUILD)/%.o: %.c $(HEADER) | $(BUILD)
	@printf "Compiling $<\n"
	@$(CC) -g $(FLAGS) -c $< -o $@

$(BUILD):
	@mkdir -p $(BUILD)

$(LIBFT):
	make -C $(LIB_DIR)

clean:
	@rm -rf $(OBJECTS) $(BUILD)
	$(MAKE) -C $(LIB_DIR) clean
	@printf "Cleaned ✅\n"

fclean:
	@rm -rf $(OBJECTS) $(NAME) $(BUILD) test
	$(MAKE) -C $(LIB_DIR) fclean
	@printf "Fcleaned ✅\n"

re: fclean all

.PHONY: all test clean fclean re test_clean