# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_cpp01_04.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 21:12:42 by ide-dieg          #+#    #+#              #
#    Updated: 2026/01/18 21:19:49 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

# Variables
TESTS_DIR="$(dirname "$0")"

echo -e "${GREEN}Running tests for cpp01_04...${NC}"

first_bin()
{
	for f in *; do
		if [ -f "$f" ] && [ -x "$f" ]; then
		printf '%s\n' "$f"
		return 0
		fi
	done
	echo -e "${RED}Binary not detected${NC}"
	return 1
}

test()
{
	echo -e "${GREEN}Test 1: Basic Functionality${NC}"
	./"$bin" > "$TESTS_DIR/files/file_out.tmp" 2>/dev/null
	exit_code=$?
	
	cat "$TESTS_DIR/files/file_out.tmp"

	rm -fr "$TESTS_DIR/files/file_out.tmp"
}


bin=$(first_bin) || exit 1
echo -e "${GREEN}Binary detected: $bin${NC}"

test

echo -e "${GREEN}Tests completed for cpp01_04.${NC}"