/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 15:08:32 by bgronon           #+#    #+#             */
/*   Updated: 2015/03/01 15:41:53 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <fcntl.h>
#include <unistd.h>

void	ft_save_highscore(t_ctx *ctx)
{
	int		fd;
	char	*score;
	char	*login;

	if (ctx->score <= 0)
		return ;
	fd = open("scores.txt", O_WRONLY | O_APPEND | O_CREAT, 0666);
	if (fd != -1)
	{
		score = ft_itoa(ctx->score);
		login = getlogin();
		ft_putstr_fd(login ? login : "Anonymous", fd);
		ft_putstr_fd(" ", fd);
		ft_putendl_fd(score, fd);
		free(score);
		close(fd);
	}
}

void	ft_show_highscore(void)
{
	int		i;
	int		fd;
	char	*line;

	clear();
	i = 2;
	fd = open("scores.txt", O_RDONLY);
	wattrset(stdscr, COLOR_PAIR(13));
	mvprintw(LINES / 2 - 10, COLS / 2 - 15, "SCORES");
	wattroff(stdscr, COLOR_PAIR(1));
	if (fd != -1)
	{
		while (get_next_line(fd, &line) && i <= 10)
		{
			mvprintw(LINES / 2 - 10 + i, COLS / 2 - 15, line);
			++i;
			free(line);
		}
	}
	while (i++ <= 10)
		mvprintw(LINES / 2 - 10 + i - 1, COLS / 2 - 15, "-");
	close(fd);
	mvprintw(LINES / 2 - 10 + 12, COLS / 2 - 15, "<ENTER>    Start the game");
	mvprintw(LINES / 2 - 10 + 13, COLS / 2 - 15, "<ECHAP>    Quit");
	refresh();
}
