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
	int	*tmp;
	int	random;

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
	ctx->map[tmp[random]] = (rand() % 10 < 8) ? 2 : 4;
	free(tmp);
}

int		ft_check_lock(t_ctx *ctx, int i)
{
	while (i < (ctx->size * ctx->size))
	{
		if (ctx->map[i] == 0)
			return (1);
		else
		{
			if (i > SIZ && MAP[i - SIZ] == MAP[i])
				return (1);
			if (i < (SIZ * SIZ) - SIZ && MAP[i + SIZ] == MAP[i])
				return (1);
			if (i % SIZ > 0 && MAP[i - 1] == MAP[i])
				return (1);
			if (i % SIZ < SIZ - 1 && MAP[i + 1] == MAP[i])
				return (1);
		}
		++i;
	}
	return (0);
}

int		ft_check_win(t_ctx *ctx, int i)
{
	while (i < (ctx->size * ctx->size))
	{
		if (ctx->map[i] == WIN_VALUE)
		{
			ctx->win = 1;
			ft_dialog("You win ! Congratulations !", "Continue");
			return (1);
		}
		++i;
	}
	return (0);
}
