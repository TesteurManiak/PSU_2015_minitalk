##
## Makefile for Makefile in /home/roux_l/rendu/PSU_2015_minitalk
## 
## Made by Guillaume Roux
## Login   <roux_l@epitech.net>
## 
## Started on  Mon Feb  1 14:02:47 2016 Guillaume Roux
## Last update Wed Feb  3 09:43:15 2016 Guillaume Roux
##

NAME		= ./server/server

NAME2		= ./client/client

SRC		= ./server/server.c \
	  	  ./server/my_put_nbr2.c

SRC2		= ./client/client.c \
		  ./client/my_getnbr.c

OBJ		= $(SRC:.c=.o)

OBJ2		= $(SRC2:.c=.o)

all:		$(NAME) $(NAME2)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

$(NAME2):	$(OBJ2)
		gcc -o $(NAME2) $(OBJ2)

clean:
		rm -f $(OBJ) $(OBJ2)

fclean:		clean
		rm -f $(NAME) $(NAME2)

re:		fclean all

.PHONY:		all clean fclean re
