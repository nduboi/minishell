##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for bnavy
##

SRC =	src/my_array_len.c	\
		src/my_getnbr.c	\
		src/my_put_nbr.c	\
		src/my_putstr.c	\
		src/my_strcmp.c	\
		src/my_strdup.c	\
		src/my_strlen.c	\

OBJ = $(SRC:.c=.o)

NAME = ../libext.a

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
