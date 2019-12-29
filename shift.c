/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:10:22 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/03 13:22:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	move_left(t_tetri t, int curr, int dist)
{
	short	i;
	short	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (t.tetri[i][j] == '#')
			{
				t.tetri[i][j] = '.';
				t.tetri[i][j - dist] = curr + 65;
			}
	}
	return (t);
}

t_tetri	move_up(t_tetri t, int curr, int dist)
{
	short	i;
	short	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (t.tetri[i][j] == curr + 65)
			{
				t.tetri[i][j] = '.';
				t.tetri[i - dist][j] = curr + 65;
			}
	}
	return (t);
}

t_tetri	left_shift(t_tetri t, int curr)
{
	int i;
	int j;
	int	dist;
	int	max;

	j = -1;
	dist = 3;
	max = 0;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
		{
			max = (t.tetri[i][j] == '#' && j >= max) ? j : max;
			dist = (t.tetri[i][j] == '#' && j < dist) ? j : dist;
		}
	}
	t.width = max - dist + 1;
	t = move_left(t, curr, dist);
	return (t);
}

t_tetri	up_shift(t_tetri t, int curr)
{
	int i;
	int j;
	int dist;
	int	max;

	i = -1;
	dist = 3;
	max = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			max = (t.tetri[i][j] == curr + 65 && i >= max) ? i : max;
			dist = (t.tetri[i][j] == curr + 65 && i < dist) ? i : dist;
		}
	}
	t.height = max - dist + 1;
	t = move_up(t, curr, dist);
	return (t);
}
