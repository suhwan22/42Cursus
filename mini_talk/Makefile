# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 02:33:10 by suhkim            #+#    #+#              #
#    Updated: 2024/12/25 02:51:28 by suhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client
SERV_SRCS = ./src/server.c ./src/utils.c
CLIENT_SRCS = ./src/client.c ./src/utils.c
SERV_OBJS = $(SERV_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(SERVER): $(SERV_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(SERV_OBJS) $(CLIENT_OBJS)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re