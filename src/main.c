/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:21:00 by bgronon           #+#    #+#             */
/*   Updated: 2015/02/28 12:01:24 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <stdlib.h>

int main(void)
{
	t_ctx	* ctx;

	if (!(ctx = (t_ctx *) malloc(sizeof(t_ctx))))
		ft_error("Can't malloc 'ctx'");

	if (!initscr()) {
		ft_putendl("Init failed");
	}

	keypad(stdscr, TRUE);

	int key;
	while ((key = getch()) != 27) {
		if (key == KEY_RESIZE) {
			clear();
			mvprintw(0, 0, "Col %d Line %d", COLS, LINES);
			refresh();
		}
		if (key == KEY_UP) {
			mvprintw(0, 0, "PUTE");
			refresh();
		}

	}

	endwin();
	free(ctx);

	return (0);
}
