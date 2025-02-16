/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 01:46:18 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/02/16 12:42:40 by ide-dieg         ###   ########.fr       */
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

void exec_function(char **str, const char *str1, const char *str2, int n, int (*ft)(const char *,const char * , size_t))
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
	const char	*str1;
	const char	*str2;
	size_t			n;
}	t_args;

void test_strncmp(int d, int i, int e)
{
	char		*original;
	char		*libft;
	int 		ok = 0;
	int			iregular_ok = 0;
	int			ko = 0;
	int 		original_int;
	int			libft_int;
	int			count;
	
	t_args arg[19] = {
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
		{"Hello World", "Hello World", INT_MAX},
		{"Hello World", "Hello World", 2147483648},
		{"Hello", "Hello World", 12},
		{"Hello World", "Hello", 12}
	};
	count = 0;
	original = (char *)malloc(1024);
	libft = (char *)malloc(1024);
	while (count < 19)
	{
		fflush(stdout);
		exec_function(&original, arg[count].str1, arg[count].str2, arg[count].n, &strncmp);
		fflush(stdout);
		exec_function(&libft, arg[count].str1, arg[count].str2, arg[count].n, &ft_strncmp);
		original_int = atoi(original);
		libft_int = atoi(libft);
		if (original_int == libft_int)
		{
			ok++;
			if (d)
				printf("%s[ok]%s[strncmp: %9s][ft_strncmp: %9s] str1: \"%s\" str2: \"%s\" n: %zu\n", COLOR_GREEN, COLOR_RESET, original, libft, arg[count].str1, arg[count].str2, arg[count].n);
			
		}
		else
		{
			if (strcmp(libft, "segfault") == 0 || (strcmp(original, "segfault") == 0))
			{
				ko++;
				if (e || d)
				{
					printf("%s[ko]%s[strncmp: %9s][ft_strncmp: %9s] str1: \"%s\" str2: \"%s\" n: %zu\n", COLOR_RED, COLOR_RESET, original, libft, arg[count].str1, arg[count].str2, arg[count].n);
				}
			}
			else
			{
				ko++;
				if (e || d)
					printf("%s[ko]%s[strncmp: %9s][ft_strncmp: %9s] str1: \"%s\" str2: \"%s\" n: %zu\n", COLOR_RED, COLOR_RESET, original, libft, arg[count].str1, arg[count].str2, arg[count].n);
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

	printf("%s%s%-16s%s ", COLOR_BOLD, COLOR_CYAN, "ft_strncmp:", COLOR_RESET);
	test_strncmp(d, i, e);
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
		test_strncmp(d, i, e);
	return (0);
}
