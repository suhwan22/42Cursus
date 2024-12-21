# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 23:30:42 by suhkim            #+#    #+#              #
#    Updated: 2024/12/17 23:36:58 by suhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE = 42
NAME = libgnl.a
SRCS = ./src/get_next_line.c \
	   ./src/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -o $@ -c $<

$(NAME): $(OBJS)
	ar rcs $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
