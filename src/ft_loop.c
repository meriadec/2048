/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:57:14 by mpillet           #+#    #+#             */
/*   Updated: 2015/02/28 19:01:28 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int		st_has_enough_size(t_ctx *ctx)
{
	int	ret = (COLS/ctx->size >= MIN_CELL_W && LINES/ctx->size >= MIN_CELL_H);
	if (!ret)
	{
		ft_finish(ctx);
		ft_putendl("\n\nYour window is too small (nice try..)\n\n");
	}
	return ret;
}

void			ft_loop(t_ctx *ctx)
{
	int		key;

	ft_spawn(ctx, 0, 0);
	ft_draw(ctx);
	if (!st_has_enough_size(ctx))
		return ;
	while ((key = getch()) != 27)
	{
		if (key == KEY_RESIZE)
			ft_draw(ctx);
		if (!st_has_enough_size(ctx))
			return ;
		if (!ft_mov(ctx, key))
			return ;
		ft_draw(ctx);
	}
}
