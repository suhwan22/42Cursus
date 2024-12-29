# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 00:33:00 by suhkim            #+#    #+#              #
#    Updated: 2022/11/13 21:25:19 by suhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = gcc
CFLAGS = -Werror -Wall -Wextra

SRC = ./src/exec.c \
		./src/cal.c \
		./src/utils.c \
		./src/stack.c \
		./src/sort.c \
		./src/error.c \
		./src/command.c \
	  ./src/divide.c \
	  ./src/init_info.c \
	  ./src/greedy_sort.c \
	  ./src/main.c


BONUS_SRC = ./bonus/checker_bonus.c \
		./bonus/command_bonus.c \
		./bonus/error_bonus.c \
		./bonus/exe_str_op_bonus.c \
		./bonus/init_info_bonus.c \
		./bonus/stack_bonus.c \
		./bonus/utils_bonus.c \
		./bonus/valid_bonus.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
RM = rm -f

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	$(CC) $(CFLAGS) -o $@ $^ -L./libft -lft

$(BONUS_NAME): $(BONUS_OBJ)
	@make -C ./libft
	@make -C ./gnl
	$(CC) $(CFLAGS) -o $@ $^ -L./libft -lft -L./gnl -lgnl

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@$(RM) $(OBJ)
	@$(RM) $(BONUS_OBJ)
	@make -C ./libft clean
	@make -C ./gnl clean

fclean: clean
	@make -C ./libft fclean
	@make -C ./gnl fclean
	@$(RM) $(NAME) $(BONUS_NAME)

re:	fclean all

.PHONY:all clean fclean re bonus
