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

SRC_DIR = ./src
BONUS_DIR = ./bonus
LIBFT_DIR = ./libft
GNL_DIR = ./gnl

SRC_FILE = exec.c \
		cal.c \
		utils.c \
		stack.c \
		sort.c \
		error.c \
		command.c \
	  divide.c \
	  init_info.c \
	  greedy_sort.c \
	  main.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILE))


BONUS_FILE = checker_bonus.c \
		command_bonus.c \
		error_bonus.c \
		exe_str_op_bonus.c \
		init_info_bonus.c \
		stack_bonus.c \
		utils_bonus.c \
		valid_bonus.c

BONUS_SRC = $(addprefix $(BONUS_DIR)/, $(BONUS_FILE))

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
RM = rm -f

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(BONUS_NAME): $(BONUS_OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(GNL_DIR)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@$(RM) $(OBJ)
	@$(RM) $(BONUS_OBJ)
	@make -C $(LIBFT_DIR) clean
	@make -C $(GNL_DIR) clean

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(GNL_DIR) fclean
	@$(RM) $(NAME) $(BONUS_NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
