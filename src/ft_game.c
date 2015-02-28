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
		exit(42);
		return ;
	}
	int random = rand() % av;
	ctx->map[tmp[random]] = 2;
}

/*
** Down : decrement, init (ctx->size * ctx->size - 1)
** Up   : increment, init (ctx->size + 1)
** Right:          , init (2, 3)
** Left :          , init (2, 1)
*/

void	ft_grav_down(t_ctx *ctx)
{
	int y;
	int x = 0;
	int tmp;

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
			else
			{
				if (ctx->map[tmp * ctx->size + x] == ctx->map[y * ctx->size + x])
				{
					ctx->map[tmp * ctx->size + x] = ctx->map[y * ctx->size + x] + ctx->map[y * ctx->size + x];
					ctx->map[y * ctx->size + x] = 0;
				}
				else if (tmp != y + 1)
				{
					ctx->map[(tmp - 1) * ctx->size + x] = ctx->map[y * ctx->size + x];
					ctx->map[y * ctx->size + x] = 0;
				}
			}
			--y;
		}
		++x;
	}



	/*
	n = 0;
	int	x = 1;
	int y = ctx->size - 1;
	while (x < ctx->size)
	{
		++x;
	}

	int y = n / ctx->size;
	int index;
	while (y < ctx->size - 2)
	{
		index = n + (y * ctx->size);
		if (ctx->map[index] != 0) {
			if (ctx->map[index] == ctx->map[n])
			{
				ctx->map[index] = ctx->map[n] * ctx->map[n];
				ctx->map[n] = 0;
				return ;
			}
			else if (n != index - ctx->size)
			{
				ctx->map[index - ctx->size] = ctx->map[n];
				ctx->map[n] = 0;
				return ;
			}
		}
		++y;
	}
	ctx->map[index] = ctx->map[n];
	ctx->map[n] = 0;
	*/
}

void	ft_gravit(t_ctx *ctx)
{
	int i = ctx->size * (ctx->size - 1);

	(void)i;
	ft_grav_down(ctx);
	/*
	while (i > 0)
	{
		if (!ctx->map[i] == 0) {

//			if (ctx->map[i + ctx->size] == ctx->map[i]) {
//				ctx->map[i + ctx->size] = ctx->map[i] * ctx->map[i];
//				ctx->map[i] = 0;
//			}

		}
		--i;
	}
	*/
	ft_spawn(ctx, 0, 0);
}
