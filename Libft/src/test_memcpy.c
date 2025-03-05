/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:23:47 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/03/05 18:36:52 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

void segfault_handler(int signum)
{
	if (signum == SIGSEGV)
		printf("segfault");
	exit(1);
}

void exec_function(char **str, void *dst, const void *src, size_t n, void *(*ft)(void *, const void *, size_t))
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
		result = ft(dst, src, n);
		printf("return: %p", result);
		len = 0;
		printf(" dst: ");
		while (len < 15)
		{
			if (isprint(((char *)dst)[len]))
				printf("%c", ((char *)dst)[len]);
			else
				printf("%d", ((char *)dst)[len]);
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
	void		*dst;
	const void 	*src;
	size_t		n;
}	t_args;

void test_memcpy(int d, int i, int e)
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
	t_args arg[14] = {
		{dst, "Hello World", 0},
		{dst, "Hello World", 5},
		{dst, "Hello World", 10},
		{dst, "Hello World", 12},
		{dst, &dst[1], 5},
		{&dst[1], dst, 5},
		{dst, &dst[5], 5},
		{&dst[5], dst, 5},
		{0, "Hello World", 0},
		{dst, 0, 0},
		{0, 0, 0},
		{0, "Hello World", 5},
		{dst, 0, 5},
		{0, 0, 5}//revisar si se puede considerar un caso irregular
	};
	count = 0;
	original = (char *)malloc(1024);
	libft = (char *)malloc(1024);
	while (count < 14)
	{
		fflush(stdout);
		exec_function(&original, arg[count].dst, arg[count].src, arg[count].n, &memcpy);
		fflush(stdout);
		exec_function(&libft, arg[count].dst, arg[count].src, arg[count].n, &ft_memcpy);
		if (strcmp(original, libft) == 0)
		{
			ok++;
			if (d)
				printf("%s[ok]%s\n[memcpy:    %s]\n[ft_memcpy: %s]\ndst *: \"%.15s\" src *: \"%.15s\" size_t: %zu \n", COLOR_GREEN, COLOR_RESET, original, libft, (char *)arg[count].dst, (char *)arg[count].src, arg[count].n);
			
		}
		else
		{
			if (strcmp(libft, "segfault") == 0 || (strcmp(original, "segfault") == 0))
			{
				ko++;
				if (e || d)
				{
					printf("%s[ko]%s\n[memcpy:    %s]\n[ft_memcpy: %s]\ndst *: \"%.15s\" src *: \"%.15s\" size_t: %zu \n", COLOR_RED, COLOR_RESET, original, libft, (char *)arg[count].dst, (char *)arg[count].src, arg[count].n);
				}
			}
			else
			{
				ko++;
				if (e || d)
					printf("%s[ko]%s\n[memcpy:    %s]\n[ft_memcpy: %s]\ndst *: \"%.15s\" src *: \"%.15s\" size_t: %zu \n", COLOR_RED, COLOR_RESET, original, libft, (char *)arg[count].dst, (char *)arg[count].src, arg[count].n);
			}
		}
		count++;
	}
	if (!d && !i && !e)
	{
		if (ko > 0)
			printf("%s[ko]%s (%4d/28  )", COLOR_RED, COLOR_RESET, (ok * 2 + iregular_ok));
		else if (iregular_ok > 0)
			printf("%s[ok]%s (%4d/28  )", COLOR_YELLOW, COLOR_RESET, (ok * 2 + iregular_ok));
		else
			printf("%s[ok]%s (%4d/28  )", COLOR_GREEN, COLOR_RESET, (ok * 2 + iregular_ok));
	}
}

int main(int argc, char **argv)
{
	int count = 1;
	int d = 0;
	int i = 0;
	int e = 0;

	printf("%s%s%-16s%s ", COLOR_BOLD, COLOR_CYAN, "ft_memcpy:", COLOR_RESET);
	test_memcpy(d, i, e);
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
		test_memcpy(d, i, e);
	return (0);
}
