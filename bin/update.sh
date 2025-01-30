# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    update.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 21:06:24 by ide-dieg          #+#    #+#              #
#    Updated: 2025/01/30 21:35:22 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
INSTALL_DIR="$HOME/42_Hormi_Tester"

# Colors
YELLOW='\033[0;33m'
GREEN='\033[0;32m'
NC='\033[0m'

update_hormi_tester() {
	echo -e "${YELLOW}Updating Hormi_Tester...${NC}"
	if [ ! -d "$INSTALL_DIR" ]; then
		echo "Hormi_Tester repository not found."
		read -p "Do you want to install it? (y/n): " choice
		if [ "$choice" = "y" ]; then
			bash -c "$(curl -fsSL https://raw.github.com/HormiDev/42_Hormi_Tester/master/bin/install.sh)"
		else
			echo "Installation cancelled."
			exit 1
		fi
	fi
	(cd "$INSTALL_DIR" && git pull)
	echo -e "${GREEN}Hormi_Tester has been updated.${NC}"
}

update_hormi_tester