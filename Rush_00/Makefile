# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 00:40:25 by ide-dieg          #+#    #+#              #
#    Updated: 2025/02/23 21:11:08 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

TEST_DIR = tests/

RUSH_DIR = $(PWD)/

SRC_CALCULATOR = calculate_rush_number.c
SRCS_RUSH_00_TEST = ex00/rush00.c ex00/ft_putchar.c main.c
SRCS_RUSH_01_TEST = ex00/rush01.c ex00/ft_putchar.c main.c
SRCS_RUSH_02_TEST = ex00/rush02.c ex00/ft_putchar.c main.c
SRCS_RUSH_03_TEST = ex00/rush03.c ex00/ft_putchar.c main.c
SRCS_RUSH_04_TEST = ex00/rush04.c ex00/ft_putchar.c main.c

SRC_RUSH_00 = $(RUSH_DIR)ex00/rush00.c $(RUSH_DIR)ex00/ft_putchar.c main.c
SRC_RUSH_01 = $(RUSH_DIR)ex00/rush01.c $(RUSH_DIR)ex00/ft_putchar.c main.c
SRC_RUSH_02 = $(RUSH_DIR)ex00/rush02.c $(RUSH_DIR)ex00/ft_putchar.c main.c
SRC_RUSH_03 = $(RUSH_DIR)ex00/rush03.c $(RUSH_DIR)ex00/ft_putchar.c main.c
SRC_RUSH_04 = $(RUSH_DIR)ex00/rush04.c $(RUSH_DIR)ex00/ft_putchar.c main.c

all: build_rush_calculator build_tests build_all_rush

build_rush_calculator:
	@if [ ! -d $(TEST_DIR) ]; then \
		mkdir -p $(TEST_DIR); \
	fi
	@if [ ! -f $(TEST_DIR)calculate_rush_number.test ]; then \
		$(CC) $(CFLAGS) -o $(TEST_DIR)calculate_rush_number.test $(SRC_CALCULATOR); \
	fi

build_tests:
	@if [ ! -d $(TEST_DIR) ]; then \
		mkdir -p $(TEST_DIR); \
	fi
	@if [ ! -f $(TEST_DIR)rush00.test ]; then \
		$(CC) $(CFLAGS) -o $(TEST_DIR)rush00.test $(SRCS_RUSH_00_TEST); \
	fi
	@if [ ! -f $(TEST_DIR)rush01.test ]; then \
		$(CC) $(CFLAGS) -o $(TEST_DIR)rush01.test $(SRCS_RUSH_01_TEST); \
	fi
	@if [ ! -f $(TEST_DIR)rush02.test ]; then \
		$(CC) $(CFLAGS) -o $(TEST_DIR)rush02.test $(SRCS_RUSH_02_TEST); \
	fi
	@if [ ! -f $(TEST_DIR)rush03.test ]; then \
		$(CC) $(CFLAGS) -o $(TEST_DIR)rush03.test $(SRCS_RUSH_03_TEST); \
	fi
	@if [ ! -f $(TEST_DIR)rush04.test ]; then \
		$(CC) $(CFLAGS) -o $(TEST_DIR)rush04.test $(SRCS_RUSH_04_TEST); \
	fi

rush_00:
	rm -f $(RUSH_DIR)rush00.out
	$(CC) $(CFLAGS) $(SRC_RUSH_00) -o $(RUSH_DIR)rush00.out

rush_01:
	rm -f $(RUSH_DIR)rush01.out
	$(CC) $(CFLAGS) $(SRC_RUSH_01) -o $(RUSH_DIR)rush01.out

rush_02:
	rm -f $(RUSH_DIR)rush02.out
	$(CC) $(CFLAGS) $(SRC_RUSH_02) -o $(RUSH_DIR)rush02.out

rush_03:
	rm -f $(RUSH_DIR)rush03.out
	$(CC) $(CFLAGS) $(SRC_RUSH_03) -o $(RUSH_DIR)rush03.out

rush_04:
	rm -f $(RUSH_DIR)rush04.out
	$(CC) $(CFLAGS) $(SRC_RUSH_04) -o $(RUSH_DIR)rush04.out

build_all_rush: rush_00 rush_01 rush_02 rush_03 rush_04

fclean: clean
	rm -fr $(TEST_DIR)

clean:
	rm -f $(RUSH_DIR)rush00.out
	rm -f $(RUSH_DIR)rush01.out
	rm -f $(RUSH_DIR)rush02.out
	rm -f $(RUSH_DIR)rush03.out
	rm -f $(RUSH_DIR)rush04.out

re: fclean all