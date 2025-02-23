# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_rush_00.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 17:07:11 by ide-dieg          #+#    #+#              #
#    Updated: 2025/02/23 19:10:17 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

# Variables
TESTS_DIR="$(dirname "$0")/tests"

# Function_tests

test_rush_00()
{
	output1=$(./rush00.out "$1" "$2")
	output2=$($TESTS_DIR/rush00.test "$1" "$2")

	echo -n "Test rush00 $1 $2: "
	if [ "$output1" = "$output2" ]; then
		echo "${GREEN}[ok]${NC}"
	else 
		echo "${RED}[ko]${NC}"
		echo "Output of rush:"
		echo "$output1"
		echo "Output of test:"
		echo "$output2"
	fi
}

test_rush_01()
{
	output1=$(./rush01.out "$1" "$2")
	output2=$($TESTS_DIR/rush01.test "$1" "$2")

	echo -n "Test rush01 $1 $2: "
	if [ "$output1" = "$output2" ]; then
		echo "${GREEN}[ok]${NC}"
	else 
		echo "${RED}[ko]${NC}"
		echo "Output of rush:"
		echo "$output1"
		echo "Output of test:"
		echo "$output2"
	fi
}

test_rush_02()
{
	output1=$(./rush02.out "$1" "$2")
	output2=$($TESTS_DIR/rush02.test "$1" "$2")

	echo -n "Test rush02 $1 $2: "
	if [ "$output1" = "$output2" ]; then
		echo "${GREEN}[ok]${NC}"
	else 
		echo "${RED}[ko]${NC}"
		echo "Output of rush:"
		echo "$output1"
		echo "Output of test:"
		echo "$output2"
	fi
}

test_rush_03()
{
	output1=$(./rush03.out "$1" "$2")
	output2=$($TESTS_DIR/rush03.test "$1" "$2")

	echo -n "Test rush03 $1 $2: "
	if [ "$output1" = "$output2" ]; then
		echo "${GREEN}[ok]${NC}"
	else 
		echo "${RED}[ko]${NC}"
		echo "Output of rush:"
		echo "$output1"
		echo "Output of test:"
		echo "$output2"
	fi
}

test_rush_04()
{
	output1=$(./rush04.out "$1" "$2")
	output2=$($TESTS_DIR/rush04.test "$1" "$2")

	echo -n "Test rush04 $1 $2: "
	if [ "$output1" = "$output2" ]; then
		echo "${GREEN}[ok]${NC}"
	else 
		echo "${RED}[ko]${NC}"
		echo "Output of rush:"
		echo "$output1"
		echo "Output of test:"
		echo "$output2"
	fi
}

tests_rush()
{
	test_rush_0"$1" 1 1
	test_rush_0"$1" 5 3
	test_rush_0"$1" 1 5
	test_rush_0"$1" 5 1
	test_rush_0"$1" 4 4
	test_rush_0"$1" 0 0
	test_rush_0"$1" 0 1
	test_rush_0"$1" 1 0
	test_rush_0"$1" 1 2
	test_rush_0"$1" 2 1
	test_rush_0"$1" 2 2
	test_rush_0"$1" 2 3
	test_rush_0"$1" 3 2
	test_rush_0"$1" 3 3
}

test_rush()
{
	tests_rush 0
	tests_rush 1
	tests_rush 2
	tests_rush 3
	tests_rush 4
}

test_rush