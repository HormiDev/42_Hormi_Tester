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

echo -e "${CYAN}${BOLD}Instalador de Hormi_Tester${NC}"

# Verifica si el repo ya esta instalado
if [ -d "$INSTALL_DIR" ]; then
	echo -e "${RED}Hormi_Tester ya está instalado en ${INSTALL_DIR}.${NC}"
	echo -e "${CYAN}¿Deseas reinstalar Hormi_Tester?${NC}"
	select yn in "Sí" "No"; do
		case $yn in
			Sí ) echo -e "${CYAN}Eliminando el directorio ${INSTALL_DIR}...${NC}"; rm -rf "$INSTALL_DIR"; break;;
			No ) echo -e "${GREEN}Instalación cancelada.${NC}"; exit;;
		esac
	done
fi

# Clonar el repositorio
echo -e "${CYAN}Clonando el repositorio ${REPO_URL} en ${INSTALL_DIR}...${NC}"
git clone "$REPO_URL" "$INSTALL_DIR" > /dev/null 2>&1 || { echo -e "${RED}Error al clonar el repositorio.${NC}"; exit 1; }
echo -e "${GREEN}Repositorio clonado.${NC}"


# Verificar si las dependencias ya están instaladas
if ! dpkg -s build-essential >/dev/null 2>&1; then
	echo "Instalando dependencias..."
	sudo apt-get install -y build-essential
else
	echo "Las dependencias ya están instaladas."
fi

# crear alias
echo -e "${CYAN}Creando alias...${NC}"
if grep -q "alias hormi_tester=" ~/.bashrc || grep -q "alias hormi_tester=" ~/.zshrc; then
	echo -e "${GREEN}El alias hormi_tester ya existe. Eliminando...${NC}"
	sed -i '/alias hormi_tester=/d' ~/.bashrc
	sed -i '/alias hormi_tester=/d' ~/.zshrc
else
	echo -e "${CYAN}Creando alias hormi_tester...${NC}"
fi

if grep -q "alias hormi=" ~/.bashrc || grep -q "alias hormi=" ~/.zshrc; then
	sed -i '/alias hormi=/d' ~/.bashrc
	sed -i '/alias hormi=/d' ~/.zshrc
fi
echo "alias hormi_tester='${INSTALL_DIR}/Hormi_Tester.sh'" >> ~/.bashrc
echo "alias hormi_tester='${INSTALL_DIR}/Hormi_Tester.sh'" >> ~/.zshrc
echo "alias hormi'=${INSTALL_DIR}/Hormi_Tester.sh'" >> ~/.bashrc
echo "alias hormi'=${INSTALL_DIR}/Hormi_Tester.sh'" >> ~/.zshrc
echo -e "${GREEN}Alias ${BOLD}hormi_tester${NC}${GREEN} creado.${NC}"
echo -e "${GREEN}Alias ${BOLD}hormi${NC}${GREEN} creado.${NC}" 
echo -e "${CYAN}Recargando el shell...${NC}"
source ~/.zshrc > /dev/null 2>&1
source ~/.bashrc > /dev/null 2>&1
echo -e "${GREEN}Alias creado.${NC}"

# Mensaje de finalización
echo -e "${GREEN}${BOLD}Hormi_Tester se ha instalado correctamente.${NC}"