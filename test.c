/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:35:11 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/31 05:56:47 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	test_printf_nospec(int test_num, const char *str)
{
	int	bytes_printed;

	printf("-------\ntest %d: string with no specifiers\n\n", test_num);
	bytes_printed = ft_printf(str);
	printf(">> ft_printf() printed %d chars\n", bytes_printed);
	bytes_printed = printf(str);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

void	test_printf_char(int test_num, char c)
{
	int	bytes_printed;

	printf("-------\ntest %d: %%c\n\n", test_num);
	bytes_printed = ft_printf("%c\n", c);
	printf(">> ft_printf() printed %d chars\n", bytes_printed);
	bytes_printed = printf("%c\n", c);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

void	test_printf_string(int test_num, const char *s)
{
	int	bytes_printed;

	printf("-------\ntest %d: %%s\n\n", test_num);
	bytes_printed = ft_printf("%s\n", s);
	printf(">> ft_printf() printed %d chars\n", bytes_printed);
	bytes_printed = printf("%s\n", s);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

void	test_printf_pointer(int test_num, void *p)
{
	int	bytes_printed;

	printf("-------\ntest %d: %%p\n\n", test_num);
	bytes_printed = ft_printf("%p\n", p);
	printf(">> ft_printf() printed %d chars\n", bytes_printed);
	bytes_printed = printf("%p\n", p);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

void	test_printf_integer(int test_num, int intgr)
{
	int	bytes_printed;

	printf("-------\ntest %d: %%d, %%i\n\n", test_num);

	bytes_printed = ft_printf("%d\n", intgr);
	printf(">> ft_printf() printed %d chars\n", bytes_printed);
	bytes_printed = printf("%d\n", intgr);
	printf(">> printf() printed %d chars\n\n", bytes_printed);

	bytes_printed = ft_printf("%d\n", intgr);
	printf(">> ft_printf() printed %i chars\n", bytes_printed);
	bytes_printed = printf("%d\n", intgr);
	printf(">> printf() printed %i chars\n\n", bytes_printed);
}

void	test_printf_unsigned(int test_num, int unsgn)
{
	int	bytes_printed;

	printf("-------\ntest %d: %%u\n\n", test_num);
	bytes_printed = ft_printf("%u\n", unsgn);
	printf(">> ft_printf() printed %d chars\n", bytes_printed);
	bytes_printed = printf("%u\n", unsgn);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

void	test_printf_hexadecimal(int test_num, int hex)
{
	int	bytes_printed;

	printf("-------\ntest %d: %%x, %%X\n\n", test_num);

	bytes_printed = ft_printf("%x\n", hex);
	printf(">> ft_printf() printed %d chars\n", bytes_printed);
	bytes_printed = printf("%x\n", hex);
	printf(">> printf() printed %d chars\n\n", bytes_printed);

	bytes_printed = ft_printf("%X\n", hex);
	printf(">> ft_printf() printed %d chars\n", bytes_printed);
	bytes_printed = printf("%X\n", hex);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

int	main(void)
{
	// test printing string with no specifiers
	test_printf_nospec(1, "hi friend\n");
	test_printf_nospec(2, "\n");
	// test %c specifier parsing
	test_printf_char(3, 'f');
	test_printf_char(4, 0);
	// test %s specifier parsing
	test_printf_string(5, "testing");
	test_printf_string(6, NULL);
	// test %p specifier parsing
	test_printf_pointer(7, &test_printf_pointer);
	test_printf_pointer(8, NULL);
	// test %d and %i specifier parsing
	test_printf_integer(9, 42);
	test_printf_integer(10, 0);
	test_printf_integer(11, -2147483648);
	// test %u specifier parsing
	test_printf_unsigned(12, 0);
	test_printf_unsigned(13, 4294967295);
	// test %x and %X specifier parsing
	test_printf_hexadecimal(14, 42);
	test_printf_hexadecimal(15, 4294967295);
	// test %% to print a literal percent sign
	test_printf_nospec(15, "this string prints a %% sign\n");
	return (0);
}
