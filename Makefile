##
## EPITECH PROJECT, 2024
## makefile
## File description:
## Makefile
##

.DEFAULT_GOAL := all
.PHONY: clean ALL fclean re unit_tests tests_run

SRC	=	src/minishell1/get_input_user.c	\
		src/minishell1/fill_struct.c	\
		src/minishell1/check_command.c	\
		src/minishell1/get_pwd.c 	\
		src/minishell1/my_str_to_word_array.c	\
		src/minishell1/start_comands.c	\
		src/minishell1/start_comands_no_interactive.c	\
		src/minishell1/non_interactive.c	\

FILE_MAIN =	src/main.c	\

FILE_TESTS = tests/test_my_project.c	\

FILE_MAIN_TESTS = src/test.c	\

NAME	= mysh

LIB = libext.a

OBJ_FILE_TESTS = $(FILE_TESTS:.c=.o)

OBJ_FILE_MAIN = $(FILE_MAIN:.c=.o)

OBJ_FILE_MAIN_TESTS = $(FILE_MAIN_TESTS:.c=.o)

OBJ = $(SRC:.c=.o)

INCLUDES = -I ./includes -I ./Library/includes/ -L./ -lext

CFLAGS += -Wall -Wextra -Werror $(INCLUDES)

all: $(LIB) $(NAME)

$(LIB):
	make -C Library

$(NAME): $(LIB) $(OBJ) $(OBJ_FILE_MAIN)
	gcc -o $(NAME) $(OBJ) $(OBJ_FILE_MAIN) $(CFLAGS)

re: fclean $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_FILE_MAIN)
	rm -f $(OBJ_FILE_TESTS)
	rm -f *.gcno
	rm -f *.gcda
	make clean -C Library

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests
	make fclean -C Library

tests: $(LIB) $(OBJ) $(OBJ_FILE_MAIN_TESTS)
	gcc -o tests_file $(OBJ) $(OBJ_FILE_MAIN_TESTS) $(CFLAGS)
	./tests_file
	@rm -f tests_file
	@rm -f ./src/test.o

unit_tests: fclean $(LIB)
	gcc -o unit_tests $(SRC) $(FILE_TESTS) $(CFLAGS) --coverage -lcriterion

tests_run : unit_tests
	./unit_tests
	gcovr --exclude tests/
