/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:47:05 by bgronon           #+#    #+#             */
/*   Updated: 2015/02/28 12:48:16 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	ft_spawn(t_ctx *ctx, int i, int av)
{
	int *tmp;

	tmp = (int *)malloc((ctx->size * ctx->size) * sizeof(*ctx->map));
	while (i < (ctx->size * ctx->size))
	{
		if (ctx->map[i] == 0)
		{
			tmp[av] = i;
			++av;
		}
		++i;
	}
	if (av == 0)
	{
		mvprintw(0, 0, "YOU LOOSE BITCH");
		return ;
	}
	int random = rand() % av;
	ctx->map[tmp[random]] = 2;
}

void	ft_gravity(t_ctx *ctx)
{
	(void)ctx;
}
