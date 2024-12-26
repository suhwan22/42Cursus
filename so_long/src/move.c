/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:03:28 by suhkim            #+#    #+#             */
/*   Updated: 2022/10/07 01:26:45 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_move(t_game *game)
{
	if (game->map[game->pos.y][game->pos.x] == 'C')
	{
		(game->info.count_c)--;
		game->map[game->pos.y][game->pos.x] = '0';
		(game->mov)++;
	}
	else if (game->map[game->pos.y][game->pos.x] == '1')
		back_pos(game);
	else if (game->map[game->pos.y][game->pos.x] == 'E')
	{
		if (game->info.count_c == 0)
		{
			(game->mov)++;
			game->player = 0;
		}
		else
			back_pos(game);
	}
	else
		(game->mov)++;
	ft_printf("move : %d\n", game->mov);
	if (game->player == 0)
		ft_printf("CLEAR\n");
}

void	back_pos(t_game *game)
{
	if (game->pos.keycode == KEY_W)
		(game->pos.y)++;
	else if (game->pos.keycode == KEY_S)
		(game->pos.y)--;
	else if (game->pos.keycode == KEY_A)
		(game->pos.x)++;
	else if (game->pos.keycode == KEY_D)
		(game->pos.x)--;
	else if (game->pos.keycode == KEY_ESC)
		exit(0);
}
