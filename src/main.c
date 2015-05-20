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
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
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
	init_pair(12, COLOR_BLACK, COLOR_BLACK);
	init_pair(13, COLOR_BLUE, COLOR_BLACK);
}

static int		st_init(t_ctx *ctx, int i)
{
	ctx->size = NB_CELLS;
	if (ctx->size < 3 || ctx->size > 10)
		return (ft_error("Ahaha nice try."));
	if (!ft_ispowertwo(WIN_VALUE))
		return (ft_error("The win value is not a power of two."));
	if (!initscr())
		return (ft_error("Can't init screen"));
	st_init_colors();
	ctx->map = (int *)malloc((ctx->size * ctx->size) * sizeof(*ctx->map));
	while (i++ < ctx->size * ctx->size)
		ctx->map[i] = 0;
	ctx->mov[0] = 0;
	ctx->mov[1] = 0;
	ctx->moved = 0;
	ctx->win = 0;
	ctx->score = 0;
	srand(time(NULL));
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	return (0);
}

int				main(int ac, char **av)
{
	t_ctx	*ctx;

	if (!(ctx = (t_ctx *)malloc(sizeof(t_ctx))))
		return (ft_error("Can't malloc 'ctx'"));
	if (-1 == st_init(ctx, -1))
	{
		free(ctx);
		return (-1);
	}
	if (ac == 3 && ft_strequ(av[1], "--mock"))
		ft_mock(ctx, av[2]);
	ft_menu(ctx);
	ft_finish(ctx);
	return (0);
}
