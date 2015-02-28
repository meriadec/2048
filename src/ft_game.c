/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:47:05 by bgronon           #+#    #+#             */
/*   Updated: 2015/02/28 16:51:19 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	ft_spawn(t_ctx *ctx, int i, int av)
{
	int *tmp;
	int random;

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
	random = rand() % av;
	ctx->map[tmp[random]] = 2;
	free(tmp);
}

int		ft_check_lock(t_ctx *ctx, int i, int av)
{
	while (i < (ctx->size * ctx->size))
	{
		if (ctx->map[i] == 0)
			++av;
		++i;
	}
	return (av);
}
