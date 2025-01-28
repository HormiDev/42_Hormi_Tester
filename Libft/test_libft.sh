# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_libft.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 17:28:13 by ide-dieg          #+#    #+#              #
#    Updated: 2025/01/28 18:44:40 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

# Variables
TESTS_DIR="tests"

# Function_tests
test_isalpha()
{
	if [ -f "$TESTS_DIR/test_isalpha.test" ]; then
		./$TESTS_DIR/test_isalpha.test "$@"
	else
		echo -e "${RED}isalpha test is not compiled${NC}"
	fi
}

test_isdigit()
{
	if [ -f "$TESTS_DIR/test_isdigit.test" ]; then
		./$TESTS_DIR/test_isdigit.test "$@"
	else
		echo -e "${RED}isdigit test is not compiled${NC}"
	fi
}

test_isalnum()
{
	if [ -f "$TESTS_DIR/test_isalnum.test" ]; then
		./$TESTS_DIR/test_isalnum.test "$@"
	else
		echo -e "${RED}isalnum test is not compiled${NC}"
	fi
}

test_isascii()
{
	if [ -f "$TESTS_DIR/test_isascii.test" ]; then
		./$TESTS_DIR/test_isascii.test "$@"
	else
		echo -e "${RED}isascii test is not compiled${NC}"
	fi
}

test_isprint()
{
	if [ -f "$TESTS_DIR/test_isprint.test" ]; then
		./$TESTS_DIR/test_isprint.test "$@"
	else
		echo -e "${RED}isprint test is not compiled${NC}"
	fi
}

test_toupper()
{
	if [ -f "$TESTS_DIR/test_toupper.test" ]; then
		./$TESTS_DIR/test_toupper.test "$@"
	else
		echo -e "${RED}toupper test is not compiled${NC}"
	fi
}

test_tolower()
{
	if [ -f "$TESTS_DIR/test_tolower.test" ]; then
		./$TESTS_DIR/test_tolower.test "$@"
	else
		echo -e "${RED}tolower test is not compiled${NC}"
	fi
}

run_tests()
{
	make > /dev/null
	if [ $? -ne 0 ]; then
		echo -e "${RED}Compilation failed${NC}"
		exit 1
	fi
	test_isalpha
	test_isdigit
	test_isalnum
	test_isascii
	test_isprint
	test_toupper
	test_tolower
}

run_tests