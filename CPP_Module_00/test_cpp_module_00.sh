# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_cpp_module_00.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/23 00:01:17 by ide-dieg          #+#    #+#              #
#    Updated: 2026/01/28 13:45:56 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

# Variables
TESTS_DIR="$(dirname "$0")/tests"

AUTHORIZED_FILES=("ex00" "ex01" "ex02")

check_authorized_files()
{
    local authorized
    for file in *; do
        # Asegurarse de que el archivo/directorio existe (por si el directorio está vacío y * no expande)
        [ -e "$file" ] || continue

        authorized=false
        for pattern in "${AUTHORIZED_FILES[@]}"; do
            # Compara el archivo contra el patrón (globbing)
            # Nota: $pattern no debe estar entre comillas aquí para que el glob funcione
            if [[ "$file" == $pattern ]]; then
                authorized=true
                break
            fi
        done

        if [ "$authorized" = false ]; then
            if [ -d "$file" ]; then
                echo -e "${RED}Unauthorized directory detected: $file${NC}"
            else
                echo -e "${RED}Unauthorized file detected: $file${NC}"
            fi
        fi
    done
}

test_00()
{
	echo "$@"
	if [ -f "$TESTS_DIR/test_cpp00_00.sh" ]; then
		"$TESTS_DIR/test_cpp00_00.sh" "$@"
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
check_authorized_files
run_tests "$@"