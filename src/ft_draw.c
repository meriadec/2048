/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:04:54 by mpillet           #+#    #+#             */
/*   Updated: 2015/02/28 13:23:09 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void			st_draw_tile(t_ctx *ctx, int n, int ch, int cw)
{
	int		x;
	int		y;

	y = (n / ctx->size) * ch + 2;
	x = (n % ctx->size) * cw + 2;
	if (ctx->map[n])
	{
		mvprintw(y, x, "%d", ctx->map[n]);
	}
}

static void			st_draw_cell(t_ctx *ctx, int n, int ch, int cw)
{
	int		x;
	int		y;

	y = (n / ctx->size) * ch;
	x = (n % ctx->size) * cw;
	if (n / ctx->size != 0)
	{
		while (x < (n % ctx->size) * cw + cw)
		{
			mvprintw(y, x, "-");
			++x;
		}
		x = (n % ctx->size) * cw;
	}
	if (n % ctx->size != 0)
	{
		++y;
		while (y < (n / ctx->size) * ch + ch)
		{
			mvprintw(y, x, "|");
			++y;
		}
	}
	st_draw_tile(ctx, n, ch, cw);
}

void				ft_draw(t_ctx *ctx)
{
	int		cw;
	int		ch;
	int		n;

	clear();
	cw = COLS / ctx->size;
	ch = LINES / ctx->size;
	n = 0;
	while (n < ctx->size * ctx->size)
	{
		st_draw_cell(ctx, n, ch, cw);
		++n;
	}
	refresh();
}