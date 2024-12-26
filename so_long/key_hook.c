/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:01:47 by suhkim            #+#    #+#             */
/*   Updated: 2022/10/06 20:02:55 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pos_init(t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
}

int	key_press(int keycode, t_game *game)
{
	if (game->player == 1)
	{
		if (keycode == KEY_W)
			(game->pos.y)--;
		else if (keycode == KEY_S)
			(game->pos.y)++;
		else if (keycode == KEY_A)
			(game->pos.x)--;
		else if (keycode == KEY_D)
			(game->pos.x)++;
		else if (keycode == KEY_ESC)
			exit(0);
		else
			return (0);
		game->pos.keycode = keycode;
		valid_move(game);
		draw(game);
	}
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
