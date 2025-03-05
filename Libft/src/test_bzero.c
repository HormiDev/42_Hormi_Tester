/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:42:26 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/03/05 18:16:19 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

void segfault_handler(int signum)
{
	if (signum == SIGSEGV)
		printf("segfault");
	exit(1);
}

void exec_function(char **str, void *s, size_t n, void(*ft)(void *, size_t))
{
	int		pipe_fd[2];
	pid_t	pid;
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
		ft(s, n);
		len = 0;
		while(len < 15)
		{
			if (isprint(((char *)s)[len]))
				printf("%c", ((char *)s)[len]);
			else
				printf("%d", ((char *)s)[len]);
			len++;
		}
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
	void		*s;
	size_t		n;
}	t_args;

void test_bzero(int d, int i, int e)
{
	char		*original;
	char		*libft;
	int 		ok = 0;
	int			iregular_ok = 0;
	int			ko = 0;
	int			count;
	char		*str;

	str = malloc(1024);
	strcpy(str, "Hello World");
	str[5] = 0;
	t_args arg[16] = {
		{str, 0},
		{str, 1},
		{str, 2},
		{str, 3},
		{str, 4},
		{str, 5},
		{str, 6},
		{str, 7},
		{str, 8},
		{str, 9},
		{str, 10},
		{str, 11},
		{str, 12},
		{str, 1024},
		{str, 10240000},
		{0, 10}

	};
	count = 0;
	original = (char *)malloc(1024);
	libft = (char *)malloc(1024);
	while (count < 16)
	{
		fflush(stdout);
		exec_function(&original, arg[count].s, arg[count].n, &bzero);
		fflush(stdout);
		exec_function(&libft, arg[count].s, arg[count].n, &ft_bzero);
		if (strcmp(original, libft) == 0)
		{
			ok++;
			if (d)
				printf("%s[ok]%s[bzero: %15s][ft_bzero: %15s] void *: \"%s\" size_t: %zu \n", COLOR_GREEN, COLOR_RESET, original, libft, (char *)arg[count].s, arg[count].n);
			
		}
		else
		{
			if (strcmp(libft, "segfault") == 0 || (strcmp(original, "segfault") == 0))
			{
				ko++;
				if (e || d)
				{
					printf("%s[ko]%s[bzero: %15s][ft_bzero: %15s] void *: \"%s\" size_t: %zu \n", COLOR_RED, COLOR_RESET, original, libft, (char *)arg[count].s, arg[count].n);
				}
			}
			else
			{
				ko++;
				if (e || d)
					printf("%s[ko]%s[bzero: %15s][ft_bzero: %15s] void *: \"%s\" size_t: %zu \n", COLOR_RED, COLOR_RESET, original, libft, (char *)arg[count].s, arg[count].n);
			}
		}
		count++;
	}
	if (!d && !i && !e)
	{
		if (ko > 0)
			printf("%s[ko]%s (%4d/32  )", COLOR_RED, COLOR_RESET, (ok * 2 + iregular_ok));
		else if (iregular_ok > 0)
			printf("%s[ok]%s (%4d/32  )", COLOR_YELLOW, COLOR_RESET, (ok * 2 + iregular_ok));
		else
			printf("%s[ok]%s (%4d/32  )", COLOR_GREEN, COLOR_RESET, (ok * 2 + iregular_ok));
	}
}

int main(int argc, char **argv)
{
	int count = 1;
	int d = 0;
	int i = 0;
	int e = 0;

	printf("%s%s%-16s%s ", COLOR_BOLD, COLOR_CYAN, "ft_bzero:", COLOR_RESET);
	test_bzero(d, i, e);
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
		test_bzero(d, i, e);
	return (0);
}
