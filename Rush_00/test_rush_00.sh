# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_rush_00.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 17:07:11 by ide-dieg          #+#    #+#              #
#    Updated: 2025/02/23 21:34:32 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'
CYAN='\033[0;36m'
BLOD='\033[1m'

# Variables
TESTS_DIR="$(dirname "$0")/tests"

# Function_tests

test_rush_00()
{
	output1=$(./rush0"$3".out "$1" "$2")
	output2=$($TESTS_DIR/rush0"$3".test "$1" "$2")

	printf "x=%-4s y=%-4s: " "$1" "$2"
	if [ "$output1" = "$output2" ]; then
		echo -e "${GREEN}[ok]${NC}"
	else 
		echo -e "${RED}[ko]${NC}"
		echo "Output of rush:"
		echo "$output1"
		echo "Output of test:"
		echo "$output2"
	fi
}

tests_rush()
{
	echo -e "${CYAN}${BLOD}Testing rush0$1${NC}"
	if [ ! -f "./rush0$1.out" ]; then
		echo -e "${RED}Error: ./rush0$1.out is not compiled${NC}"
		return
	fi
	test_rush_00 1 1 "$1"
	test_rush_00 5 3 "$1"
	test_rush_00 1 5 "$1"
	test_rush_00 5 1 "$1"
	test_rush_00 4 4 "$1"
	test_rush_00 0 0 "$1"
	test_rush_00 0 1 "$1"
	test_rush_00 1 0 "$1"
	test_rush_00 1 2 "$1"
	test_rush_00 2 1 "$1"
	test_rush_00 2 2 "$1"
	test_rush_00 2 3 "$1"
	test_rush_00 3 2 "$1"
	test_rush_00 3 3 "$1"
	test_rush_00 0 4 "$1"
	test_rush_00 4 0 "$1"
	test_rush_00 100 100 "$1"
	test_rush_00 1000 1000 "$1"
	test_rush_00 -1 -1 "$1"
	test_rush_00 1 -1 "$1"
	test_rush_00 -1 1 "$1"
}

test_rush()
{
	tests_rush 0
	tests_rush 1
	tests_rush 2
	tests_rush 3
	tests_rush 4
}

mandatory_rush()
{
	read -p "Group leader login is required: " user_input
	while [ -z "$user_input" ]; do
		read -p "Group leader login is required: " user_input
	done
	echo "You entered: $user_input"
	echo -n "The mandatory rush number is: "
	$TESTS_DIR/calculate_rush_number.test "$user_input"
}

make -C "$(dirname "$0")" > /dev/null
mandatory_rush
test_rush