/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 01:14:44 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/02/26 19:56:33 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

void segfault_handler(int signum)
{
	if (signum == SIGSEGV)
		printf("segfault");
	exit(1);
}

void exec_function(char **str, const char *arg, size_t (*ft)(const char *))
{
	int		pipe_fd[2];
	pid_t	pid;
	size_t	result;
	int		len;

	if (pipe(pipe_fd) == -1)
	{
        perror("pipe");
        exit(1);
    }
	pid = fork();
	if (pid == 0)
	{
		signal(SIGSEGV, segfault_handler);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		result = ft(arg);
		printf("%zu", result);
		exit(0);
	}
	else if (pid < 0)
	{
		printf("fork failed\n");
		exit(1);
	}
	waitpid(pid, NULL, 0);
	close(pipe_fd[1]);
	len = read(pipe_fd[0], *str, 100);
	(*str)[len] = 0;
	close(pipe_fd[0]);
}

void test_strlen(int d, int i, int e)
{
	char		*original;
	char		*libft;
	int 		ok = 0;
	int			iregular_ok = 0;
	int			ko = 0;
	int			count;
	char 	str1[128];
	char 	str2[255];
	char 	str3[512];
	const char	*arg[10] = {
		"hello",
		"hello world",
		"HormiTester is awesome",
		"hello\\0\0world",
		" ",
		"",
		0,
		str1,
		str2,
		str3};

	count = 0;
	while (count < 127)
	{
		str1[count] = 1 + count;
		count++;
	}
	str1[count] = 0;
	count = 0;
	while (count < 254)
	{
		str2[count] = 1 + count;
		count++;
	}
	str2[count] = 0;
	count = 0;
	while (count < 510)
	{
		if (254 - count != 0)
			str3[count] = count - 254;
		else
			str3[count] = count + 1;
		count++;
	}
	str3[count] = 0;

	count = 0;
	original = (char *)malloc(1024);
	libft = (char *)malloc(1024);
	while (count < 10)
	{
		fflush(stdout);
		exec_function(&original, arg[count], &strlen);
		fflush(stdout);
		exec_function(&libft, arg[count], &ft_strlen);
		if (strcmp(original, libft) == 0)
		{
			ok++;
			if (d)
				printf("%s[ok]%s[strlen: %s][ft_strlen: %s] str: \"%s\"\n", COLOR_GREEN, COLOR_RESET, original, libft, arg[count]);
			
		}
		else
		{
			if (strcmp(libft, "segfault") == 0 || (strcmp(original, "segfault") == 0))
			{
				ko++;
				if (e || d)
				{
					printf("%s[ko]%s[strlen: %s][ft_strlen: %s] str: \"%s\"\n", COLOR_RED, COLOR_RESET, original, libft, arg[count]);
				}
			}
			else
			{
				ko++;
				if (e || d)
					printf("%s[ko]%s[strlen: %s][ft_strlen: %s] str: \"%s\"\n", COLOR_RED, COLOR_RESET, original, libft, arg[count]);
			}
		}
		count++;
	}
	if (!d && !i && !e)
	{
		if (ko > 0)
			printf("%s[ko]%s (%4d/20  )", COLOR_RED, COLOR_RESET, (ok * 2 + iregular_ok));
		else if (iregular_ok > 0)
			printf("%s[ok]%s (%4d/20  )", COLOR_YELLOW, COLOR_RESET, (ok * 2 + iregular_ok));
		else
			printf("%s[ok]%s (%4d/20  )", COLOR_GREEN, COLOR_RESET, (ok * 2 + iregular_ok));
	}
}

int main(int argc, char **argv)
{
	int count = 1;
	int d = 0;
	int i = 0;
	int e = 0;

	printf("%s%s%-16s%s ", COLOR_BOLD, COLOR_CYAN, "ft_strlen:", COLOR_RESET);
	test_strlen(d, i, e);
	printf("\n");
	while (count < argc)
	{
		if ((!strcmp(argv[count], "-d") || !strcmp(argv[count], "--detail")))
			d = 1;
		if ((!strcmp(argv[count], "-i") || !strcmp(argv[count], "--irregular")))
			i = 1;
		if ((!strcmp(argv[count], "-e") || !strcmp(argv[count], "--error")))
			e = 1;
		count++;
	}
	if (d || i || e)
		test_strlen(d, i, e);
	return (0);
}
