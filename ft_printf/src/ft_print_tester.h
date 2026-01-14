/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tester.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:20:42 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/10/30 14:52:21 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_TESTER_H
# define FT_PRINT_TESTER_H

# include <limits.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>

# define COLOR_RESET   "\x1b[0m"
# define COLOR_RED     "\x1b[31m"
# define COLOR_GREEN   "\x1b[32m"
# define COLOR_YELLOW  "\x1b[33m"
# define COLOR_BLUE    "\x1b[34m"
# define COLOR_CYAN    "\x1b[36m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_BOLD    "\x1b[1m"

int	ft_printf(char const *, ...);

#endif