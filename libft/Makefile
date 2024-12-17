# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 14:00:57 by suhkim            #+#    #+#              #
#    Updated: 2022/03/27 16:53:02 by suhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ./src/ft_atoi.c \
	   ./src/ft_bzero.c \
	   ./src/ft_calloc.c \
	   ./src/ft_isalnum.c \
	   ./src/ft_isalpha.c \
	   ./src/ft_isascii.c \
	   ./src/ft_isdigit.c \
	   ./src/ft_isprint.c \
	   ./src/ft_itoa.c \
	   ./src/ft_memchr.c \
	   ./src/ft_memcmp.c \
	   ./src/ft_memcpy.c \
	   ./src/ft_memmove.c \
	   ./src/ft_memset.c \
	   ./src/ft_striteri.c \
	   ./src/ft_putchar_fd.c \
	   ./src/ft_putendl_fd.c \
	   ./src/ft_putnbr_fd.c \
	   ./src/ft_putstr_fd.c \
	   ./src/ft_split.c \
	   ./src/ft_strchr.c \
	   ./src/ft_strdup.c \
	   ./src/ft_strjoin.c \
	   ./src/ft_strlcat.c \
	   ./src/ft_strlcpy.c \
	   ./src/ft_strlen.c \
	   ./src/ft_strmapi.c \
	   ./src/ft_strncmp.c \
	   ./src/ft_strnstr.c \
	   ./src/ft_strrchr.c \
	   ./src/ft_strtrim.c \
	   ./src/ft_substr.c \
	   ./src/ft_tolower.c \
	   ./src/ft_toupper.c
SRCS_BONUS = ./src/ft_lstadd_back.c \
			 ./src/ft_lstadd_front.c \
			 ./src/ft_lstclear.c \
			 ./src/ft_lstdelone.c \
			 ./src/ft_lstiter.c \
			 ./src/ft_lstlast.c \
			 ./src/ft_lstmap.c \
			 ./src/ft_lstnew.c \
			 ./src/ft_lstsize.c
OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)  

ifdef WITH_BONUS
	OBJS_TARGET = $(OBJS) $(OBJS_BONUS)
else
	OBJS_TARGET = $(OBJS)
endif

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS_TARGET)
	ar rcs $@ $^

bonus:
	make WITH_BONUS=1 all

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
