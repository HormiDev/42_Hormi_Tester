/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:35:18 by fatigarc          #+#    #+#             */
/*   Updated: 2025/02/23 02:04:27 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
void	rush(int x, int y);

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("\033[0;31mSe requiere dos argumentos X e Y\033[0m\n");
		return (1);
	}
	rush (atoi(argv[1]), atoi(argv[2]));
	return (0);
}
