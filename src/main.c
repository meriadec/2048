/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:21:00 by bgronon           #+#    #+#             */
/*   Updated: 2015/02/28 18:30:34 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <time.h>

static void		st_init_colors(void)
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_WHITE, COLOR_YELLOW);
	init_pair(3, COLOR_WHITE, COLOR_GREEN);
	init_pair(4, COLOR_WHITE, COLOR_CYAN);
	init_pair(5, COLOR_WHITE, COLOR_BLUE);
	init_pair(6, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(7, COLOR_WHITE, COLOR_RED);
	init_pair(8, COLOR_WHITE, COLOR_WHITE);
	init_pair(9, COLOR_WHITE, COLOR_WHITE);
	init_pair(10, COLOR_WHITE, COLOR_WHITE);
	init_pair(11, COLOR_WHITE, COLOR_WHITE);
}

static int		st_init(t_ctx *ctx, int i)
{
	if (!initscr())
		return (ft_error("Can't init screen"));
	st_init_colors();
	ctx->size = 4;
	ctx->map = (int *)malloc((ctx->size * ctx->size) * sizeof(*ctx->map));
	while (i < ctx->size * ctx->size)
	{
		ctx->map[i] = 0;
		++i;
	}
	ctx->mov[0] = 0;
	ctx->mov[1] = 0;
	ctx->moved = 0;
	srand(time(NULL));
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	return (0);
}

static int		st_has_enough_size(t_ctx *ctx)
{
	return (COLS / ctx->size >= MIN_CELL_W && LINES / ctx->size >= MIN_CELL_H);
}

static void		st_loop(t_ctx *ctx)
{
	int		key;

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

int				main(int ac, char **av)
{
	t_ctx	*ctx;

	if (!(ctx = (t_ctx *)malloc(sizeof(t_ctx))))
		return (ft_error("Can't malloc 'ctx'"));
	if (-1 == st_init(ctx, 0))
		return (ft_error("Init failed"));
	if (ac == 3 && ft_strequ(av[1], "--mock"))
		ft_mock(ctx, av[2]);
	ft_spawn(ctx, 0, 0);
	ft_draw(ctx);
	st_loop(ctx);
	endwin();
	free(ctx);
	return (0);
}
