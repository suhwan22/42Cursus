# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 01:11:54 by suhkim            #+#    #+#              #
#    Updated: 2024/12/27 01:40:41 by suhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long
CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror
MLX = ./mlx/libmlx.dylib
SRCS 	= ./main.c \
		  ./get_next_line.c \
		  ./get_next_line_utils.c \
		  ./ft_strnstr.c \
		  ./ft_memcmp.c \
		  ./ft_putnbr_base.c \
		  ./printf.c \
		  ./draw.c \
		  ./valid.c \
		  ./key_hook.c \
		  ./move.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(MLX)
	$(CC) -L./mlx -lmlx -framework Metal -framework MetalKit $^ -o $@
	install_name_tool -change libmlx.dylib ./mlx/libmlx.dylib so_long

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(MLX):
	make -C ./mlx

clean:
	rm -f $(OBJS)
	make -C ./mlx clean

fclean: clean
	rm -f $(NAME)
	make -C ./mlx fclean

re: fclean all

.PHONY: all clean fclean re
