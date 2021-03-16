##
## EPITECH PROJECT, 2020
## makefile
## File description:
## bsq
##

NAME	=	my_ls

SRC	=	my_ls.c	\
		find_mode.c 	\
		my_ls2.c 	\
		my_ls_t.c 	\
		orga.c 	\
		my_ls_next.c 	\
		my_ls_rr.c 	\

all :	$(NAME)

$(NAME):
	make -C ./lib/my
	gcc -o $(NAME) -g $(SRC) -L./lib/my -lmy

clean:
	make -C ./lib/my
	rm -f *~
	rm -f *#

fclean: clean
	make clean -C ./lib/my
	rm -f $(NAME)

re:	fclean all
	make fclean -C ./lib/my
