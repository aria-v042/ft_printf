# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/23 22:59:04 by frodrig2          #+#    #+#              #
#    Updated: 2026/05/31 16:20:24 by frodrig2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT = ..

NAME = $(ROOT)/libftprintf.a

LIB = libft
LIBNAME = $(ROOT)/$(LIB)/$(LIB).a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = $(ROOT)
SRCS = $(shell find $(SRC_DIR) -maxdepth 1 -name '*.c')
OBJS = $(SRCS:.c=.o)

TEST_SRC ?= $(or $(filter %.c, $(MAKECMDGOALS)), test.c)
TEST_OUT = test

all: $(NAME)

$(NAME): $(LIBNAME) $(OBJS)
	cp $(LIBNAME) $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIBNAME):
	$(MAKE) -C $(ROOT)/$(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(ROOT)/$(LIB)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(ROOT)/$(LIB)
	rm -f $(NAME)

re: fclean all

# ==== EXTRA ==== #

ifneq ($(filter %.c, $(MAKECMDGOALS)),)
	%.c: ;
endif

test: all
	$(CC) $(CFLAGS) -g $(TEST_SRC) $(NAME) -o $(TEST_OUT)
	$(MAKE) fclean

tclean: fclean
	rm -f $(TEST_OUT)

# =============== #

.PHONY: all clean fclean re test tclean
