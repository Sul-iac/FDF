# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbarron <qbarron@student.42perpignan.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 15:17:50 by qbarron           #+#    #+#              #
#    Updated: 2024/02/17 15:17:50 by qbarron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
FLAGS = -Wall -Wextra -g
RM = rm -f
FRAMEDIR = ./mlx
FRAMEWORK = -Lmlx -lmlx -Imlx -lXext -lX11 -lm -lz
SRC = main.c rotations.c

OBJ = $(SRC:.c=.o)

.c.o: 
	$(CC) $(FLAGS) -Imlx -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(FRAMEWORK) -o $(NAME)

all:
	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all