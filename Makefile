##
## EPITECH PROJECT, 2024
## makefile
## File description:
## Makefile
##

.DEFAULT_GOAL := all
.PHONY: clean ALL fclean

SRC	=	src/main.c	\
		src/minishell1/get_input_user.c	\
		src/minishell1/fill_struct.c	\
		src/minishell1/check_command.c	\
		src/minishell1/get_pwd.c 	\

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

clean:
	rm -f $(OBJ)
	make clean -C Library

fclean: clean
	rm -f $(NAME)
	make fclean -C Library
