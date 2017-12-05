##
## EPITECH PROJECT, 2017
## makefile
## File description:
## compiler
##

SRC	=   	main.c			\
		src/l_flag.c		\
		src/linked_list.c	\
		src/display.c		\
		src/my_swap_functions.c \
		lib/my_strcmp.c		\
		lib/my_put_nbr.c	\
		lib/my_strlen.c		\
		lib/my_putstr.c		\
		lib/my_strcpy.c		\
		lib/my_strcat.c		\

NAME	=	my_ls

CFLAGS	=	-Wall -Wextra

LFLAGS	=	-I./include


$(NAME):
		gcc $(SRC) -o $(NAME) $(CFLAGS) $(LFLAGS)


all:            $(NAME)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY: all clean fclean re
