/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 01:07:01 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/20 01:27:46 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

void segfault_handler(int signum)
{
	if (signum == SIGSEGV)
		printf("segfault");
	exit(1);
}

void exec_function(char **str, const void *str1, const void *str2, size_t n, int (*ft)(const void *,const void * , size_t))
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
		result = ft(str1, str2, n);
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

typedef struct s_args
{
	const void	*str1;
	const void	*str2;
	size_t			n;
}	t_args;

void test_memcmp(int d, int i, int e)
{
	char		*original;
	char		*libft;
	int 		ok = 0;
	int			iregular_ok = 0;
	int			ko = 0;
	int			count;
	
	t_args arg[25] = {
		{"Hello World", "Hello World", 14},
		{"Hello World", "Hello World", 13},
		{"Hello World", "Hello World", 12},
		{"Hello World", "Hello World", 11},
		{"Hello World", "Hello World", 10},
		{"Hello World", "Hello World", 9},
		{"Hello World", "Hello World", 8},
		{"Hello World", "Hello World", 7},
		{"Hello World", "Hello World", 6},
		{"Hello World", "Hello World", 5},
		{"Hello World", "Hello World", 4},
		{"Hello World", "Hello World", 3},
		{"Hello World", "Hello World", 2},
		{"Hello World", "Hello World", 1},
		{"Hello World", "Hello World", 0},
		{"Hello World", "Hello World", INT_MAX},
		{"Hello World", "Hello World", 2147483648},
		{"Hello", "Hello World", 12},
		{"Hello World", "Hello", 12},
		{"", "Hello World", 100},
		{"Hello World", "", 100},
		{"Hello World", 0, 100},
		{0, "Hello World", 100},
		{0, 0, 100},
		{0, 0, 0}
	};
	count = 0;
	original = (char *)malloc(1024);
	libft = (char *)malloc(1024);
	while (count < 25)
	{
		fflush(stdout);
		exec_function(&original, arg[count].str1, arg[count].str2, arg[count].n, &memcmp);
		fflush(stdout);
		exec_function(&libft, arg[count].str1, arg[count].str2, arg[count].n, &ft_memcmp);
		if (strcmp(original, libft) == 0)
		{
			ok++;
			if (d)
				printf("%s[ok]%s[memcmp: %9s][ft_memcmp: %9s] str1: \"%s\" str2: \"%s\" n: %zu\n", COLOR_GREEN, COLOR_RESET, original, libft, (char *)arg[count].str1, (char *)arg[count].str2, arg[count].n);
			
		}
		else
		{
			if (strcmp(libft, "segfault") == 0 || (strcmp(original, "segfault") == 0))
			{
				ko++;
				if (e || d)
				{
					printf("%s[ko]%s[memcmp: %9s][ft_memcmp: %9s] str1: \"%s\" str2: \"%s\" n: %zu\n", COLOR_RED, COLOR_RESET, original, libft, (char *)arg[count].str1, (char *)arg[count].str2, arg[count].n);
				}
			}
			else
			{
				ko++;
				if (e || d)
					printf("%s[ko]%s[memcmp: %9s][ft_memcmp: %9s] str1: \"%s\" str2: \"%s\" n: %zu\n", COLOR_RED, COLOR_RESET, original, libft, (char *)arg[count].str1, (char *)arg[count].str2, arg[count].n);
			}
		}
		count++;
	}
	if (!d && !i && !e)
	{
		if (ko > 0)
			printf("%s[ko]%s (%4d/50  )", COLOR_RED, COLOR_RESET, (ok * 2 + iregular_ok));
		else if (iregular_ok > 0)
			printf("%s[ok]%s (%4d/50  )", COLOR_YELLOW, COLOR_RESET, (ok * 2 + iregular_ok));
		else
			printf("%s[ok]%s (%4d/50  )", COLOR_GREEN, COLOR_RESET, (ok * 2 + iregular_ok));
	}
}

int main(int argc, char **argv)
{
	int count = 1;
	int d = 0;
	int i = 0;
	int e = 0;

	printf("%s%s%-16s%s ", COLOR_BOLD, COLOR_CYAN, "ft_memcmp:", COLOR_RESET);
	test_memcmp(d, i, e);
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
		test_memcmp(d, i, e);
	return (0);
}
