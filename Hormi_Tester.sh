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

print_header() {
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
	echo -e "${GREEN} _  _   __  ____  _  _  __ ${RED}    ____  ____  ____  ____  ____  ____  ${NC}"
	echo -e "${GREEN}/ )( \ /  \(  _ \( \/ )(  )${RED}   (_  _)(  __)/ ___)(_  _)(  __)(  _ \ ${NC}"
	echo -e "${GREEN}) __ ((  O ))   // \/ \ )( ${RED}     )(   ) _) \___ \  )(   ) _)  )   / ${NC}"
	echo -e "${GREEN}\_)(_/ \__/(__\_)\_)(_/(__)${RED}    (__) (____)(____/ (__) (____)(__\_) ${NC}"
}

execute_test() {
	ARGUMENTS_FOR_LIBFT=("libft" "ft_memset" "ft_bzero" "ft_memcpy" "ft_memccpy" "ft_memmove" "ft_memchr" "ft_memcmp" "ft_strlen" "ft_strdup" "ft_strcpy" "ft_strncpy" "ft_strcat" "ft_strncat" "ft_strlcat" "ft_strchr" "ft_strrchr" "ft_strstr" "ft_strnstr" "ft_strcmp" "ft_strncmp" "ft_atoi" "ft_isalpha" "ft_isdigit" "ft_isalnum" "ft_isascii" "ft_isprint" "ft_toupper" "ft_tolower" "ft_memalloc" "ft_memdel" "ft_strnew" "ft_strdel" "ft_strclr" "ft_striter" "ft_striteri" "ft_strmap" "ft_strmapi" "ft_strequ" "ft_strnequ" "ft_strsub" "ft_strjoin" "ft_strtrim" "ft_strsplit" "ft_itoa" "ft_putchar" "ft_putstr" "ft_putendl" "ft_putnbr" "ft_putchar_fd" "ft_putstr_fd" "ft_putendl_fd" "ft_putnbr_fd")
	local arg="$1"
	if [[ " ${ARGUMENTS_FOR_LIBFT[@],,} " =~ " ${arg,,} " ]]; then
		echo -e "${GREEN}Executing tests for ${arg}...${NC}"
		${TESTER_DIR}/Libft/test_libft.sh "$@"
	else
		echo -e "${RED}Invalid argument: ${arg}${NC}"
	fi
}

print_header
execute_test "$@"


