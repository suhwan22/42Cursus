/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:52:53 by suhkim            #+#    #+#             */
/*   Updated: 2022/10/07 02:37:45 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_info(t_info *info)
{
	info->width = 0;
	info->height = 0;
	info->count_c = 0;
	info->count_e = 0;
	info->count_p = 0;
}

char	**save_map(char *title, t_game *game)
{
	int		fd;
	int		i;
	char	**map;

	i = 0;
	fd = open(title, O_RDONLY);
	if (fd < 0)
		return (0);
	map = malloc(sizeof(char *) * game->info.height);
	while (i < game->info.height)
		map[i++] = get_next_line(fd);
	return (map);
}

void	game_init(t_game *game)
{
	game->player = 1;
	game->mov = 0;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
			(game->info.width) * 32, (game->info.height) * 32, "so_long");
}

int	exit_game(int keycode, t_game *game)
{
	(void) keycode;
	(void) game;
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_info(&(game.info));
	pos_init(&(game.pos));
	if (argc != 2)
		return (print_error(NULL));
	else
	{
		if (!valid_map(argv[1], &game))
			return (0);
		game.map = save_map(argv[1], &game);
		game_init(&game);
		draw(&game);
		mlx_hook(game.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &game);
		mlx_hook(game.win_ptr, 17, 0, &exit_game, &game);
		mlx_loop(game.mlx_ptr);
	}
	return (0);
}
