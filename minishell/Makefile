# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 19:05:09 by jaeywon           #+#    #+#              #
#    Updated: 2023/01/20 02:22:07 by suhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS =

# readline 추가
LINKING_READLINE_FLAGS = -lreadline -L/opt/homebrew/opt/readline/lib
COMFILE_READLINE_FLAGS = -I/opt/homebrew/opt/readline/include

SRC_DIR = ./src
LIBFT_DIR = ./libft

SRC_FILE = main.c \
	  push_back_token.c \
	  push_front_token.c \
	  push_back_env.c \
	  push_front_env.c \
	  push_back_unlink.c \
	  push_front_unlink.c \
	  init.c \
	  save_env.c \
	  parse.c \
	  split_token.c \
	  get_env.c \
	  free_token.c \
	  ft_token_parse.c \
	  ft_pipe.c \
	  ft_dup2.c \
	  ft_close.c \
	  check_redirection.c \
	  redir_r.c \
	  redir_l.c \
	  redir_append.c \
	  arg_utils.c \
	  arg_utils2.c \
	  del_token.c \
	  heredoc.c	\
	  heredoc_utils.c \
	  unlink.c \
	  ft_env.c \
	  ft_echo.c \
	  ft_export.c \
	  ft_unset.c \
	  ft_pwd.c \
	  ft_exit.c \
	  path.c \
	  add_change_export.c \
	  change_list_to_arr_env.c \
	  check_builtin.c \
	  exe_builtin.c \
	  exe_single_cmd.c \
	  ft_export_solo.c \
	  ft_cd.c \
	  cd_utils.c \
	  signal.c \
	  terminal.c \
	  error.c \
	  free_unlink.c \
	  utils.c \
	  is_redir.c \
	  split_token_utils.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ = $(SRC:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft $(LINKING_READLINE_FLAGS) -o $@ $^ 

%.o: %.c
	@$(CC) $(CFLAGS) $(COMFILE_READLINE_FLAGS) -c $^ -o $@
	
clean:
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME) $(LIBFT)

re:	fclean all

.PHONY = all, clean, fclean, re
