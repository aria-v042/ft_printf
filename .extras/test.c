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
#include <limits.h>

void	test_printf_hello(int test_num)
{
	int	bytes_printed;

	printf("-------\ntest %d: no conversion\n\n", test_num);
	bytes_printed = ft_printf("hello world\n");
	printf(">> ft_printf() printed %d chars\n\n", bytes_printed);
	bytes_printed = printf("hello world\n");
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

void	test_printf_null(int test_num)
{
	int	bytes_printed;

	printf("-------\ntest %d: NULL format string\n\n", test_num);
	bytes_printed = ft_printf(NULL);
	printf(">> ft_printf() printed %d chars\n\n", bytes_printed);
	bytes_printed = printf(NULL);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

//void	test_printf_empty(int test_num)
//{
//	int	bytes_printed;
//
//	printf("-------\ntest %d: empty format string\n\n", test_num);
//	bytes_printed = ft_printf("");
//	printf(">> ft_printf() printed %d chars\n\n", bytes_printed);
//	bytes_printed = printf("");
//	printf(">> printf() printed %d chars\n\n", bytes_printed);
//}
//
void	test_printf_char(int test_num, char c)
{
	int	bytes_printed;

	printf("-------\ntest %d: %%c\n\n", test_num);
	bytes_printed = ft_printf("%c\n", c);
	printf(">> ft_printf() printed %d chars\n\n", bytes_printed);
	bytes_printed = printf("%c\n", c);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

void	test_printf_string(int test_num, const char *s)
{
	int	bytes_printed;

	printf("-------\ntest %d: %%s\n\n", test_num);
	bytes_printed = ft_printf("%s\n", s);
	printf(">> ft_printf() printed %d chars\n\n", bytes_printed);
	bytes_printed = printf("%s\n", s);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

void	test_printf_pointer(int test_num, void *p)
{
	int	bytes_printed;

	printf("-------\ntest %d: %%p\n\n", test_num);
	bytes_printed = ft_printf("%p\n", p);
	printf(">> ft_printf() printed %d chars\n\n", bytes_printed);
	bytes_printed = printf("%p\n", p);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

void	test_printf_integer(int test_num, int intgr)
{
	int	bytes_printed;

	printf("-------\ntest %d.a: %%d\n\n", test_num);

	bytes_printed = ft_printf("%d\n", intgr);
	printf(">> ft_printf() printed %d chars\n\n", bytes_printed);
	bytes_printed = printf("%d\n", intgr);
	printf(">> printf() printed %d chars\n\n", bytes_printed);

	printf("test %d.b: %%i\n\n", test_num);

	bytes_printed = ft_printf("%d\n", intgr);
	printf(">> ft_printf() printed %i chars\n\n", bytes_printed);
	bytes_printed = printf("%d\n", intgr);
	printf(">> printf() printed %i chars\n\n", bytes_printed);
}

void	test_printf_unsigned(int test_num, int unsgn)
{
	int	bytes_printed;

	printf("-------\ntest %d: %%u\n\n", test_num);
	bytes_printed = ft_printf("%u\n", unsgn);
	printf(">> ft_printf() printed %d chars\n\n", bytes_printed);
	bytes_printed = printf("%u\n", unsgn);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

void	test_printf_hexadecimal(int test_num, int hex)
{
	int	bytes_printed;

	printf("-------\ntest %d: %%x, %%X\n\n", test_num);

	bytes_printed = ft_printf("%x\n", hex);
	printf(">> ft_printf() printed %d chars\n\n", bytes_printed);
	bytes_printed = printf("%x\n", hex);
	printf(">> printf() printed %d chars\n\n", bytes_printed);

	bytes_printed = ft_printf("%X\n", hex);
	printf(">> ft_printf() printed %d chars\n\n", bytes_printed);
	bytes_printed = printf("%X\n", hex);
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

void	test_printf_percent(int test_num)
{
	int	bytes_printed;

	printf("-------\ntest %d: %%%%\n\n", test_num);
	bytes_printed = ft_printf("print literal %% sign\n");
	printf(">> ft_printf() printed %d chars\n\n", bytes_printed);
	bytes_printed = printf("print literal %% sign\n");
	printf(">> printf() printed %d chars\n\n", bytes_printed);
}

int	main(void)
{
	// test format string with no conversion
	test_printf_hello(1);
	// test null format string
	test_printf_null(2);
	// test %c specifier conversion
	test_printf_char(3, 'f');
	test_printf_char(4, 0);
	// test %s specifier conversion
	test_printf_string(5, "hi friend");
	test_printf_string(6, NULL);
	// test %p specifier conversion
	test_printf_pointer(7, &test_printf_pointer);
	test_printf_pointer(8, NULL);
	// test %d and %i specifier conversion
	test_printf_integer(9, 42);
	test_printf_integer(10, INT_MIN);
	test_printf_integer(11, INT_MAX);
	// test %u specifier conversion
	test_printf_unsigned(12, 0);
	test_printf_unsigned(13, UINT_MAX);
	// test %x and %X specifier conversion
	test_printf_hexadecimal(14, 42);
	test_printf_hexadecimal(15, UINT_MAX);
	// test %% to print a literal percent sign
	test_printf_percent(16);
	return (0);
}
