/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dialog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 15:00:52 by mpillet           #+#    #+#             */
/*   Updated: 2015/03/01 15:47:51 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void			st_line(int y, int x, int len)
{
	int			tmp;

	wattrset(stdscr, COLOR_PAIR(1));
	tmp = x - 1;
	while (tmp++ < x + len)
		mvprintw(y, tmp, " ");
	wattroff(stdscr, COLOR_PAIR(1));
}

static void			st_title(int y, int x, int len, char *title)
{
	int		tmp;

	wattrset(stdscr, COLOR_PAIR(5));
	tmp = x - 1;
	while (tmp++ < x + len)
		mvprintw(y, tmp, " ");
	mvprintw(y, x + len / 2, "%s", title);
	wattroff(stdscr, COLOR_PAIR(5));
}

static void			st_draw_box(int x, int y, int len)
{
	int		tmp;

	st_title(y, x, len, "2048");
	st_line(y + 1, x, len);
	st_line(y + 2, x, len);
	st_line(y + 3, x, len);
	st_line(y + 4, x, len);
	st_line(y + 5, x, len);
	wattrset(stdscr, COLOR_PAIR(4));
	mvprintw(y + 1, x + len + 1, " ");
	mvprintw(y + 2, x + len + 1, " ");
	mvprintw(y + 3, x + len + 1, " ");
	mvprintw(y + 4, x + len + 1, " ");
	mvprintw(y + 5, x + len + 1, " ");
	tmp = x;
	while (tmp++ < x + len + 1)
		mvprintw(y + 6, tmp, " ");
	wattroff(stdscr, COLOR_PAIR(4));
	refresh();
}

static void			st_draw(char *msg, char *opt)
{
	int		x;
	int		y;
	int		len;

	len = ft_strlen(opt) + 10 > ft_strlen(msg)
		? ft_strlen(opt) + 12 : ft_strlen(msg) + 2;
	x = COLS / 2 - len / 2;
	y = LINES / 2 - 3;
	st_draw_box(x, y, len);
	wattrset(stdscr, COLOR_PAIR(1));
	mvprintw(y + 2, x + 1, "%s", msg);
	mvprintw(y + 4, x + 1, "<ENTER> : %s", opt);
	wattroff(stdscr, COLOR_PAIR(1));
}

void				ft_dialog(char *msg, char *opt)
{
	int		key;

	st_draw(msg, opt);
	while ((key = getch()) != 27)
	{
		if (key == KEY_RESIZE)
		{
			clear();
			st_draw(msg, opt);
		}
		if (key == 10)
			break ;
	}
}
