# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    uninstall.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 03:24:59 by ide-dieg          #+#    #+#              #
#    Updated: 2025/01/30 21:35:03 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
INSTALL_DIR="$HOME/42_Hormi_Tester"

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

uninstall() {
	echo -e "${RED}Uninstalling Hormi_Tester...${NC}"
	rm -rf "$INSTALL_DIR"
	sed -i '/alias hormi_tester=/d' ~/.bashrc
	sed -i '/alias hormi_tester=/d' ~/.zshrc
	sed -i '/alias hormi=/d' ~/.bashrc
	sed -i '/alias hormi=/d' ~/.zshrc
	echo -e "${GREEN}Hormi_Tester has been uninstalled.${NC}"
}

uninstall