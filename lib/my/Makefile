##
## EPITECH PROJECT, 2020
## makefile
## File description:
## task01
##

SRC	=	my_printf.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_put_nbr.c	\
		check_type.c	\
		convert.c	\
		more_flag.c	\
		my_getnbr.c	\
		my_strlen.c	\
		space_or_zero.c	\
		more_put_nbr.c 	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

NAMECP	=	my.h


$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		mkdir -p  ../../include
		cp $(NAME) ../
		cp $(NAMECP) ../../include/

clean:
		rm $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean $(NAME)
