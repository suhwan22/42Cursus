/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:53:36 by suhkim            #+#    #+#             */
/*   Updated: 2022/10/07 01:03:20 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_image(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"./image/wall.xpm", &img_width, &img_height);
	game->img.tile = mlx_xpm_file_to_image(game->mlx_ptr,
			"./image/tile.xpm", &img_width, &img_height);
	game->img.coin = mlx_xpm_file_to_image(game->mlx_ptr,
			"./image/coffee.xpm", &img_width, &img_height);
	game->img.player = mlx_xpm_file_to_image(game->mlx_ptr,
			"./image/empty_cup.xpm", &img_width, &img_height);
	game->img.player2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./image/pull_cup.xpm", &img_width, &img_height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"./image/exit.xpm", &img_width, &img_height);
	game->img.clear = mlx_xpm_file_to_image(game->mlx_ptr,
			"./image/clear.xpm", &img_width, &img_height);
}

void	print_map(t_game *game, int i, int j, int flag)
{
	int	bit;

	bit = 32;
	if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.coin, j * bit, i * bit);
	if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.exit, j * bit, i * bit);
	if (game->map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.tile, j * bit, i * bit);
		if (flag == 0)
		{
			game->pos.x = j;
			game->pos.y = i;
		}
	}
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.wall, j * bit, i * bit);
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.tile, j * bit, i * bit);
}

void	print_player(t_game *game)
{
	if (game->player == 1)
	{
		if (game->info.count_c)
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.player, game->pos.x * 32, game->pos.y * 32);
		else
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.player2, game->pos.x * 32, game->pos.y * 32);
	}
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.clear, game->pos.x * 32, game->pos.y * 32);
}

void	draw(t_game *game)
{
	int			i;
	int			j;
	static int	flag;

	set_image(game);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	i = 0;
	j = 0;
	while (i < game->info.height)
	{	
		while (j < game->info.width)
		{
			print_map(game, i, j, flag);
			j++;
		}
		j = 0;
		i++;
	}
	flag = 1;
	print_player(game);
}
