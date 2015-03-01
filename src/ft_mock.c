/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:15:40 by mpillet           #+#    #+#             */
/*   Updated: 2015/02/28 14:47:19 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <fcntl.h>
#include <unistd.h>

static void		st_acquire(t_ctx *ctx, int y, char **cells)
{
	char	**tmp;
	int		x;

	tmp = cells;
	x = 0;
	while (*tmp && x < ctx->size)
	{
		ctx->map[y * ctx->size + x] = ft_atoi(*tmp);
		++tmp;
		++x;
	}
}

int				ft_mock(t_ctx *ctx, char *filename)
{
	char		*line;
	char		**cells;
	int			fd;
	int			y;

	if (-1 == (fd = open(filename, O_RDONLY)))
	{
		return (1);
	}
	y = 0;
	while (get_next_line(fd, &line) && y < ctx->size)
	{
		cells = ft_str_super_split(line);
		st_acquire(ctx, y, cells);
		ft_free_tab((void ***)&cells);
		ft_memdel((void **)&line);
		++y;
	}
	if (-1 == close(fd))
	{
		return (1);
	}
	return (0);
}
