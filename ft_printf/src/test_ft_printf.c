/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:17:33 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/10/30 15:03:30 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_tester.h"

void segfault_handler(int signum)
{
	if (signum == SIGSEGV)
		printf("segfault");
	exit(1);
}

void exec_function(int (*ft)(const char *, ...), const char *format, ...)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		len;
	char	result[1024];
	char	buffer[1024];
	va_list args;
	
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();
	if (pid == 0)
	{
		va_start(args, format);
		vsnprintf(buffer, sizeof(buffer), format, args);
		signal(SIGSEGV, segfault_handler);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		int ret = ft(format, buffer);
		va_end(args);
		printf("%d", ret);
		exit(0);
	}
	else if (pid < 0)
	{
		printf("fork failed\n");
		exit(1);
	}
	waitpid(pid, NULL, 0);
	close(pipe_fd[1]);
	len = read(pipe_fd[0], result, 1024);
	result[len] = 0;
	close(pipe_fd[0]);
}

int	main(void)
{
	
	return (0);
}