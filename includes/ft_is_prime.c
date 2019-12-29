/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:59:16 by gaerhard          #+#    #+#             */
/*   Updated: 2018/11/10 15:59:26 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_prime(int nb)
{
	int i;

	i = 1;
	if (nb == 2 || nb == 3)
		return (1);
	if (nb <= 1 || nb % 2 == 0)
		return (0);
	while (i <= nb / i)
	{
		i = i + 2;
		if (nb % i == 0)
			return (0);
	}
	return (1);
}
