# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 03:19:24 by ide-dieg          #+#    #+#              #
#    Updated: 2025/01/28 16:58:44 by ide-dieg         ###   ########.fr        #
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
	@$(CC) $(CFLAGS) $< $(LIBFT) -o $@
	@if [ -f $@ ]; then \
		echo "${GREEN}Compiled $@${NC}"; \
	else \
		echo "${RED}Failed to compile $@${NC}"; \
	fi

all: $(OBJ) clean_test $(TEST)
	@echo "All tests compiled"

clean_obj:
	@rm -f $(OBJ)
	@echo "${RED}All objects cleaned${NC}"

clean_test:
	@rm -f $(TEST)
	@echo "${RED}All tests cleaned${NC}"

clean: clean_obj clean_test

