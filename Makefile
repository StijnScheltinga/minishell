SOURCES		=	input.c
VPATH		=	src/ src/input src/token
BUILD		=	build
OBJECTS		=	$(addprefix $(BUILD)/, $(SOURCES:.c=.o))
NAME		=	minishell
FLAGS		=	-Wall -Werror -Wextra
CC			=	gcc
INCLUDE		=	-I inc/main.h
HEADER		=	inc/main.h

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(PTHREAD)

$(BUILD)/%.o: %.c $(HEADER) | $(BUILD)
	$(CC) -g $(FLAGS) $(INCLUDE) -c $< -o $@

$(BUILD):
	@mkdir -p $(BUILD)

clean:
	rm -rf $(OBJECTS) $(BUILD)

fclean:
	rm -rf $(OBJECTS) $(NAME) $(BUILD)

re: fclean all