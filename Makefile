##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

SRC = main.c\
	  fctools.c\
	  play_mode.c\

OBJ = $(SRC:.c=.o)

NAME = prout

FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -o

all: $(NAME)
$(NAME):
	gcc $(FLAGS) $(NAME) $(SRC) -g3

clean: $(shell rm -f $(OBJ))

fclean: clean
	rm -f $(NAME)

re: fclean all
