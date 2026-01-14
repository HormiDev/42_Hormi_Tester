# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_cpp_module_01.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 20:58:05 by ide-dieg          #+#    #+#              #
#    Updated: 2026/01/13 21:46:19 by ide-dieg         ###   ########.fr        #
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
	if [ -f "$TESTS_DIR/test_cpp01_00.sh" ]; then
		"$TESTS_DIR/test_cpp01_00.sh"
	else
		echo -e "${RED}Not existing test for cpp01_00${NC}"
	fi
}

test_01()
{
	if [ -f "$TESTS_DIR/test_cpp01_01.sh" ]; then
		"$TESTS_DIR/test_cpp01_01.sh"
	else
		echo -e "${RED}Not existing test for cpp01_01${NC}"
	fi
}

test_02()
{
	if [ -f "$TESTS_DIR/test_cpp01_02.sh" ]; then
		"$TESTS_DIR/test_cpp01_02.sh"
	else
		echo -e "${RED}Not existing test for cpp01_02${NC}"
	fi
}

test_03()
{
	if [ -f "$TESTS_DIR/test_cpp01_03.sh" ]; then
		"$TESTS_DIR/test_cpp01_03.sh"
	else
		echo -e "${RED}Not existing test for cpp01_03${NC}"
	fi
}

test_04()
{
	if [ -f "$TESTS_DIR/test_cpp01_04.sh" ]; then
		"$TESTS_DIR/test_cpp01_04.sh"
	else
		echo -e "${RED}Not existing test for cpp01_04${NC}"
	fi
}

test_05()
{
	if [ -f "$TESTS_DIR/test_cpp01_05.sh" ]; then
		"$TESTS_DIR/test_cpp01_05.sh"
	else
		echo -e "${RED}Not existing test for cpp01_05${NC}"
	fi
}

run_tests()
{
	echo -e "${GREEN}Executing tests for CPP Module 01...${NC}"
	
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
	("03"|"3")
		shift
		test_03
		;;
	("04"|"4")
		shift
		test_04
		;;
	("05"|"5")
		shift
		test_05
		;;
	(*)
		test_00
		test_01
		test_02
		test_03
		test_04
		test_05
		;;
	esac
}

run_tests "$@"