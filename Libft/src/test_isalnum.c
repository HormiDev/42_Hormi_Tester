/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 03:01:41 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/02/15 00:51:03 by ide-dieg         ###   ########.fr       */
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

void test_isalnum(int d, int i, int e)
{
	char	*original;
	char	*libft;
	int		arg;
	int 	ok = 0;
	int		iregular_ok = 0;
	int		ko = 0;
	int 	original_int;
	int		libft_int;

	original = (char *)malloc(1024);
	libft = (char *)malloc(1024);
	arg = -256;
	while (arg < 256)
	{
		fflush(stdout);
		exec_function(&original, arg, &isalnum);
		fflush(stdout);
		exec_function(&libft, arg, &ft_isalnum);
		original_int = atoi(original);
		libft_int = atoi(libft);
		if (strcmp(original, libft) == 0)
		{
			ok++;
			if (d)
			{
				if (isprint(arg))
					printf("char: (%c)%s[ok]%s[isalnum: %s][ft_isalnum: %s]\n", arg, COLOR_GREEN, COLOR_RESET, original, libft);
				else
					printf("char: (%d)%s[ok]%s[isalnum: %s][ft_isalnum: %s]\n", arg, COLOR_GREEN, COLOR_RESET, original, libft);
			}
			
		}
		else
		{
			if (strcmp(libft, "segfault") == 0 || (strcmp(original, "segfault") == 0))
			{
				ko++;
				if (e || d)
				{
					if (isprint(arg))
						printf("char: (%c)%s[ko]%s[isalnum: %s][ft_isalnum: %s]\n", arg, COLOR_RED, COLOR_RESET, original, libft);
					else
						printf("char: (%d)%s[ko]%s[isalnum: %s][ft_isalnum: %s]\n", arg, COLOR_RED, COLOR_RESET, original, libft);
				}
			}
			else if ((original_int > 0 && libft_int > 0) || (original_int < 0 && libft_int < 0))
			{
				iregular_ok++;
				if (i || d)
				{
					if (isprint(arg))
						printf("char: (%c)%s[ok]%s[isalnum: %s][ft_isalnum: %s]\n", arg, COLOR_YELLOW, COLOR_RESET, original, libft);
					else
						printf("char: (%d)%s[ok]%s[isalnum: %s][ft_isalnum: %s]\n", arg, COLOR_YELLOW, COLOR_RESET, original, libft);
				}
			}
			else
			{
				ko++;
				if (e || d)
				{
					if (isprint(arg))
						printf("char: (%c)%s[ko]%s[isalnum: %s][ft_isalnum: %s]\n", arg, COLOR_RED, COLOR_RESET, original, libft);
					else
						printf("char: (%d)%s[ko]%s[isalnum: %s][ft_isalnum: %s]\n", arg, COLOR_RED, COLOR_RESET, original, libft);
				}
			}
		}
		arg++;
	}
	if (!d && !i && !e)
	{
		if (ko > 0)
			printf("%s[ko]%s (%4d/1024)", COLOR_RED, COLOR_RESET, (ok * 2 + iregular_ok));
		else if (iregular_ok > 0)
			printf("%s[ok]%s (%4d/1024)", COLOR_YELLOW, COLOR_RESET, (ok * 2 + iregular_ok));
		else
			printf("%s[ok]%s (%4d/1024)", COLOR_GREEN, COLOR_RESET, (ok * 2 + iregular_ok));
	}
}

int main(int argc, char **argv)
{
	int count = 1;
	int d = 0;
	int i = 0;
	int e = 0;

	printf("%s%s%-16s%s ", COLOR_BOLD, COLOR_CYAN, "ft_isalnum:", COLOR_RESET);
	test_isalnum(d, i, e);
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
		test_isalnum(d, i, e);
	return (0);
}
