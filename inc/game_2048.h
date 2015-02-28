/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:21:00 by bgronon           #+#    #+#             */
/*   Updated: 2015/02/28 12:02:47 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include "libft.h"
# include <ncurses.h>

enum e_const
{
	WIN_VALUE = 2048
};

//enum keymap { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT };

typedef struct	s_ctx
{
	int			size;
	int			* map;
	int			mov[2];
}				t_ctx;

/**
** Prototypes
*/

void			ft_exit (int code);
void			ft_error (char * msg);

#endif
