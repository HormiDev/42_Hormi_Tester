/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatigarc <fatigarc@student.42madrid.comr>   +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:46:18 by fatigarc          #+#    #+#             */
/*   Updated: 2023/11/12 21:09:41 by ide_dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
char	get_char(int x, int y, int contx, int conty);

void	rush(int x, int y)
{
	int	contx;
	int	conty;

	if (x < 0 || y < 0)
	{
		write(1, "¡Eh, los números negativos no son bienvenidos aquí! 😄\n", 59);
	}
	else
	{
		contx = 0;
		conty = 0;
		while (conty < y)
		{
			contx = 0;
			while (contx < x)
			{
				ft_putchar(get_char(x, y, contx, conty));
				contx++;
			}
			conty++;
			ft_putchar('\n');
		}
	}
}

// get_char para  rush01
char	get_char(int x, int y, int contx, int conty)
{
	if (conty > 0 && conty < y - 1 && contx > 0 && contx < x - 1)
		return (' ');
	else if (contx == 0 && conty == 0)
		return ('/');
	else if (contx == x - 1 && conty == 0)
		return ('\\');
	else if (contx == 0 && conty == y - 1)
		return ('\\');
	else if (contx == x - 1 && conty == y - 1)
		return ('/');
	else
		return ('*');
	return ('@');
}
