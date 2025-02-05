/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 03:05:59 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/02/05 22:27:23 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft_tester.h"

void segfault_handler(int signum)
{
	if (signum == SIGSEGV)
		printf("segfault");
	exit(1);
}

void exec_function(char **str, int arg, int (*ft)(int))
{
	int		pipe_fd[2];
	pid_t	pid;
	int		result;
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
		printf("%d", result);
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

void test_isascii(int d, int i, int e)
{
	char	*original;
	char	*libft;
	int		arg;
	int 	ok = 0;
	int		iregular_ok = 0;
	int		ko = 0;

	original = (char *)malloc(1024);
	libft = (char *)malloc(1024);
	arg = -256;
	while (arg < 256)
	{
		exec_function(&original, arg, &isascii);
		exec_function(&libft, arg, &ft_isascii);
		if (strcmp(original, libft) != 0)
		{
			if (strcmp(libft, "segfault") == 0)
			{
				if (e || d)
				{
					if (isprint(arg))
						printf("char: (%c)%s[ko]%s[isascii: %s][ft_isascii: %s]\n", arg, COLOR_RED, COLOR_RESET, original, libft);
					else
						printf("char: (%d)%s[ko]%s[isascii: %s][ft_isascii: %s]\n", arg, COLOR_RED, COLOR_RESET, original, libft);
				}
				ko++;
			}
			else if ((atoi(original) && atoi(libft)) || (!atoi(original) && !atoi(libft)))
			{
				if (i || d)
				{
					if (isprint(arg))
						printf("char: (%c)%s[ok]%s[isascii: %s][ft_isascii: %s]\n", arg, COLOR_YELLOW, COLOR_RESET, original, libft);
					else
						printf("char: (%d)%s[ok]%s[isascii: %s][ft_isascii: %s]\n", arg, COLOR_YELLOW, COLOR_RESET, original, libft);
				}
				iregular_ok++;
			}
			else
			{
				ko++;
				if (e || d)
				{
					if (isprint(arg))
						printf("char: (%c)%s[ko]%s[isascii: %s][ft_isascii: %s]\n", arg, COLOR_RED, COLOR_RESET, original, libft);
					else
						printf("char: (%d)%s[ko]%s[isascii: %s][ft_isascii: %s]\n", arg, COLOR_RED, COLOR_RESET, original, libft);
				}
			}
		}
		else
		{
			ok++;
			if (d)
			{
				if (isprint(arg))
					printf("char: (%c)%s[ok]%s[isascii: %s][ft_isascii: %s]\n", arg, COLOR_GREEN, COLOR_RESET, original, libft);
				else
					printf("char: (%d)%s[ok]%s[isascii: %s][ft_isascii: %s]\n", arg, COLOR_GREEN, COLOR_RESET, original, libft);
			}
		}
		arg++;
	}
	if (!d && !i && !e)
	{
		if (ko > 0)
			printf("%s[ko]%s (%d/1024)\n", COLOR_RED, COLOR_RESET, (ok * 2 + iregular_ok));
		else if (iregular_ok > 0)
			printf("%s[ok]%s (%d/1024)\n", COLOR_YELLOW, COLOR_RESET, (ok * 2 + iregular_ok));
		else
			printf("%s[ok]%s (%d/1024)\n", COLOR_GREEN, COLOR_RESET, (ok * 2 + iregular_ok));
	}
}

int main(int argc, char **argv)
{
	int count = 1;
	int d = 0;
	int i = 0;
	int e = 0;

	printf("%s%s%-16s%s ", COLOR_BOLD, COLOR_CYAN, "ft_isascii:", COLOR_RESET);
	test_isascii(d, i, e);
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
		test_isascii(d, i, e);
	return (0);
}
