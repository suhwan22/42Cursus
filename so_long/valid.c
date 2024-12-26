/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:06:55 by suhkim            #+#    #+#             */
/*   Updated: 2022/10/07 01:28:58 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	print_error(char *buf)
{
	if (buf)
		free(buf);
	buf = 0;
	ft_printf("Error\n");
	return (0);
}

int	valid_wall(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	valid_mid(t_info *info, char *str, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (str[i] == 'C')
		{
			(info->count_c)++;
			continue ;
		}
		if (str[i] == 'E')
		{
			(info->count_e)++;
			continue ;
		}
		if (str[i] == 'P')
		{
			(info->count_p)++;
			continue ;
		}
		if (str[i] != '0' && str[i] != '1')
			return (0);
	}
	return (1);
}

int	check_map(int fd, t_game *game)
{
	char	*buf;
	char	*temp_buf;

	buf = get_next_line(fd);
	while (buf)
	{
		if (game->info.width != ft_strlen(buf) - 1 || \
				buf[0] != '1' || buf[ft_strlen(buf) - 2] != '1' || \
				!(valid_mid(&(game->info), buf, ft_strlen(buf) - 1)))
					return (print_error(buf));
		game->info.height++;
		temp_buf = buf;
		buf = get_next_line(fd);
		if (!buf)
		{
			if (!valid_wall(temp_buf, game->info.width))
				return (print_error(temp_buf));
		}
		free(temp_buf);
	}
	if (!(game->info.count_c && game->info.count_e && game->info.count_p))
		return (print_error(NULL));
	game->info.height++;
	return (1);
}

int	valid_map(char *title, t_game *game)
{
	int		fd;
	char	*buf;

	if (!ft_strnstr(title, ".ber", 1000))
		return (print_error(NULL));
	else
	{
		fd = open(title, O_RDONLY);
		if (fd < 0)
			return (0);
		buf = get_next_line(fd);
		if (!buf)
			return (print_error(buf));
		if (!valid_wall(buf, game->info.width))
			return (print_error(buf));
		game->info.width = ft_strlen(buf) - 1;
		free(buf);
		if (!check_map(fd, game))
			return (0);
		close(fd);
	}
	return (1);
}
