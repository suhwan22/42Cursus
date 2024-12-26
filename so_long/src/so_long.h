/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:13:20 by suhkim            #+#    #+#             */
/*   Updated: 2022/10/07 02:29:28 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define X_EVENT_KEY_PRESS 2
# define KEY_W 13   
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_pos
{
	int	x;
	int	y;
	int	keycode;
}	t_pos;

typedef struct s_info
{
	int	width;
	int	height;
	int	count_c;
	int	count_e;
	int	count_p;
}	t_info;

typedef struct s_image
{
	void	*wall;
	void	*tile;
	void	*coin;
	void	*player;
	void	*player2;
	void	*exit;
	void	*clear;
}	t_img;

typedef struct s_game
{
	struct s_info	info;
	struct s_pos	pos;
	struct s_image	img;
	int				player;
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	int				mov;
}	t_game;

void	draw(t_game *game);
int		valid_mid(t_info *tmp, char *str, int len);
int		valid_first(char *str, int len);
int		valid_map(char *title, t_game *game);
void	init_info(t_info *tmp);
char	*get_next_line(int fd);
char	*read_line(int fd, char *backup);
char	*return_right(char *backup);
char	*return_left(char *backup);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		key_press(int keycode, t_game *game);
void	pos_init(t_pos *pos);
void	valid_move(t_game *game);
void	back_pos(t_game *game);
char	*ft_itoa(int n);
int		print_error(char *buf);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_putnbr_base_printf(unsigned long nbr, char *base,
			int len, int *bytes);
int		ft_printf(const char *format, ...);

#endif
