# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/23 22:59:04 by frodrig2          #+#    #+#              #
#    Updated: 2026/05/25 00:45:44 by frodrig2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB_DIR = ./libft
SRCS_DIR = .

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(shell find $(SRCS_DIR) -maxdepth 1 -name '*.c')
OBJS = $(SRCS:.c=.o)

TEST = test.c
DEBUG ?= $(or $(filter %.c, $(MAKECMDGOALS)), $(TEST))
D_OUT = debug

all: $(NAME)
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

ifneq ($(filter %.c, $(MAKECMDGOALS)),)
	%.c: ;
endif

debug: all
	$(CC) $(CFLAGS) -I$(LIB_DIR) -g $(DEBUG) $(NAME) -o $(D_OUT)
	$(MAKE) fclean

dclean: fclean
	rm -f $(D_OUT)

.PHONY: all clean fclean re debug dclean
