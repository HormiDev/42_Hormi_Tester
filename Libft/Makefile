# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 03:19:24 by ide-dieg          #+#    #+#              #
#    Updated: 2025/01/26 02:14:04 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

EXTENSION = .test

SRC =	test_isalpha.c \
		test_isdigit.c \
		test_isalnum.c \
		test_isascii.c \
		test_isprint.c \
		test_toupper.c \
		test_tolower.c \

LIBFT = libft.a

all: $(SRC:.c=$(EXTENSION)) exec

$(SRC:.c=$(EXTENSION)): %$(EXTENSION): %.c $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $< $(LIBFT)

clean:
	rm -f $(SRC:.c=$(EXTENSION))

fclean: clean

exec:
	for test in $(SRC:.c=$(EXTENSION)); do ./$$test; done