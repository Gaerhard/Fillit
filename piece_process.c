/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:23:52 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/03 13:24:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

short	clear_piece(t_map m, char ch, t_coord c)
{
	short	i;
	short	j;

	i = c.y - 1;
	while (++i < m.size && i < c.y + 4)
	{
		j = c.x - 1;
		while (++j < m.size && j < c.x + 4)
			if (m.map[i][j] == ch)
				m.map[i][j] = '\0';
	}
	return (0);
}

short	put_piece(t_tetri t, t_map m, t_coord c, short current)
{
	short	i;
	short	j;

	i = -1;
	current += 0;
	while (++i < t.height)
	{
		j = -1;
		while (++j < t.width)
			if (t.tetri[i][j] != '.')
				m.map[i + c.y][j + c.x] = t.tetri[i][j];
	}
	return (1);
}

short	test_piece(t_tetri t, t_map m, t_coord c, short current)
{
	short	i;
	short	j;

	i = -1;
	current += 0;
	while (++i < t.height)
	{
		j = -1;
		while (++j < t.width)
			if (t.tetri[i][j] != '.')
				if (m.map[i + c.y][j + c.x] != '\0')
					return (0);
	}
	return (1);
}
