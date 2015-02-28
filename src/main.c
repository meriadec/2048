/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:21:00 by bgronon           #+#    #+#             */
/*   Updated: 2015/02/28 13:25:34 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <time.h>

void	ft_init (t_ctx * ctx, int i)
{
	if (!initscr()) {
		ft_error("Init failed");
	}
	ctx->size = 4;
	ctx->map = (int *) malloc((ctx->size * ctx->size) * sizeof(*ctx->map));
	while (i < ctx->size * ctx->size)
	{
		ctx->map[i] = 0;
		++i;
	}
	ctx->mov[0] = 0;
	ctx->mov[1] = 0;
	srand(time(NULL));
	keypad(stdscr, TRUE);
	curs_set(0);
}

int		main(void)
{
	t_ctx	* ctx;
	int		key;

	if (!(ctx = (t_ctx *) malloc(sizeof(t_ctx))))
		ft_error("Can't malloc 'ctx'");
	ft_init(ctx, 0);
	ft_draw(ctx);
	while ((key = getch()) != 27) {
		if (key == KEY_RESIZE) {
			mvprintw(0, 0, "Col %d Line %d", COLS, LINES);
			refresh();
		}
		ft_mov(ctx, key);
		ft_draw(ctx);
	}
	endwin();
	free(ctx);
	return (0);
}
