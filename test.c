/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:35:11 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/31 03:09:28 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	test_printf_char(int test_num, char c)
{
	int	bytes_printed;

	printf("-------\ntest %d:\n\n", test_num);
	bytes_printed = ft_printf("%c\n", c);
	printf(">> ft_printf() printed %d chars\n", bytes_printed);
	bytes_printed = printf("%c\n", c);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

void	test_printf_string(int test_num, const char *s)
{
	int	bytes_printed;

	printf("-------\ntest %d:\n\n", test_num);
	bytes_printed = ft_printf("%s\n", s);
	printf(">> ft_printf() printed %d chars\n", bytes_printed);
	bytes_printed = printf("%s\n", s);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

void	test_printf_pointer(int test_num, void *p)
{
	int	bytes_printed;

	printf("-------\ntest %d:\n\n", test_num);
	bytes_printed = ft_printf("%p\n", p);
	printf(">> ft_printf() printed %d chars\n", bytes_printed);
	bytes_printed = printf("%p\n", p);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

void	test_printf_integer(int test_num, int integer)
{
	int	bytes_printed;

	printf("-------\ntest %d:\n\n", test_num);
	bytes_printed = ft_printf("%i\n", integer);
	ft_printf(">> ft_printf() printed %d chars\n", bytes_printed);
	bytes_printed = printf("%i\n", integer);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

int	main(void)
{
	test_printf_char(1, 'f');
	test_printf_char(2, 0);
	test_printf_string(3, "testing");
	test_printf_string(4, NULL);
	test_printf_pointer(5, &test_printf_pointer);
	test_printf_pointer(6, NULL);
	test_printf_integer(7, 42);
	test_printf_integer(8, 0);
	return (0);
}
