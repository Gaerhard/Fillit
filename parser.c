/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:39:14 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/03 14:19:23 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static short	check_piece(char piece[4][5])
{
	short	i;
	short	j;
	short	connect;
	short	block;

	i = -1;
	connect = 0;
	block = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (piece[i][j] == '#')
			{
				block++;
				connect += (j + 1 < 4 && piece[i][j + 1] == '#') ? 1 : 0;
				connect += (j - 1 >= 0 && piece[i][j - 1] == '#') ? 1 : 0;
				connect += (i + 1 < 4 && piece[i + 1][j] == '#') ? 1 : 0;
				connect += (i - 1 >= 0 && piece[i - 1][j] == '#') ? 1 : 0;
			}
		}
	}
	return (((connect != 6 && connect != 8) || block != 4) ? ERROR : 1);
}

static short	check_line(char *line, int line_count)
{
	if (line_count % 5 == 4 && ft_strlen(line) != 0)
		return (ERROR);
	else if (ft_strlen(line) != 4 && line_count % 5 != 4)
		return (ERROR);
	while (*line)
	{
		if (*line != '.' && *line != '#')
			return (ERROR);
		line++;
	}
	return (1);
}

static short	reader(t_tetri pieces[26], char *file)
{
	char	*line;
	int		fd;
	int		line_count;
	int		index;

	index = 0;
	line_count = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (ERROR);
	while (get_next_line(fd, &line))
	{
		if (check_line(line, line_count) == ERROR)
			return (ERROR);
		if (ft_strlen(line) == 0)
			index++;
		else
			ft_strcpy(pieces[index].tetri[line_count % 5], line);
		ft_strdel(&line);
		if (++line_count > 129)
			return (ERROR);
	}
	if (close(fd) == -1)
		return (ERROR);
	return ((line_count % 5 == 4) ? line_count / 5 : ERROR);
}

short			parser(t_tetri pieces[26], char *file)
{
	int		pieces_count;
	int		i;

	if ((pieces_count = reader(pieces, file)) == ERROR)
		return (ERROR);
	i = -1;
	while (++i <= pieces_count)
		if (check_piece(pieces[i].tetri) == ERROR)
			return (ERROR);
	i = -1;
	while (++i <= pieces_count)
	{
		pieces[i] = left_shift(pieces[i], i);
		pieces[i] = up_shift(pieces[i], i);
	}
	return (pieces_count);
}
