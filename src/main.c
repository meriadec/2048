/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:21:00 by bgronon           #+#    #+#             */
/*   Updated: 2015/02/28 12:39:11 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <stdlib.h>

void	ft_init (t_ctx * ctx, int i)
{
	ctx->size = 4;
	ctx->map = (int *) malloc((ctx->size * ctx->size) * sizeof(*ctx->map));
	while (i < ctx->size * ctx->size)
	{
		ctx->map[i] = 0;
		++i;
	}
	ctx->mov[0] = 0;
	ctx->mov[1] = 0;
}

int main(void)
{
	t_ctx	* ctx;

	if (!(ctx = (t_ctx *) malloc(sizeof(t_ctx))))
		ft_error("Can't malloc 'ctx'");

	ft_init(ctx, 0);

	if (!initscr()) {
		ft_error("Init failed");
	}

	keypad(stdscr, TRUE);

	int key;
	while ((key = getch()) != 27) {
		clear();
		if (key == KEY_RESIZE) {
			mvprintw(0, 0, "Col %d Line %d", COLS, LINES);
			refresh();
		}
		ft_mov(ctx, key);
		refresh();
	}

	endwin();
	free(ctx);

	//printf(" pute %d %d %d %d\n", KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT);

	return (0);
}
