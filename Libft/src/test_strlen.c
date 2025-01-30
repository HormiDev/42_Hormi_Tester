/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 01:14:44 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/01/30 02:06:42 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	normal_test(int d, int i, int e)
{
	int original_strlen;
	int libft_strlen;
	int ok = 0;
	int ko = 0;
	//char	ci= 1;

	if (d && i && e)
		printf("%s[Detail test]%s\n", COLOR_BOLD, COLOR_RESET);

	if ((libft_strlen = ft_strlen("Hola Mundo!")) == (original_strlen = strlen("Hola Mundo!")))
		ok++;
	else
		ko++;
	if (ft_strlen("") == strlen(""))
		ok++;
	else
		ko++;
	if (ft_strlen("Este tester es la ostia!") == strlen("Este tester es la ostia!"))
		ok++;
	else
		ko++;
	if (ft_strlen("Hola\0Mundo!") == strlen("Hola\0Mundo!"))
		ok++;
	else
		ko++;
	
	
	
	if (ko > 0)
	{
		printf("%s[ko]%s (%d/4)\n", COLOR_RED, COLOR_RESET, (ok));
		return (ok);
	}
	else
	{
		printf("%s[ok]%s (%d/4)\n", COLOR_GREEN, COLOR_RESET, (ok));
		return (ok);
	}
}

int main(int argc, char **argv)
{
	int	result;
	int i = 1;

	printf("%s%s%-16s%s ", COLOR_BOLD, COLOR_CYAN, "ft_strlen:", COLOR_RESET);
	result = normal_test(0, 0, 0);
	if (argc > 1)
	{
		while (i < argc)
		{
			if ((!strcmp(argv[i], "-d") || !strcmp(argv[i], "--detail")) && result < 512)
				normal_test(1, 0, 0);
			if ((!strcmp(argv[i], "-i") || !strcmp(argv[i], "--irregular")) && result < 512)
				normal_test(0, 1, 0);
			if ((!strcmp(argv[i], "-e") || !strcmp(argv[i], "--error")) && result < 512)
				normal_test(0, 0, 1);
			i++;
		}
	}
	return (0);
}