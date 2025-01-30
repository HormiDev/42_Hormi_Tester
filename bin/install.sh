#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    install.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 02:40:27 by ide-dieg          #+#    #+#              #
#    Updated: 2025/01/29 02:51:19 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ORANGE='\033[0;33m'
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
BOLD='\033[1m'

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

print_header

# Variables
REPO_URL="https://github.com/HormiDev/42_Hormi_Tester.git"
INSTALL_DIR="$HOME/42_Hormi_Tester"

echo -e "${CYAN}${BOLD}Hormi_Tester Installer${NC}"

# Check if the repo is already installed
if [ -d "$INSTALL_DIR" ]; then
	echo -e "${RED}Hormi_Tester is already installed in ${INSTALL_DIR}.${NC}"
	echo -e "${CYAN}Do you want to reinstall Hormi_Tester?${NC}"
	select yn in "Yes" "No"; do
		case $yn in
			Yes ) echo -e "${CYAN}Removing the directory ${INSTALL_DIR}...${NC}"; rm -rf "$INSTALL_DIR"; break;;
			No ) echo -e "${GREEN}Installation canceled.${NC}"; exit;;
		esac
	done
fi

# Clone the repository
echo -e "${CYAN}Cloning the repository ${REPO_URL} into ${INSTALL_DIR}...${NC}"
git clone "$REPO_URL" "$INSTALL_DIR" > /dev/null 2>&1 || { echo -e "${RED}Error cloning the repository.${NC}"; exit 1; }
echo -e "${GREEN}Repository cloned.${NC}"


# Check if dependencies are already installed
if ! dpkg -s build-essential >/dev/null 2>&1; then
	echo "Installing dependencies..."
	sudo apt-get install -y build-essential
else
	echo "Dependencies are already installed."
fi

# Create alias
echo -e "${CYAN}Creating alias...${NC}"
if grep -q "alias hormi_tester=" ~/.bashrc || grep -q "alias hormi_tester=" ~/.zshrc; then
	echo -e "${GREEN}The hormi_tester alias already exists. Removing...${NC}"
	sed -i '/alias hormi_tester=/d' ~/.bashrc
	sed -i '/alias hormi_tester=/d' ~/.zshrc
else
	echo -e "${CYAN}Creating hormi_tester alias...${NC}"
fi

if grep -q "alias hormi=" ~/.bashrc || grep -q "alias hormi=" ~/.zshrc; then
	sed -i '/alias hormi=/d' ~/.bashrc
	sed -i '/alias hormi=/d' ~/.zshrc
fi
echo "alias hormi_tester='${INSTALL_DIR}/Hormi_Tester.sh'" >> ~/.bashrc
echo "alias hormi_tester='${INSTALL_DIR}/Hormi_Tester.sh'" >> ~/.zshrc
echo "alias hormi'=${INSTALL_DIR}/Hormi_Tester.sh'" >> ~/.bashrc
echo "alias hormi'=${INSTALL_DIR}/Hormi_Tester.sh'" >> ~/.zshrc
echo -e "${GREEN}Alias ${BOLD}hormi_tester${NC}${GREEN} created.${NC}"
echo -e "${GREEN}Alias ${BOLD}hormi${NC}${GREEN} created.${NC}" 
echo -e "${CYAN}Reloading the shell...${NC}"
source ~/.zshrc > /dev/null 2>&1
source ~/.bashrc > /dev/null 2>&1
echo -e "${GREEN}Alias created.${NC}"

# Completion message
echo -e "${GREEN}${BOLD}Hormi_Tester has been successfully installed.${NC}"