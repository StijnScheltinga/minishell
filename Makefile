SOURCES	=		main.c
SRC_DIR	=		src
BUILD	=		build
OBJECTS	=		$(addprefix $(BUILD)/, $(SOURCES:.c=.o))
NAME	=		minishell	
FLAGS	=		-Wall -Werror -Wextra
CC		=		gcc
INCLUDE	=		-I inc/main.h
HEADER	=		inc/main.h

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(PTHREAD)

$(BUILD)/%.o: $(SRC_DIR)/%.c $(HEADER) | $(BUILD)
	gcc -g $(FLAGS) $(INCLUDE) -c $< -o $@

$(BUILD):
	@mkdir -p $(BUILD)

clean:
	rm -rf $(OBJECTS) $(BUILD)

fclean:
	rm -rf $(OBJECTS) $(NAME) $(BUILD)

re: fclean all