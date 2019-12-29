/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:52:17 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/03 13:26:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		init_sqrts(short sqrts[26])
{
	sqrts[0] = 2;
	sqrts[1] = 3;
	sqrts[2] = 4;
	sqrts[3] = 4;
	sqrts[4] = 5;
	sqrts[5] = 5;
	sqrts[6] = 6;
	sqrts[7] = 6;
	sqrts[8] = 6;
	sqrts[9] = 7;
	sqrts[10] = 7;
	sqrts[11] = 7;
	sqrts[12] = 8;
	sqrts[13] = 8;
	sqrts[14] = 8;
	sqrts[15] = 8;
	sqrts[16] = 9;
	sqrts[17] = 9;
	sqrts[18] = 9;
	sqrts[19] = 9;
	sqrts[20] = 10;
	sqrts[21] = 10;
	sqrts[22] = 10;
	sqrts[23] = 10;
	sqrts[24] = 10;
}

static char		**init_map(short size)
{
	short	i;
	char	**map;

	if (!(map = (char**)malloc(sizeof(*(map)) * size)))
		return (0);
	i = -1;
	while (++i < size)
	{
		if (!(map[i] = ft_strnew(size)))
		{
			i = -1;
			while (map[++i])
				free(map[i]);
			free(map);
			return (0);
		}
	}
	return (map);
}

static t_map	grow_map(t_map m)
{
	t_map	new;
	short	i;

	i = -1;
	while (++i < m.size)
		free(m.map[i]);
	free(m.map);
	if (!(new.map = init_map(m.size + 1)))
		exit(ERROR);
	new.size = m.size + 1;
	return (new);
}

static short	fill_map(t_pieces p, t_map m, t_coord c, short current)
{
	t_coord zero;

	zero.x = 0;
	zero.y = 0;
	if (current == p.count)
		return (1);
	if (c.x + p.pieces[current].width <= m.size && c.y +
			p.pieces[current].height <= m.size &&
			test_piece(p.pieces[current], m, c, current) == 1)
	{
		put_piece(p.pieces[current], m, c, current);
		if (fill_map(p, m, zero, current + 1))
			return (1);
		clear_piece(m, current + 'A', c);
	}
	c.x++;
	if (c.x == m.size)
	{
		c.y++;
		if (c.y == m.size)
			return (0);
		c.x = 0;
	}
	return (fill_map(p, m, c, current));
}

t_map			solver(t_pieces p)
{
	t_map	m;
	t_coord	c;
	short	sqrts[26];

	c.x = 0;
	c.y = 0;
	init_sqrts(sqrts);
	sqrts[25] = 11;
	p.count++;
	m.size = sqrts[p.count - 1];
	if (!(m.map = init_map(m.size)))
		exit(ERROR);
	while (fill_map(p, m, c, 0) != 1)
		m = grow_map(m);
	return (m);
}
