# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 19:48:52 by ide-dieg          #+#    #+#              #
#    Updated: 2025/03/03 20:05:41 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush_01

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = 	main.c \
		check_arguments.c \
		ft_strlen.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
