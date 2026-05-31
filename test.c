/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:35:11 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/31 05:04:18 by frodrig2         ###   ########.fr       */
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

void	test_printf_integer(int test_num, int intgr)
{
	int	bytes_printed;

	printf("-------\ntest %d:\n\n", test_num);
	bytes_printed = ft_printf("%i\n", intgr);
	ft_printf(">> ft_printf() printed %d chars\n", bytes_printed);
	bytes_printed = printf("%i\n", intgr);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

void	test_printf_unsigned(int test_num, int unsgn)
{
	int	bytes_printed;

	printf("-------\ntest %d:\n\n", test_num);
	bytes_printed = ft_printf("%u\n", unsgn);
	ft_printf(">> ft_printf() printed %d chars\n", bytes_printed);
	bytes_printed = printf("%u\n", unsgn);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

void	test_printf_hexadecimal(int test_num, int hex)
{
	int	bytes_printed;

	printf("-------\ntest %d:\n\n", test_num);
	bytes_printed = ft_printf("%x\n", hex);
	ft_printf(">> ft_printf() printed %d chars\n", bytes_printed);
	bytes_printed = printf("%x\n", hex);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
	bytes_printed = ft_printf("%X\n", hex);
	ft_printf(">> ft_printf() printed %d chars\n", bytes_printed);
	bytes_printed = printf("%X\n", hex);
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
	test_printf_integer(9, -2147483648);
	test_printf_unsigned(10, 0);
	test_printf_unsigned(11, 4294967295);
	test_printf_hexadecimal(12, 42);
	test_printf_hexadecimal(12, 4294967295);
	return (0);
}
