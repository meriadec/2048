/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:31:32 by bgronon           #+#    #+#             */
/*   Updated: 2015/02/28 17:33:18 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	ft_up(t_ctx *ctx, int x, int y, int tmp)
{
	while (x < ctx->size)
	{
		y = 1;
		while (y < ctx->size)
		{
			tmp = y - 1;
			while (ctx->map[tmp * ctx->size + x] == 0 && tmp > 0)
				--tmp;
			if (ctx->map[tmp * ctx->size + x] == 0)
			{
				ctx->map[tmp * ctx->size + x] = ctx->map[y * ctx->size + x];
				ctx->map[y * ctx->size + x] = 0;
			}
			else if ((ctx->map[tmp * ctx->size + x] == ctx->map[y * ctx->size + x]) || (tmp != y - 1))
			{
				if (ctx->map[tmp * ctx->size + x] == ctx->map[y * ctx->size + x])
					ctx->map[tmp * ctx->size + x] = ctx->map[y * ctx->size + x] + ctx->map[y * ctx->size + x];
				else if (tmp != y - 1)
					ctx->map[(tmp + 1) * ctx->size + x] = ctx->map[y * ctx->size + x];
				ctx->map[y * ctx->size + x] = 0;
			}
			++y;
		}
		++x;
	}
}

void	ft_down(t_ctx *ctx, int x, int y, int tmp)
{
	while (x < ctx->size)
	{
		y = ctx->size - 2;
		while (y >= 0)
		{
			tmp = y + 1;
			while (ctx->map[tmp * ctx->size + x] == 0 && tmp < ctx->size - 1)
				++tmp;
			if (ctx->map[tmp * ctx->size + x] == 0)
			{
				ctx->map[tmp * ctx->size + x] = ctx->map[y * ctx->size + x];
				ctx->map[y * ctx->size + x] = 0;
			}
			else if ((ctx->map[tmp * ctx->size + x] == ctx->map[y * ctx->size + x]) || (tmp != y + 1))
			{
				if (ctx->map[tmp * ctx->size + x] == ctx->map[y * ctx->size + x])
					ctx->map[tmp * ctx->size + x] = ctx->map[y * ctx->size + x] + ctx->map[y * ctx->size + x];
				else if (tmp != y + 1)
					ctx->map[(tmp - 1) * ctx->size + x] = ctx->map[y * ctx->size + x];
				ctx->map[y * ctx->size + x] = 0;
			}
			--y;
		}
		++x;
	}
}

void	ft_left(t_ctx *ctx, int x, int y, int tmp)
{
	while (y < ctx->size)
	{
		x = 1;
		while (x < ctx->size)
		{
			tmp = x - 1;
			while (ctx->map[y * ctx->size + tmp] == 0 && tmp > 0)
				--tmp;
			if (ctx->map[y * ctx->size + tmp] == 0)
			{
				ctx->map[y * ctx->size + tmp] = ctx->map[y * ctx->size + x];
				ctx->map[y * ctx->size + x] = 0;
			}
			else if ((ctx->map[y * ctx->size + tmp] == ctx->map[y * ctx->size + x]) || (tmp != x - 1))
			{
				if (ctx->map[y * ctx->size + tmp] == ctx->map[y * ctx->size + x])
					ctx->map[y * ctx->size + tmp] = ctx->map[y * ctx->size + x] + ctx->map[y * ctx->size + x];
				else if (tmp != x - 1)
					ctx->map[y * ctx->size + tmp + 1] = ctx->map[y * ctx->size + x];
				ctx->map[y * ctx->size + x] = 0;
			}
			++x;
		}
		++y;
	}
}

void	ft_right(t_ctx *ctx, int x, int y, int tmp)
{
	while (y < ctx->size)
	{
		x = ctx->size - 2;
		while (x >= 0)
		{
			tmp = x + 1;
			while (ctx->map[y * ctx->size + tmp] == 0 && tmp < ctx->size - 1)
				++tmp;
			if (ctx->map[y * ctx->size + tmp] == 0)
			{
				ctx->map[y * ctx->size + tmp] = ctx->map[y * ctx->size + x];
				ctx->map[y * ctx->size + x] = 0;
			}
			else if ((ctx->map[y * ctx->size + tmp] == ctx->map[y * ctx->size + x]) || (tmp != x + 1))
			{
				if (ctx->map[y * ctx->size + tmp] == ctx->map[y * ctx->size + x])
					ctx->map[y * ctx->size + tmp] = ctx->map[y * ctx->size + x] + ctx->map[y * ctx->size + x];
				else if (tmp != x + 1)
					ctx->map[y * ctx->size + tmp - 1] = ctx->map[y * ctx->size + x];
				ctx->map[y * ctx->size + x] = 0;
			}
			--x;
		}
		++y;
	}
}

void	ft_mov(t_ctx *ctx, int key)
{
	void (*p[4])(t_ctx *ctx, int x, int y, int tmp);

	if (!(key >= 258 && key <= 261))
		return ;
	p[0] = ft_down;
	p[1] = ft_up;
	p[2] = ft_left;
	p[3] = ft_right;
	(*p[key - 258])(ctx, 0, 0, 0);
	ft_spawn(ctx, 0, 0);
}
