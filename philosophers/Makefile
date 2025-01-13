# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhkim <suhkim@student.4seoul.kr>         +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 0/09/30 0:33:0 by suhkim            #+#    #+#                   #
#    Updated: 2022/12/14 13:05:57 by suhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Werror -Wall -Wextra

SRC_DIR = ./src

SRC_FILE = main.c \
	  check_valid_arg.c \
	  utils.c \
	  mutex.c \
	  init.c \
	  thread_philo.c \
	  philo.c \
	  philo_utils.c \
	  thread_monitor.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ = $(SRC:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
