/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 11:50:49 by mpillet           #+#    #+#             */
/*   Updated: 2015/03/01 14:16:35 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		st_showbox(char *msg, int x, int y)
{
	int		x1;
	int		y1;
	int		len;

	x = COLS / 2 - ft_strlen(msg) / 2 - 1;
	y = LINES / 2 - 1;
	x1 = x - 1;
	y1 = y;
	len = ft_strlen(msg);
	wattrset(stdscr, COLOR_PAIR(1));
	while ((x1 - x) < len + 1)
	{
		mvprintw(y - 1, x1, " ");
		mvprintw(y + 1, x1, " ");
		++x1;
	}
	mvprintw(y, x - 1, " %s ", msg);
	wattroff(stdscr, COLOR_PAIR(1));
	mvprintw(y + 3, x - 1, "<ENTER>    Start the game");
	mvprintw(y + 4, x - 1, "<ECHAP>    Quit");
	refresh();
}

void			ft_menu(t_ctx *ctx)
{
	char	*msg;
	int		key;

	clear();
	msg = ft_strdup("    WELCOME TO 2042    ");
	st_showbox(msg, 0, 0);
	while ((key = getch()) != 27)
	{
		if (key == KEY_RESIZE)
			st_showbox(msg, 0, 0);
		if (key == 10)
		{
			ft_loop(ctx);
			break ;
		}
	}
	ft_memdel((void **)&msg);
	if (key == 27)
		ft_finish(ctx);
}
