/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 03:01:41 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/01/23 03:03:40 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	normal_test(void)
{
	int i = 0;
	int original_isalnum;
	int libft_isalnum;
	int ok = 0;
	int iregular_ok = 0;
	int ko = 0;
	
	while (i < 256)
	{
		original_isalnum = isalnum(i);
		libft_isalnum = ft_isalnum(i);
		if (original_isalnum == libft_isalnum)
			ok++;
		else if ((original_isalnum && libft_isalnum) || (!original_isalnum && !libft_isalnum))
			iregular_ok++;
		else
			ko++;
		i++;
	}
	printf("%s%sft_isalnum:%s ", COLOR_BOLD, COLOR_BLUE, COLOR_RESET);
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
	int original_isalnum;
	int libft_isalnum;
	
	while (i < 256)
	{
		original_isalnum = isalnum(i);
		libft_isalnum = ft_isalnum(i);
		if (isprint(i))
		{
			if (original_isalnum == libft_isalnum)
				printf("char: (%c)%s[ok]%s\n", i, COLOR_GREEN, COLOR_RESET);
			else if ((original_isalnum && libft_isalnum) || (!original_isalnum && !libft_isalnum))
				printf("char: (%c)%s[ok]%s[isalnum: %d][ft_isalnum: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_isalnum, libft_isalnum);
			else
				printf("char: (%c)%s[ko]%s[isalnum: %d][ft_isalnum: %d]\n", i, COLOR_RED, COLOR_RESET, original_isalnum, libft_isalnum);
		}
		else
		{
			if (original_isalnum == libft_isalnum)
				printf("char: (%d)%s[ok]%s\n", i, COLOR_GREEN, COLOR_RESET);
			else if ((original_isalnum && libft_isalnum) || (!original_isalnum && !libft_isalnum))
				printf("char: (%d)%s[ok]%s[isalnum: %d][ft_isalnum: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_isalnum, libft_isalnum);
			else
				printf("char: (%d)%s[ko]%s[isalnum: %d][ft_isalnum: %d]\n", i, COLOR_RED, COLOR_RESET, original_isalnum, libft_isalnum);
		}
		i++;
	}
}

static void test_irregular_cases(void)
{
	int i = 0;
	int original_isalnum;
	int libft_isalnum;
	
	while (i < 256)
	{
		original_isalnum = isalnum(i);
		libft_isalnum = ft_isalnum(i);
		if (isprint(i))
		{
			if (!(original_isalnum == libft_isalnum) && ((original_isalnum && libft_isalnum) || (!original_isalnum && !libft_isalnum)))
				printf("char: (%c)%s[ok]%s[isalnum: %d][ft_isalnum: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_isalnum, libft_isalnum);
		}
		else
		{
			if (!(original_isalnum == libft_isalnum) && ((original_isalnum && libft_isalnum) || (!original_isalnum && !libft_isalnum)))
				printf("char: (%d)%s[ok]%s[isalnum: %d][ft_isalnum: %d]\n", i, COLOR_YELLOW, COLOR_RESET, original_isalnum, libft_isalnum);
		}
		i++;
	}
}

static void test_error_cases(void)
{
	int i = 0;
	int original_isalnum;
	int libft_isalnum;
	
	while (i < 256)
	{
		original_isalnum = isalnum(i);
		libft_isalnum = ft_isalnum(i);
		if (isprint(i))
		{
			if ((!original_isalnum && libft_isalnum) || (original_isalnum && !libft_isalnum))
				printf("char: (%c)%s[ko]%s[isalnum: %d][ft_isalnum: %d]\n", i, COLOR_RED, COLOR_RESET, original_isalnum, libft_isalnum);
		}
		else
		{
			if ((!original_isalnum && libft_isalnum) || (original_isalnum && !libft_isalnum))
				printf("char: (%d)%s[ko]%s[isalnum: %d][ft_isalnum: %d]\n", i, COLOR_RED, COLOR_RESET, original_isalnum, libft_isalnum);
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