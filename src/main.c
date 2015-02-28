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

static void		st_init_colors(void)
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_GREEN);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLUE);
	init_pair(5, COLOR_RED, COLOR_BLACK);
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
	srand(time(NULL));
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	return (0);
}

int				main(int ac, char **av)
{
	t_ctx	*ctx;
	int		key;

	if (!(ctx = (t_ctx *)malloc(sizeof(t_ctx))))
		return (ft_error("Can't malloc 'ctx'"));
	if (-1 == st_init(ctx, 0))
		return (ft_error("Init failed"));
	if (ac == 3 && ft_strequ(av[1], "--mock"))
		ft_mock(ctx, av[2]);
	ft_draw(ctx);
	while ((key = getch()) != 27)
	{
		if (key == KEY_RESIZE)
		{
			mvprintw(0, 0, "Col %d Line %d", COLS, LINES);
			ft_draw(ctx);
		}
		ft_mov(ctx, key);
		ft_draw(ctx);
	}
	endwin();
	free(ctx);
	return (0);
}
