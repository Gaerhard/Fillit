/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:09:34 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/03 15:20:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	set_color(int color)
{
	ft_putstr("\033[");
	if (color < 8)
	{
		ft_putstr("0;4");
		ft_putnbr(color);
	}
	else
	{
		ft_putstr("10");
		ft_putnbr(color - 8);
	}
	ft_putchar('m');
}

static void	put_border(char *str)
{
	ft_putstr("\033[107m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}

void		print_map(t_map m)
{
	short	i;
	short	j;

	i = -1;
	while (++i < m.size)
	{
		j = -1;
		while (++j < m.size)
		{
			if (m.map[i][j] == '\0')
				ft_putchar('.');
			else
				ft_putchar(m.map[i][j]);
		}
		ft_putchar('\n');
	}
}

static void	put_content(t_map m)
{
	short	i;
	short	j;

	i = -1;
	while (++i < m.size)
	{
		j = -2;
		while (++j <= m.size)
		{
			if (j == -1 || j == m.size)
				put_border("__");
			else if (m.map[i][j] == '\0')
				ft_putstr("  ");
			else
			{
				set_color(1 + m.map[i][j] - 'A');
				ft_putstr("  ");
				ft_putstr("\033[0m");
			}
		}
		ft_putchar('\n');
	}
}

void		print_map_color(t_map m)
{
	short	i;

	i = -2;
	while (++i <= m.size)
		put_border("| ");
	ft_putchar('\n');
	put_content(m);
	i = -2;
	while (++i <= m.size)
		put_border("| ");
	ft_putchar('\n');
}
