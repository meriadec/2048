/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:21:00 by bgronon           #+#    #+#             */
/*   Updated: 2015/02/28 14:15:34 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include "libft.h"
# include <ncurses.h>
# include <stdlib.h>

enum	e_const
{
	WIN_VALUE = 2048
};

//typedef enum {KEY_UP = 0, KEY_DOWN, KEY_LEFT, KEY_RIGHT } keymap;

typedef struct	s_ctx
{
	int			size;
	int			* map;
	int			mov[2];
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
void			ft_mov (t_ctx * ctx, int key);

/**
** ft_game.c
*/
void			ft_gravit (t_ctx * ctx);
void			ft_spawn (t_ctx * ctx, int i, int av);


/**
** ft_utils.c
*/
int				ft_ispowertwo (unsigned int x);

/**
** ft_mock
*/
int				ft_mock(t_ctx *ctx, char *filename);

#endif
