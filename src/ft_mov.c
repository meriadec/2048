/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:31:32 by bgronon           #+#    #+#             */
/*   Updated: 2015/02/28 14:55:21 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	ft_down(t_ctx *ctx)
{
	ctx->mov[0] = 0;
	ctx->mov[1] = 1;
	mvprintw(0, 0, "DOWN");
}

void	ft_up(t_ctx *ctx)
{
	ctx->mov[0] = 0;
	ctx->mov[1] = -1;
	mvprintw(0, 0, "UP");
}

void	ft_left(t_ctx *ctx)
{
	ctx->mov[0] = -1;
	ctx->mov[1] = 0;
	mvprintw(0, 0, "LEFT");
}

void	ft_right(t_ctx *ctx)
{
	ctx->mov[0] = 1;
	ctx->mov[1] = 0;
	mvprintw(0, 0, "RIGHT");
}

void	ft_mov(t_ctx *ctx, int key)
{
	void (*p[4])(t_ctx *ctx);

	if (!(key >= 258 && key <= 261))
		return ;
	p[0] = ft_down;
	p[1] = ft_up;
	p[2] = ft_left;
	p[3] = ft_right;
	(*p[key - 258])(ctx);
	ft_gravit(ctx);
}
