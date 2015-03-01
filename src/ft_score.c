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

	fd = open("highscores.zavattas", O_WRONLY | O_APPEND | O_CREAT, 0666);
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
