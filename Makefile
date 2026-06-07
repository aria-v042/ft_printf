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

NAME = libftprintf.a

LIB = libft
LIBNAME = $(LIB)/$(LIB).a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	   convert_char.c \
	   convert_string.c \
	   convert_pointer.c \
	   convert_integer.c \
	   convert_unsigned.c \
	   convert_hexadecimal.c \
	   utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBNAME) $(OBJS)
	cp $(LIBNAME) $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIBNAME):
	git submodule update --init
	$(MAKE) -C $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIB)

clean:
	$(MAKE) clean -C $(LIB)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIB)
	rm -f $(NAME)

re: fclean all

.PHONY: all $(LIBNAME) clean fclean re
