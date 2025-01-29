# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    uninstall.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 03:24:59 by ide-dieg          #+#    #+#              #
#    Updated: 2025/01/29 03:28:01 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
INSTALL_DIR="$HOME/42_Hormi_Tester"

echo "\033[0;31mUninstalling Hormi_Tester...\033[0m"
rm -rf "$INSTALL_DIR"
sed -i '/alias hormi_tester=/d' ~/.bashrc
sed -i '/alias hormi_tester=/d' ~/.zshrc
sed -i '/alias hormi=/d' ~/.bashrc
sed -i '/alias hormi=/d' ~/.zshrc
echo "\033[0;32mHormi_Tester has been uninstalled.\033[0m"