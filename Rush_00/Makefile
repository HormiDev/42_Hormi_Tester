# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 00:40:25 by ide-dieg          #+#    #+#              #
#    Updated: 2025/02/23 01:03:58 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME_RUSH_CALCULATOR = calculate_rush_number

src_calculator = rush_calculator.c

all: build_rush_calculator

build_rush_calculator:
	$(CC) $(CFLAGS) -o $(NAME_RUSH_CALCULATOR) $(src_calculator)

clean:
	rm -f $(NAME_RUSH_CALCULATOR)