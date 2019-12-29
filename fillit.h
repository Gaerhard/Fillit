/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:08:11 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/03 15:24:10 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# define ERROR -1

typedef struct	s_tetri
{
	char	tetri[4][5];
	short	width;
	short	height;
}				t_tetri;

typedef struct	s_pieces
{
	t_tetri	pieces[26];
	short	count;
}				t_pieces;

typedef struct	s_map
{
	char	**map;
	short	size;
}				t_map;

typedef struct	s_coord
{
	short	x;
	short	y;
}				t_coord;

short			parser(t_tetri pieces[26], char *file);
t_map			solver(t_pieces p);
t_tetri			left_shift(t_tetri t, int curr);
t_tetri			up_shift(t_tetri t, int curr);
void			print_map(t_map m);
void			print_map_color(t_map m);
short			clear_piece(t_map m, char ch, t_coord c);
short			put_piece(t_tetri t, t_map m, t_coord c, short current);
short			test_piece(t_tetri t, t_map m, t_coord c, short current);

#endif
