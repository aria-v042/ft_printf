# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frodrig2 <frodrig2@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/20 21:45:22 by frodrig2          #+#    #+#              #
#    Updated: 2026/05/22 02:06:03 by frodrig2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = ..
SRCS = $(shell find $(SRCS_DIR) -name 'ft_*.c')
OBJS = $(SRCS:.c=.o)

TEST = test.c
T_OUT = runtests
DEBUG ?= $(or $(filter %.c, $(MAKECMDGOALS)), $(TEST))
D_OUT = debug

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: all

test: all
	$(CC) $(CFLAGS) -g $(TEST) $(NAME) -o $(T_OUT)
	$(MAKE) fclean

debug: all
	$(CC) $(CFLAGS) -g $(DEBUG) $(NAME) -o $(D_OUT)
	$(MAKE) fclean

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

ifneq ($(filter %.c, $(MAKECMDGOALS)),)
%.c: ;
endif

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

tclean: fclean
	rm -f $(T_OUT)

dclean: fclean
	rm -f $(D_OUT)

re: fclean all

.PHONY: all clean fclean re test debug tclean dclean
