# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/23 22:59:04 by frodrig2          #+#    #+#              #
#    Updated: 2026/05/29 17:38:46 by frodrig2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = .
SRCS = $(shell find $(SRC_DIR) -maxdepth 1 -name '*.c')
OBJS = $(SRCS:.c=.o)

TEST_SRC = test.c
DBG_SRC ?= $(or $(filter %.c, $(MAKECMDGOALS)), $(TEST_SRC))
DBG_OUT = debug

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB)
	cp $(LIB)/$(LIB).a $(NAME)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	git submodule update --init
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIB)

clean:
	$(MAKE) clean -C $(LIB)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIB)
	rm -f $(NAME)

re: fclean all

ifneq ($(filter %.c, $(MAKECMDGOALS)),)
	%.c: ;
endif

debug: all
	$(CC) $(CFLAGS) -g $(DBG_SRC) $(NAME) -o $(DBG_OUT)
	$(MAKE) fclean

dclean: fclean
	rm -f $(DBG_OUT)

.PHONY: all clean fclean re debug dclean
