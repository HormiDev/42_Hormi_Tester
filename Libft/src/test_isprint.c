/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 03:09:37 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/01/30 01:11:03 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	normal_test(void)
{
	int i = 0;
	int original_isprint;
	int libft_isprint;
	int ok = 0;
	int iregular_ok = 0;
	int ko = 0;
	
	while (i < 256)
	{
		original_isprint = isprint(i);
		libft_isprint = ft_isprint(i);
		if (original_isprint == libft_isprint)
			ok++;
		else if ((original_isprint && libft_isprint) || (!original_isprint && !libft_isprint))
			iregular_ok++;
		else
			ko++;
		i++;
	}
	if (ko > 0)
		printf("%s[ko]%s (%d/512)\n", COLOR_RED, COLOR_RESET, (ok * 2 + iregular_ok));
	else if (iregular_ok > 0)
		printf("%s[ok]%s (%d/512)\n", COLOR_YELLOW, COLOR_RESET, (ok * 2 + iregular_ok));
	else
		printf("%s[ok]%s (%d/512)\n", COLOR_GREEN, COLOR_RESET, (ok * 2 + iregular_ok));
	return (ko * 2 + iregular_ok);
}

static void	detail_test(void)
{
	int i = 0;
	int original_isprint;
	int libft_isprint;
	
	while (i < 256)
	{
		original_isprint = isprint(i);
		libft_isprint = ft_isprint(i);
		if (isprint(i))
		{
			if (original_isprint == libft_isprint)
				printf("char: (%c)%s[ok]%s\n", i, COLOR_GREEN, COLOR_RESET);
			else if ((original_isprint && libft_isprint) || (!original_isprint && !libft_isprint))
				printf("char: (%c)%s[ok]%s[isprint: %d][ft_isprint: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_isprint, libft_isprint);
			else
				printf("char: (%c)%s[ko]%s[isprint: %d][ft_isprint: %d]\n", i, COLOR_RED, COLOR_RESET, original_isprint, libft_isprint);
		}
		else
		{
			if (original_isprint == libft_isprint)
				printf("char: (%d)%s[ok]%s\n", i, COLOR_GREEN, COLOR_RESET);
			else if ((original_isprint && libft_isprint) || (!original_isprint && !libft_isprint))
				printf("char: (%d)%s[ok]%s[isprint: %d][ft_isprint: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_isprint, libft_isprint);
			else
				printf("char: (%d)%s[ko]%s[isprint: %d][ft_isprint: %d]\n", i, COLOR_RED, COLOR_RESET, original_isprint, libft_isprint);
		}
		i++;
	}
}

static void test_irregular_cases(void)
{
	int i = 0;
	int original_isprint;
	int libft_isprint;
	
	while (i < 256)
	{
		original_isprint = isprint(i);
		libft_isprint = ft_isprint(i);
		if (isprint(i))
		{
			if (!(original_isprint == libft_isprint) && ((original_isprint && libft_isprint) || (!original_isprint && !libft_isprint)))
				printf("char: (%c)%s[ok]%s[isprint: %d][ft_isprint: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_isprint, libft_isprint);
		}
		else
		{
			if (!(original_isprint == libft_isprint) && ((original_isprint && libft_isprint) || (!original_isprint && !libft_isprint)))
				printf("char: (%d)%s[ok]%s[isprint: %d][ft_isprint: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_isprint, libft_isprint);
		}
		i++;
	}
}

static void test_error_cases(void)
{
	int i = 0;
	int original_isprint;
	int libft_isprint;
	
	while (i < 256)
	{
		original_isprint = isprint(i);
		libft_isprint = ft_isprint(i);
		if (isprint(i))
		{
			if ((!original_isprint && libft_isprint) || (original_isprint && !libft_isprint))
				printf("char: (%c)%s[ko]%s[isprint: %d][ft_isprint: %d]\n", i, COLOR_RED, COLOR_RESET, original_isprint, libft_isprint);
		}
		else
		{
			if ((!original_isprint && libft_isprint) || (original_isprint && !libft_isprint))
				printf("char: (%d)%s[ko]%s[isprint: %d][ft_isprint: %d]\n", i, COLOR_RED, COLOR_RESET, original_isprint, libft_isprint);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int	result;
	int i = 1;

	printf("%s%s%-16s%s ", COLOR_BOLD, COLOR_CYAN, "ft_isprint:", COLOR_RESET);
	result = normal_test();
	if (argc > 1)
	{
		while (i < argc)
		{
			if ((!strcmp(argv[i], "-d") || !strcmp(argv[i], "--detail")) && result < 512)
				detail_test();
			if ((!strcmp(argv[i], "-i") || !strcmp(argv[i], "--irregular")) && result < 512)
				test_irregular_cases();
			if ((!strcmp(argv[i], "-e") || !strcmp(argv[i], "--error")) && result < 512)
				test_error_cases();
			i++;
		}
	}
	return (0);
}