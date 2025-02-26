/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:42:40 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/02/16 00:54:20 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int ft_return(int c)
{
	return (c);
}

void segfault_handler(int signum)
{
	if (signum == SIGSEGV)
		printf("segfault");
	exit(1);
}

void exec_function(char **str, const char *arg, int c, char *(*ft)(const char *, int))
{
	int		pipe_fd[2];
	pid_t	pid;
	char	*result;
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
		result = ft(arg, c);
		printf("%p", result);
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

typedef struct s_args
{
	const char	*str;
	int			c;
}	t_args;

void test_strchr(int d, int i, int e)
{
	char		*original;
	char		*libft;
	int 		ok = 0;
	int			iregular_ok = 0;
	int			ko = 0;
	int 		original_int;
	int			libft_int;
	int			count;
	
	t_args arg[12] = {
		{"Hello World", 'H'},
		{"Hello World", 'e'},
		{"Hello World", 'l'},
		{"Hello World", 'o'},
		{"Hello World", 'W'},
		{"Hello World", 'r'},
		{"Hello World", 'd'},
		{"Hello World", ' '},
		{"Hello World", 'z'},
		{"Hello World", 0},
		{"Hello World", -1},
		{0, 'H'}
	};
	count = 0;
	original = (char *)malloc(1024);
	libft = (char *)malloc(1024);
	while (count < 12)
	{
		fflush(stdout);
		exec_function(&original, arg[count].str, arg[count].c, &strchr);
		fflush(stdout);
		exec_function(&libft, arg[count].str, arg[count].c, &ft_strchr);
		original_int = atoi(original);
		libft_int = atoi(libft);
		if (strcmp(original, libft) == 0)
		{
			ok++;
			if (d)
				printf("%s[ok]%s[strchr: %9s][ft_strchr: %9s] str: \"%s\" int: %3d '%c' \n", COLOR_GREEN, COLOR_RESET, original, libft, arg[count].str, arg[count].c, arg[count].c);
			
		}
		else
		{
			if (strcmp(libft, "segfault") == 0 || (strcmp(original, "segfault") == 0))
			{
				ko++;
				if (e || d)
				{
					printf("%s[ko]%s[strchr: %9s][ft_strchr: %9s] str: \"%s\" int: %3d '%c' \n", COLOR_RED, COLOR_RESET, original, libft, arg[count].str, arg[count].c, arg[count].c);
				}
			}
			else
			{
				ko++;
				if (e || d)
					printf("%s[ko]%s[strchr: %9s][ft_strchr: %9s] str: \"%s\" int: %3d '%c' \n", COLOR_RED, COLOR_RESET, original, libft, arg[count].str, arg[count].c, arg[count].c);
			}
		}
		count++;
	}
	if (!d && !i && !e)
	{
		if (ko > 0)
			printf("%s[ko]%s (%4d/24  )", COLOR_RED, COLOR_RESET, (ok * 2 + iregular_ok));
		else if (iregular_ok > 0)
			printf("%s[ok]%s (%4d/24  )", COLOR_YELLOW, COLOR_RESET, (ok * 2 + iregular_ok));
		else
			printf("%s[ok]%s (%4d/24  )", COLOR_GREEN, COLOR_RESET, (ok * 2 + iregular_ok));
	}
}

int main(int argc, char **argv)
{
	int count = 1;
	int d = 0;
	int i = 0;
	int e = 0;

	printf("%s%s%-16s%s ", COLOR_BOLD, COLOR_CYAN, "ft_strchr:", COLOR_RESET);
	test_strchr(d, i, e);
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
		test_strchr(d, i, e);
	return (0);
}
