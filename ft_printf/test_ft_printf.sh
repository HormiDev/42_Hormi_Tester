# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_ft_printf.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 21:11:19 by ide-dieg          #+#    #+#              #
#    Updated: 2025/10/29 21:18:53 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

# Variables
TESTS_DIR="$(dirname "$0")/tests"

# tests
test_simple()
{
	if [ -f "$TESTS_DIR/test_simple.test" ]; then
		$TESTS_DIR/test_simple.test "$@"
	else
		echo -e "${RED}simple test is not compiled${NC}"
	fi
}

