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
	while (x < SIZ)
	{
		y = 1;
		while (y < SIZ)
		{
			tmp = y - 1;
			while (MAP[tmp * SIZ + x] == 0 && tmp > 0)
				--tmp;
			if (MAP[tmp * SIZ + x] == 0)
			{
				ft_move_tile(ctx, tmp * SIZ + x, MAP[y * SIZ + x]);
				ft_reset_tile(ctx, y * SIZ + x);
			}
			else if ((MAP[tmp * SIZ + x] == MAP[y * SIZ + x]) || (tmp != y - 1))
			{
				if (MAP[tmp * SIZ + x] == MAP[y * SIZ + x])
					ft_fusion_tile(ctx, tmp * SIZ + x, MAP[y * SIZ + x]);
				else if (tmp != y - 1)
					ft_move_tile(ctx, (tmp + 1) * SIZ + x, MAP[y * SIZ + x]);
				ft_reset_tile(ctx, y * SIZ + x);
			}
			++y;
		}
		++x;
	}
}

void	ft_down(t_ctx *ctx, int x, int y, int tmp)
{
	while (x < SIZ)
	{
		y = SIZ - 2;
		while (y >= 0)
		{
			tmp = y + 1;
			while (MAP[tmp * SIZ + x] == 0 && tmp < SIZ - 1)
				++tmp;
			if (MAP[tmp * SIZ + x] == 0)
			{
				ft_move_tile(ctx, tmp * SIZ + x, MAP[y * SIZ + x]);
				ft_reset_tile(ctx, y * SIZ + x);
			}
			else if ((MAP[tmp * SIZ + x] == MAP[y * SIZ + x]) || (tmp != y + 1))
			{
				if (MAP[tmp * SIZ + x] == MAP[y * SIZ + x])
					ft_fusion_tile(ctx, tmp * SIZ + x, MAP[y * SIZ + x]);
				else if (tmp != y + 1)
					ft_move_tile(ctx, (tmp - 1) * SIZ + x, MAP[y * SIZ + x]);
				ft_reset_tile(ctx, y * SIZ + x);
			}
			--y;
		}
		++x;
	}
}

void	ft_left(t_ctx *ctx, int x, int y, int tmp)
{
	while (y < SIZ)
	{
		x = 1;
		while (x < SIZ)
		{
			tmp = x - 1;
			while (MAP[y * SIZ + tmp] == 0 && tmp > 0)
				--tmp;
			if (MAP[y * SIZ + tmp] == 0)
			{
				ft_move_tile(ctx, y * SIZ + tmp, MAP[y * SIZ + x]);
				ft_reset_tile(ctx, y * SIZ + x);
			}
			else if ((MAP[y * SIZ + tmp] == MAP[y * SIZ + x]) || (tmp != x - 1))
			{
				if (MAP[y * SIZ + tmp] == MAP[y * SIZ + x])
					ft_fusion_tile(ctx, y * SIZ + tmp, MAP[y * SIZ + x]);
				else if (tmp != x - 1)
					ft_move_tile(ctx, y * SIZ + tmp + 1, MAP[y * SIZ + x]);
				ft_reset_tile(ctx, y * SIZ + x);
			}
			++x;
		}
		++y;
	}
}

void	ft_right(t_ctx *ctx, int x, int y, int tmp)
{
	while (y < SIZ)
	{
		x = SIZ - 2;
		while (x >= 0)
		{
			tmp = x + 1;
			while (MAP[y * SIZ + tmp] == 0 && tmp < SIZ - 1)
				++tmp;
			if (MAP[y * SIZ + tmp] == 0)
			{
				ft_move_tile(ctx, y * SIZ + tmp, MAP[y * SIZ + x]);
				ft_reset_tile(ctx, y * SIZ + x);
			}
			else if ((MAP[y * SIZ + tmp] == MAP[y * SIZ + x]) || (tmp != x + 1))
			{
				if (MAP[y * SIZ + tmp] == MAP[y * SIZ + x])
					ft_fusion_tile(ctx, y * SIZ + tmp, MAP[y * SIZ + x]);
				else if (tmp != x + 1)
					ft_move_tile(ctx, y * SIZ + tmp - 1, MAP[y * SIZ + x]);
				ft_reset_tile(ctx, y * SIZ + x);
			}
			--x;
		}
		++y;
	}
}

int		ft_mov(t_ctx *ctx, int key)
{
	void (*p[4])(t_ctx *ctx, int x, int y, int tmp);

	if (!(key >= 258 && key <= 261))
		return (1);
	if (!ft_check_lock(ctx, 0))
	{
		ft_dialog("You loose, bro.", "Quit");
		return (0);
	}
	p[0] = ft_down;
	p[1] = ft_up;
	p[2] = ft_left;
	p[3] = ft_right;
	(*p[key - 258])(ctx, 0, 0, 0);
	if (ctx->moved)
		ft_spawn(ctx, 0, 0);
	ctx->moved = 0;
	if (!ctx->win)
		ft_check_win(ctx, 0);
	return (1);
}
