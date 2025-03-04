/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:55:49 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/03/03 20:04:48 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

static int check_arg(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9' || ft_strlen(arg) > 1)
			return (1);
		i++;
	}
	return (0);
}

int check_arguments(int argc, char **argv)
{
	int i;

	if (argc < 17 || (argc - 1) % 4 != 0)
		return (1);
	i = 1;
	while(i < argc)
	{
		if (check_arg(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
