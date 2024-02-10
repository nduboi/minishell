##
## EPITECH PROJECT, 2024
## makefile
## File description:
## Makefile
##

.DEFAULT_GOAL := all
.PHONY: clean ALL fclean re

SRC	=	src/main.c	\
		src/minishell1/get_input_user.c	\
		src/minishell1/fill_struct.c	\
		src/minishell1/check_command.c	\
		src/minishell1/get_pwd.c 	\
		src/minishell1/my_str_to_word_array.c	\
		src/minishell1/start_comands.c	\
		src/minishell1/start_comands_no_interactive.c	\
		src/minishell1/non_interactive.c	\

NAME	= mysh

LIB = libext.a

OBJ = $(SRC:.c=.o)

INCLUDES = -I ./includes -I ./Library/includes/ -L./ -lext

CFLAGS += -Wall -Wextra -Werror $(INCLUDES)

all: $(LIB) $(NAME)

$(LIB):
	make -C Library

$(NAME): $(LIB) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

re: fclean $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C Library

fclean: clean
	rm -f $(NAME)
	make fclean -C Library
