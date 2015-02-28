/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:21:00 by bgronon           #+#    #+#             */
/*   Updated: 2015/02/28 18:30:15 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		ft_ispowertwo(unsigned int x)
{
	while (((x % 2) == 0) && x > 1)
	{
		x /= 2;
	}
	return (x == 1);
}

int		ft_getpowexposant(int x)
{
	int	i;

	i = 1;
	while (x > 2)
	{
		x /= 2;
		i++;
	}
	return (i);
}

void	ft_reset_tile (t_ctx *ctx, int n)
{
	MAP[n] = 0;
	ctx->moved = 1;
}
