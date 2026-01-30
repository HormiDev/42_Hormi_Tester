# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_cpp00_00.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/23 00:03:13 by ide-dieg          #+#    #+#              #
#    Updated: 2026/01/29 21:06:25 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

AUTHORIZED_FILES=("Makefile" "megaphone.cpp")

#flags
DETAIL_FLAG=false
ERROR_FLAG=false
IRREGULAR_FLAG=false

# Variables
TESTS_DIR="$(dirname "$0")"
EX_DIR="ex00"

check_flags()
{
	for arg in "$@"; do
		case $arg in
			--detail | -d)
				DETAIL_FLAG=true
				;;
			--error | -e)
				ERROR_FLAG=true
				;;
			--irregular | -i)
				IRREGULAR_FLAG=true
				;;
			*)
				echo -e "${RED}Unknown flag: $arg${NC}"
				;;
		esac
	done
}

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

test()
{
	output=$(./"$bin" $1 2>/dev/null)
	exit_code=$?
	if [ $exit_code -ne 0 ]; then
		echo -e "${RED}Test failed: Program exited with code $exit_code${NC}"
		return
	fi
	if [ "$output" == "$2" ]; then
		echo -e -n "${GREEN}"[OK]"${NC}"
		if [ "$DETAIL_FLAG" = true ]; then
			echo -e "Test passed for input '$1': \nYour output:   '${GREEN}$output${NC}'\nTest expected: '$2''\n"
		fi
	else
		echo -e -n "${RED}"[KO]"${NC}"
		if [ "$DETAIL_FLAG" = true ] || [ "$ERROR_FLAG" = true ]; then
			echo -e "Test failed for input '$1': \nYour output:   '${RED}$output${NC}'\nTest expected: '$2''\n"
		fi
	fi
}
echo $@

check_flags

echo -e "Running tests for cpp00_00$..."

cd $EX_DIR || (echo -e "${RED}Directory $EX_DIR not found.${NC}"; exit 1)
check_authorized_files

make re >/dev/null 2>&1
bin=$(first_bin) || exit 1
echo -e "Binary detected:${GREEN} $bin${NC}"

test "hola" "HOLA"
test "Hello World" "HELLO WORLD"
test "42madrid" "42MADRID"
test "TeStInG 1 2 3" "TESTING 1 2 3"
test "12345" "12345"
test "mixed CASE 123 !" "MIXED CASE 123 !"
test "~0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdehghijklmnopqrstuvwxyzñÑçÇ" "~0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZÑÑÇÇ"
test "" "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
test "\"\"" "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
make fclean >/dev/null 2>&1

echo -e "\n${GREEN}Tests completed for cpp00_00.${NC}"

cd ..
