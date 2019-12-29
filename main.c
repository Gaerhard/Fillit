/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:41:18 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/03 15:21:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_pieces	p;
	t_map		res;
	short		i;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit target_file");
		return (-1);
	}
	if ((p.count = parser(p.pieces, av[1])) == ERROR)
	{
		ft_putendl_fd("error", 1);
		return (ERROR);
	}
	res = solver(p);
	print_map(res);
	i = -1;
	while (++i < res.size)
		free(res.map[i]);
	free(res.map);
	return (0);
}
