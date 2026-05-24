# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/23 22:59:04 by frodrig2          #+#    #+#              #
#    Updated: 2026/05/24 01:13:36 by frodrig2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = .
SRCS = $(shell find $(SRCS_DIR) -name '*.c')
OBJS = $(SRCS:.c=.o)

DEBUG ?= $(or $(filter %.c, $(MAKECMDGOALS)), ft_printf.c)
D_OUT = debug

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

ifneq ($(filter %.c, $(MAKECMDGOALS)),)
	%.c: ;
endif

debug:
	$(CC) -g $(DEBUG) $(NAME) -o $(D_OUT)
	$(MAKE) fclean

dclean: fclean
	rm -f $(D_OUT)

.PHONY: all clean fclean re debug dclean
