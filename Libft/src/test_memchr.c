/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:41:11 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/14 20:27:53 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

void segfault_handler(int signum)
{
	if (signum == SIGSEGV)
		printf("segfault");
	exit(1);
}

void exec_function(char **str, const void *s, int c, size_t n, void *(*ft)(const void *, int, size_t))
{
	int		pipe_fd[2];
	pid_t	pid;
	int		len;
	void	*result = 0;

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
		result = ft(s, c, n);
		printf("return: %p %s", result, (char *)result);
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
	const void	*s;
	int			c;
	size_t		n;
}	t_args;

void test_memchr(int d, int i, int e)
{
	char		*original;
	char		*libft;
	int 		ok = 0;
	int			ko = 0;
	int			iregular_ok = 0;
	int			count;
	char		*dst;
	int 		a = 'A';


	dst = malloc(1024);
	memset(dst, '.', 1024);
	count = 0;
	while (count < 1024)
	{
		if (a > 'z')
			a = 'A';
		dst[count] = a;
		a++;
		count++;
	}
	t_args arg[20] = {
		{"Hello World", 'H', 11},
		{"Hello World", 'e', 11},
		{"Hello World", 'l', 11},
		{"Hello World", 'o', 11},
		{"Hello World", ' ', 11},
		{"Hello World", 'W', 11},
		{"Hello World", 'r', 11},
		{"Hello World", 'd', 11},
		{"Hello World", 0, 11},
		{"Hello World", 'z', 11},
		{"Hello World", 'W', 200},
		{"Hello World", 'z', 200},
		{"Hello World", 'W', 0},
		{"Hello World", 'W', 6},
		{"Hello World", 'W', 7},
		{"", 'W', 11},
		{"", 'W', 1},
		{"", 0, 1},
		{0, 'W', 11},
		{0, 0, 0}
	};
	count = 0;
	original = (char *)malloc(1024);
	libft = (char *)malloc(1024);
	while (count < 20)
	{
		fflush(stdout);
		exec_function(&original, arg[count].s, arg[count].c, arg[count].n, &memchr);
		fflush(stdout);
		exec_function(&libft, arg[count].s, arg[count].c, arg[count].n, &ft_memchr);
		if (strcmp(original, libft) == 0)
		{
			ok++;
			if (d)
				printf("%s[ok]%s\n[memchr:    %s]\n[ft_memchr: %s]\ns *: \"%.15s\" c *: \"%d\" n: %zu \n", COLOR_GREEN, COLOR_RESET, original, libft, (char *)arg[count].s, arg[count].c, arg[count].n);
			
		}
		else
		{
			if (strcmp(libft, "segfault") == 0 || (strcmp(original, "segfault") == 0))
			{
				ko++;
				if (e || d)
				{
					printf("%s[ko]%s\n[memchr:    %s]\n[ft_memchr: %s]\ns *: \"%.15s\" c *: \"%d\" n: %zu \n", COLOR_RED, COLOR_RESET, original, libft, (char *)arg[count].s, arg[count].c, arg[count].n);
				}
			}
			else
			{
				ko++;
				if (e || d)
					printf("%s[ko]%s\n[memchr:    %s]\n[ft_memchr: %s]\ns *: \"%.15s\" c *: \"%d\" n: %zu \n", COLOR_RED, COLOR_RESET, original, libft, (char *)arg[count].s, arg[count].c, arg[count].n);
			}
		}
		count++;
	}
	if (!d && !i && !e)
	{
		if (ko > 0)
			printf("%s[ko]%s (%4d/40  )", COLOR_RED, COLOR_RESET, (ok * 2 + iregular_ok));
		else if (iregular_ok > 0)
			printf("%s[ok]%s (%4d/40  )", COLOR_YELLOW, COLOR_RESET, (ok * 2 + iregular_ok));
		else
			printf("%s[ok]%s (%4d/40  )", COLOR_GREEN, COLOR_RESET, (ok * 2 + iregular_ok));
	}
}

int main(int argc, char **argv)
{
	int count = 1;
	int d = 0;
	int i = 0;
	int e = 0;

	printf("%s%s%-16s%s ", COLOR_BOLD, COLOR_CYAN, "ft_memchr:", COLOR_RESET);
	test_memchr(d, i, e);
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
		test_memchr(d, i, e);
	return (0);
}
