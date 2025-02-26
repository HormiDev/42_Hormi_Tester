/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rush_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:57:54 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/02/26 10:03:29 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/**
 * @brief Este programa calcula el número de rush obligatorio en funcion del
 * login del lider de grupo.
 * 
 * @argument "Login" del lider de grupo
 * @return int
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\033[0;31mThe login of the group leader is required as an argument\033[0m\n");
		return (1);
	}
	printf("\033[0;36mRush: 0%d\033[0m\n", (argv[1][0] - 'a' + 1) % 5);
	return (0);
}
