/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 02:56:41 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/01/23 02:58:12 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	normal_test(void)
{
	int i = 0;
	int original_isdigit;
	int libft_isdigit;
	int ok = 0;
	int iregular_ok = 0;
	int ko = 0;
	
	while (i < 256)
	{
		original_isdigit = isdigit(i);
		libft_isdigit = ft_isdigit(i);
		if (original_isdigit == libft_isdigit)
			ok++;
		else if ((original_isdigit && libft_isdigit) || (!original_isdigit && !libft_isdigit))
			iregular_ok++;
		else
			ko++;
		i++;
	}
	printf("%s%sft_isdigit:%s ", COLOR_BOLD, COLOR_BLUE, COLOR_RESET);
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
	int original_isdigit;
	int libft_isdigit;
	
	while (i < 256)
	{
		original_isdigit = isdigit(i);
		libft_isdigit = ft_isdigit(i);
		if (isprint(i))
		{
			if (original_isdigit == libft_isdigit)
				printf("char: (%c)%s[ok]%s\n", i, COLOR_GREEN, COLOR_RESET);
			else if ((original_isdigit && libft_isdigit) || (!original_isdigit && !libft_isdigit))
				printf("char: (%c)%s[ok]%s[isdigit: %d][ft_isdigit: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_isdigit, libft_isdigit);
			else
				printf("char: (%c)%s[ko]%s[isdigit: %d][ft_isdigit: %d]\n", i, COLOR_RED, COLOR_RESET, original_isdigit, libft_isdigit);
		}
		else
		{
			if (original_isdigit == libft_isdigit)
				printf("char: (%d)%s[ok]%s\n", i, COLOR_GREEN, COLOR_RESET);
			else if ((original_isdigit && libft_isdigit) || (!original_isdigit && !libft_isdigit))
				printf("char: (%d)%s[ok]%s[isdigit: %d][ft_isdigit: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_isdigit, libft_isdigit);
			else
				printf("char: (%d)%s[ko]%s[isdigit: %d][ft_isdigit: %d]\n", i, COLOR_RED, COLOR_RESET, original_isdigit, libft_isdigit);
		}
		i++;
	}
}

static void test_irregular_cases(void)
{
	int i = 0;
	int original_isdigit;
	int libft_isdigit;
	
	while (i < 256)
	{
		original_isdigit = isdigit(i);
		libft_isdigit = ft_isdigit(i);
		if (isprint(i))
		{
			if (!(original_isdigit == libft_isdigit) && ((original_isdigit && libft_isdigit) || (!original_isdigit && !libft_isdigit)))
				printf("char: (%c)%s[ok]%s[isdigit: %d][ft_isdigit: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_isdigit, libft_isdigit);
		}
		else
		{
			if (!(original_isdigit == libft_isdigit) && ((original_isdigit && libft_isdigit) || (!original_isdigit && !libft_isdigit)))
				printf("char: (%d)%s[ok]%s[isdigit: %d][ft_isdigit: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_isdigit, libft_isdigit);
		}
		i++;
	}
}

static void test_error_cases(void)
{
	int i = 0;
	int original_isdigit;
	int libft_isdigit;
	
	while (i < 256)
	{
		original_isdigit = isdigit(i);
		libft_isdigit = ft_isdigit(i);
		if (isprint(i))
		{
			if ((!original_isdigit && libft_isdigit) || (original_isdigit && !libft_isdigit))
				printf("char: (%c)%s[ko]%s[isdigit: %d][ft_isdigit: %d]\n", i, COLOR_RED, COLOR_RESET, original_isdigit, libft_isdigit);
		}
		else
		{
			if ((!original_isdigit && libft_isdigit) || (original_isdigit && !libft_isdigit))
				printf("char: (%d)%s[ko]%s[isdigit: %d][ft_isdigit: %d]\n", i, COLOR_RED, COLOR_RESET, original_isdigit, libft_isdigit);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int	result;
	int i = 1;

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