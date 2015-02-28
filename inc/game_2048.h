/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:21:00 by bgronon           #+#    #+#             */
/*   Updated: 2015/02/28 18:29:55 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include "libft.h"
# include <ncurses.h>
# include <stdlib.h>

/**
** Defines
*/
# define MIN_CELL_W		15
# define MIN_CELL_H		5
# define MAP			ctx->map
# define SIZ			ctx->size

# define TCTR_Y		(n/ctx->size)*ch+2+(ch-3)/2
# define TCL		ft_strlen(ft_itoa(ctx->map[n]))
# define TCTR_X		(n%ctx->size)*cw+3+(cw-6)/2-(TCL+2)/2

enum	e_const
{
	WIN_VALUE = 2048
};

typedef struct	s_ctx
{
	int			size;
	int			* map;
	int			mov[2];
	int			moved;
}				t_ctx;

/**
** Prototypes
*/

/**
** ft_draw
*/
void			ft_draw (t_ctx * ctx);

/**
** errors
*/
int				ft_error (char * msg);

/**
** ft_mov.c
*/
int				ft_mov (t_ctx * ctx, int key);

/**
** ft_game.c
*/
void			ft_spawn (t_ctx * ctx, int i, int av);
int				ft_check_lock(t_ctx *ctx, int i, int av);

/**
** ft_utils.c
*/
int				ft_ispowertwo (unsigned int x);
int				ft_getpowexposant (int x);
void			ft_reset_tile (t_ctx *ctx, int n);

/**
** ft_mock
*/
int				ft_mock(t_ctx *ctx, char *filename);

/**
** ft_finish
*/
void			ft_finish(t_ctx *ctx);

/**
** ft_loop
*/
void			ft_loop(t_ctx *ctx);

#endif
