# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_cpp_module_00.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/23 00:01:17 by ide-dieg          #+#    #+#              #
#    Updated: 2026/01/23 00:26:16 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

# Variables
TESTS_DIR="$(dirname "$0")/tests"

test_00()
{
	if [ -f "$TESTS_DIR/test_cpp00_00.sh" ]; then
		"$TESTS_DIR/test_cpp00_00.sh"
	else
		echo -e "${RED}Not existing test for cpp00_00${NC}"
	fi
}

test_01()
{
	if [ -f "$TESTS_DIR/test_cpp00_01.sh" ]; then
		"$TESTS_DIR/test_cpp00_01.sh"
	else
		echo -e "${RED}Not existing test for cpp00_01${NC}"
	fi
}

test_02()
{
	if [ -f "$TESTS_DIR/test_cpp00_02.sh" ]; then
		"$TESTS_DIR/test_cpp00_02.sh"
	else
		echo -e "${RED}Not existing test for cpp00_02${NC}"
	fi
}

run_tests()
{
	echo -e "${GREEN}CPP Module 00...${NC}"
	
	shift
	case "$1" in
	("00"|"0")
		shift
		test_00
		;;
	("01"|"1")
		shift
		test_01
		;;
	("02"|"2")
		shift
		test_02
		;;
	(*)
		test_00
		test_01
		test_02
		;;
	esac
}

run_tests "$@"