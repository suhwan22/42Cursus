# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 05:10:02 by suhkim            #+#    #+#              #
#    Updated: 2022/11/13 20:59:22 by suhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

CC	= cc
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line_bonus.c\
	  get_next_line_utils_bonus.c\
	  ft_strncmp_bonus.c\
	  ft_strtol_bonus.c\
	  ft_atoi_bonus.c

OBJ	= $(SRC:.c=.o)

$(NAME): $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $^
	@ar crsu $(NAME) $@

all: $(NAME)
		
clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re bonus
