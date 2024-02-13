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
		src/env/str_to_word_array.c	\
		src/env/my_strcpy.c	\
		src/minishell1/my_str_to_word_array_pwd.c	\
		src/minishell1/start_comands.c	\
		src/minishell1/non_interactive.c	\
		src/cd/main_cd.c	\
		src/env/main_env.c	\
		src/exit/main_exit.c	\
		src/unsetenv/main_unsetenv.c	\
		src/env/get_line_env.c	\
		src/env/get_env.c	\
		src/env/print_env.c	\
		src/setenv/main_setenv.c	\
		src/env/fill_env.c	\
		src/unsetenv/delete_node.c	\
		src/minishell1/my_linked_list_to_table.c	\

FILE_MAIN =	src/main.c	\

FILE_TESTS = tests/test_my_project.c	\

FILE_MAIN_TESTS = src/test.c	\

NAME	= mysh

LIB = libext.a

OBJ_FILE_TESTS = $(FILE_TESTS:.c=.o)

OBJ_FILE_MAIN = $(FILE_MAIN:.c=.o)

OBJ_FILE_MAIN_TESTS = $(FILE_MAIN_TESTS:.c=.o)

OBJ = $(SRC:.c=.o)

INCLUDES = -I ./includes -I ./library/includes/ -L./ -lext

CFLAGS += -Wall -Wextra -Werror $(INCLUDES) -g

all: $(LIB) $(NAME)

$(LIB):
	make -C library

$(NAME): $(LIB) $(OBJ) $(OBJ_FILE_MAIN)
	gcc -o $(NAME) $(OBJ) $(OBJ_FILE_MAIN) $(CFLAGS)
	cp $(NAME) tester/$(NAME)

re: fclean $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_FILE_MAIN)
	rm -f $(OBJ_FILE_TESTS)
	rm -f *.gcno
	rm -f *.gcda
	make clean -C library

fclean: clean
	rm -f $(NAME)
	rm -f tester/$(NAME)
	rm -f unit_tests
	make fclean -C library

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
