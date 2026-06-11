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

ROOT = .
NAME = libftprintf.a

LIB = libft
LIBDIR = $(ROOT)/$(LIB)
LIBNAME = $(LIBDIR)/$(LIB).a

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
	$(MAKE) -C $(LIBDIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBDIR) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBDIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
