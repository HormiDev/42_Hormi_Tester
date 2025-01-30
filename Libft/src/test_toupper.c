/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:40:19 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/01/30 01:08:19 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	normal_test(void)
{
	int i = 0;
	int original_toupper;
	int libft_toupper;
	int ok = 0;
	int iregular_ok = 0;
	int ko = 0;
	
	while (i < 256)
	{
		original_toupper = toupper(i);
		libft_toupper = ft_toupper(i);
		if (original_toupper == libft_toupper)
			ok++;
		else if ((original_toupper && libft_toupper) || (!original_toupper && !libft_toupper))
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
	int original_toupper;
	int libft_toupper;
	
	while (i < 256)
	{
		original_toupper = toupper(i);
		libft_toupper = ft_toupper(i);
		if (toupper(i))
		{
			if (original_toupper == libft_toupper)
				printf("char: (%c)%s[ok]%s\n", i, COLOR_GREEN, COLOR_RESET);
			else if ((original_toupper && libft_toupper) || (!original_toupper && !libft_toupper))
				printf("char: (%c)%s[ok]%s[toupper: %d][ft_toupper: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_toupper, libft_toupper);
			else
				printf("char: (%c)%s[ko]%s[toupper: %d][ft_toupper: %d]\n", i, COLOR_RED, COLOR_RESET, original_toupper, libft_toupper);
		}
		else
		{
			if (original_toupper == libft_toupper)
				printf("char: (%d)%s[ok]%s\n", i, COLOR_GREEN, COLOR_RESET);
			else if ((original_toupper && libft_toupper) || (!original_toupper && !libft_toupper))
				printf("char: (%d)%s[ok]%s[toupper: %d][ft_toupper: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_toupper, libft_toupper);
			else
				printf("char: (%d)%s[ko]%s[toupper: %d][ft_toupper: %d]\n", i, COLOR_RED, COLOR_RESET, original_toupper, libft_toupper);
		}
		i++;
	}
}

static void test_irregular_cases(void)
{
	int i = 0;
	int original_toupper;
	int libft_toupper;
	
	while (i < 256)
	{
		original_toupper = toupper(i);
		libft_toupper = ft_toupper(i);
		if (toupper(i))
		{
			if (!(original_toupper == libft_toupper) && ((original_toupper && libft_toupper) || (!original_toupper && !libft_toupper)))
				printf("char: (%c)%s[ok]%s[toupper: %d][ft_toupper: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_toupper, libft_toupper);
		}
		else
		{
			if (!(original_toupper == libft_toupper) && ((original_toupper && libft_toupper) || (!original_toupper && !libft_toupper)))
				printf("char: (%d)%s[ok]%s[toupper: %d][ft_toupper: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_toupper, libft_toupper);
		}
		i++;
	}
}

static void test_error_cases(void)
{
	int i = 0;
	int original_toupper;
	int libft_toupper;
	
	while (i < 256)
	{
		original_toupper = toupper(i);
		libft_toupper = ft_toupper(i);
		if (toupper(i))
		{
			if ((!original_toupper && libft_toupper) || (original_toupper && !libft_toupper))
				printf("char: (%c)%s[ko]%s[toupper: %d][ft_toupper: %d]\n", i, COLOR_RED, COLOR_RESET, original_toupper, libft_toupper);
		}
		else
		{
			if ((!original_toupper && libft_toupper) || (original_toupper && !libft_toupper))
				printf("char: (%d)%s[ko]%s[toupper: %d][ft_toupper: %d]\n", i, COLOR_RED, COLOR_RESET, original_toupper, libft_toupper);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int	result;
	int i = 1;

	printf("%s%s%-16s%s ", COLOR_BOLD, COLOR_CYAN, "ft_toupper:", COLOR_RESET);
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
