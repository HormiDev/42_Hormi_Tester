#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Hormi_Tester.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 19:38:27 by ide-dieg          #+#    #+#              #
#    Updated: 2025/01/29 02:35:59 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TESTER_DIR="$(dirname "$0")"

ORANGE='\033[0;33m'
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'

print_hormidev_header() {
	echo -e "${RED}██╗██████╗ ███████╗    ██████╗ ██╗███████╗ ██████╗ ${BLUE}         ██╗  ██╗██████╗ "
	echo -e "${RED}██║██╔══██╗██╔════╝    ██╔══██╗██║██╔════╝██╔════╝ ${BLUE}         ██║  ██║╚════██╗"
	echo -e "${RED}██║██║  ██║█████╗█████╗██║  ██║██║█████╗  ██║  ███╗${BLUE}         ███████║ █████╔╝"
	echo -e "${RED}██║██║  ██║██╔══╝╚════╝██║  ██║██║██╔══╝  ██║   ██║${BLUE}         ╚════██║██╔═══╝ "
	echo -e "${RED}██║██████╔╝███████╗    ██████╔╝██║███████╗╚██████╔╝${BLUE}              ██║███████╗"
	echo -e "${RED}╚═╝╚═════╝ ╚══════╝    ╚═════╝ ╚═╝╚══════╝ ╚═════╝ ${BLUE}              ╚═╝╚══════╝"
	echo -e "${ORANGE}██╗  ██╗ ██████╗ ██████╗ ███╗   ███╗██╗██████╗ ███████╗██╗   ██╗${GREEN}       ██╗  "
	echo -e "${ORANGE}██║  ██║██╔═══██╗██╔══██╗████╗ ████║██║██╔══██╗██╔════╝██║   ██║${GREEN}   ██╗ ╚═██╗"
	echo -e "${ORANGE}███████║██║   ██║██████╔╝██╔████╔██║██║██║  ██║█████╗  ██║   ██║${GREEN}   ╚═╝   ██║"
	echo -e "${ORANGE}██╔══██║██║   ██║██╔══██╗██║╚██╔╝██║██║██║  ██║██╔══╝  ╚██╗ ██╔╝${GREEN}   ██╗   ██║"
	echo -e "${ORANGE}██║  ██║╚██████╔╝██║  ██║██║ ╚═╝ ██║██║██████╔╝███████╗ ╚████╔╝ ${GREEN}   ╚═╝ ██╔═╝"
	echo -e "${ORANGE}╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝╚═════╝ ╚══════╝  ╚═══╝  ${GREEN}       ╚═╝  ${NC}"
	print_header
}

print_header() {
	echo -e "${GREEN} _  _   __  ____  _  _  __ ${RED}    ____  ____  ____  ____  ____  ____  ${NC}"
	echo -e "${GREEN}/ )( \ /  \(  _ \( \/ )(  )${RED}   (_  _)(  __)/ ___)(_  _)(  __)(  _ \ ${NC}"
	echo -e "${GREEN}) __ ((  O ))   // \/ \ )( ${RED}     )(   ) _) \___ \  )(   ) _)  )   / ${NC}"
	echo -e "${GREEN}\_)(_/ \__/(__\_)\_)(_/(__)${RED}    (__) (____)(____/ (__) (____)(__\_) ${NC}"
}

execute_test() {
	ARGUMENTS_FOR_HELP=("-h" "--help" "help" "h" "?" "man")
	ARGUMENTS_FOR_LIBFT=("libft" "isalpha" "isdigit" "isalnum" "isascii" "isprint" "toupper" "tolower" "strlen" "memset" "bzero" "memcpy" "memccpy" "memmove" "memchr" "memcmp" "strlcpy" "strlcat" "strchr" "strrchr" "strncmp" "strnstr" "atoi" "calloc" "strdup")
	ARGUMENTS_FOR_RUSH00=("rush00" "rush0" "rush_00" "rush 00", "rush")
	local arg="$1"
	if [[ " ${ARGUMENTS_FOR_LIBFT[@],,} " =~ " ${arg,,} " ]]; then
		print_header
		echo -e "${GREEN}Executing tests for...${NC}"
		${TESTER_DIR}/Libft/test_libft.sh "$@"
	elif [[ " ${ARGUMENTS_FOR_HELP[@],,} " =~ " ${arg,,} " ]]; then
		print_hormidev_header
		cat ${TESTER_DIR}/man.txt
	elif [[ " ${ARGUMENTS_FOR_RUSH00[@],,} " =~ " ${arg,,} " ]]; then
		print_header
		echo -e "${GREEN}Executing tests for...${NC}"
		${TESTER_DIR}/Rush_00/test_rush_00.sh "$@"
	else
		print_hormidev_header
		echo -e "${RED}unrecognized project...${NC}"
		cat ${TESTER_DIR}/man.txt
	fi
}

execute_test "$@"


