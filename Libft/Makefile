# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 03:19:24 by ide-dieg          #+#    #+#              #
#    Updated: 2025/05/20 02:43:20 by ide-dieg         ###   ########.fr        #
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
		test_strlen.c \
		test_strchr.c \
		test_strrchr.c \
		test_strncmp.c \
		test_bzero.c \
		test_memcpy.c \
		test_memchr.c \
		test_memcmp.c \
		test_memmove.c \
	#	test_strlcpy.c \

LIBFT = libft.a

LIBFT_DIR = $(PWD)

SRC_DIR = src

OBJ_DIR = obj

TEST_DIR = tests

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

TEST = $(addprefix $(TEST_DIR)/, $(SRC:.c=$(EXTENSION)))

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m
CIAN = \033[0;36m

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "${GREEN}Compiled $<${NC}"

$(TEST_DIR)/%$(EXTENSION): $(OBJ_DIR)/%.o
	@mkdir -p $(TEST_DIR)
	@if $(CC) $(CFLAGS) $< $(LIBFT_DIR)/$(LIBFT) -o $@; then \
		echo "${GREEN}Compiled $@${NC}"; \
	else \
		echo "${RED}Failed to compile $@${NC}"; \
	fi

all: $(OBJ) clean_test $(TEST)
	@echo $(LIBFT_DIR)
	@echo "All tests compiled"

clean_obj:
	@rm -f $(OBJ)
	@echo "${RED}All objects cleaned${NC}"

clean_test:
	@rm -f $(TEST)
	@echo "${RED}All tests cleaned${NC}"

clean: clean_obj clean_test

