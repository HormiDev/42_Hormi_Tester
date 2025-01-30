/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 00:34:36 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/01/30 01:13:42 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	normal_test(void)
{
	int i = 0;
	int original_isalpha;
	int libft_isalpha;
	int ok = 0;
	int iregular_ok = 0;
	int ko = 0;
	
	while (i < 256)
	{
		original_isalpha = isalpha(i);
		libft_isalpha = ft_isalpha(i);
		if (original_isalpha == libft_isalpha)
			ok++;
		else if ((original_isalpha && libft_isalpha) || (!original_isalpha && !libft_isalpha))
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
	int original_isalpha;
	int libft_isalpha;
	
	while (i < 256)
	{
		original_isalpha = isalpha(i);
		libft_isalpha = ft_isalpha(i);
		if (isprint(i))
		{
			if (original_isalpha == libft_isalpha)
				printf("char: (%c)%s[ok]%s\n", i, COLOR_GREEN, COLOR_RESET);
			else if ((original_isalpha && libft_isalpha) || (!original_isalpha && !libft_isalpha))
				printf("char: (%c)%s[ok]%s[isalpha: %d][ft_isalpha: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_isalpha, libft_isalpha);
			else
				printf("char: (%c)%s[ko]%s[isalpha: %d][ft_isalpha: %d]\n", i, COLOR_RED, COLOR_RESET, original_isalpha, libft_isalpha);
		}
		else
		{
			if (original_isalpha == libft_isalpha)
				printf("char: (%d)%s[ok]%s\n", i, COLOR_GREEN, COLOR_RESET);
			else if ((original_isalpha && libft_isalpha) || (!original_isalpha && !libft_isalpha))
				printf("char: (%d)%s[ok]%s[isalpha: %d][ft_isalpha: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_isalpha, libft_isalpha);
			else
				printf("char: (%d)%s[ko]%s[isalpha: %d][ft_isalpha: %d]\n", i, COLOR_RED, COLOR_RESET, original_isalpha, libft_isalpha);
		}
		i++;
	}
}

static void test_irregular_cases(void)
{
	int i = 0;
	int original_isalpha;
	int libft_isalpha;
	
	while (i < 256)
	{
		original_isalpha = isalpha(i);
		libft_isalpha = ft_isalpha(i);
		if (isprint(i))
		{
			if (!(original_isalpha == libft_isalpha) && ((original_isalpha && libft_isalpha) || (!original_isalpha && !libft_isalpha)))
				printf("char: (%c)%s[ok]%s[isalpha: %d][ft_isalpha: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_isalpha, libft_isalpha);
		}
		else
		{
			if (!(original_isalpha == libft_isalpha) && ((original_isalpha && libft_isalpha) || (!original_isalpha && !libft_isalpha)))
				printf("char: (%d)%s[ok]%s[isalpha: %d][ft_isalpha: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_isalpha, libft_isalpha);
		}
		i++;
	}
}

static void test_error_cases(void)
{
	int i = 0;
	int original_isalpha;
	int libft_isalpha;
	
	while (i < 256)
	{
		original_isalpha = isalpha(i);
		libft_isalpha = ft_isalpha(i);
		if (isprint(i))
		{
			if ((!original_isalpha && libft_isalpha) || (original_isalpha && !libft_isalpha))
				printf("char: (%c)%s[ko]%s[isalpha: %d][ft_isalpha: %d]\n", i, COLOR_RED, COLOR_RESET, original_isalpha, libft_isalpha);
		}
		else
		{
			if ((!original_isalpha && libft_isalpha) || (original_isalpha && !libft_isalpha))
				printf("char: (%d)%s[ko]%s[isalpha: %d][ft_isalpha: %d]\n", i, COLOR_RED, COLOR_RESET, original_isalpha, libft_isalpha);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int	result;
	int i = 1;

	printf("%s%s%-16s%s ", COLOR_BOLD, COLOR_CYAN, "ft_isalpha:", COLOR_RESET);
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