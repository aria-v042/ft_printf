/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 03:33:06 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/25 04:32:57 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_format(const char *format, va_list *apptr)
{
	if (*format == 'c')
		return convert_char(apptr);
	if (*format == 's')
		return convert_string(apptr);
	if (*format == 'p')
		return convert_pointer(apptr);
	if (*format == 'd' || *format == 'i')
		return convert_integer(apptr);
	if (*format == 'u')
		return convert_unsigned(apptr);
	if (*format == 'x' || *format == 'X')
		return convert_hexadecimal(apptr);
	if (*format == '%')
		return convert_percent(apptr);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		bytes_printed;

	bytes_printed = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			bytes_printed += convert_format(++format, &ap); // TODO
		}
		else
		{
			bytes_printed += write(STDOUT_FILENO, format, 1);
		}
		format++;
	}
	va_end(ap);
	return (bytes_printed);
}
//
///* DEBUGGING */
//#include <stdio.h>
//
////void	test_printf_null(int tint, void *nul)
////{
////	int	ret;
////
////	printf("test %d:\n\n", tint);
////	ret = ft_printf(nul);
////	ft_printf(">>> ft_printf() printed %d chars\n\n", ret);
////	ret = printf("%s", nul);
////	printf(">>> printf() printed %d chars\n\n", ret);
////}
////
//void	test_printf_string(int tint, const char *s)
//{
//	int	ret;
//
//	printf("-------\ntest %d:\n\n", tint);
//	ret = ft_printf(s);
//	ft_printf(">>> ft_printf() printed %i chars\n", ret);
//	ret = printf("%s", s);
//	printf(">>> printf() printed %i chars\n\n", ret);
//}
//
//void	test_printf_decimal(int tint, int d)
//{
//	int	ret;
//
//	printf("-------\ntest %d:\n\n", tint);
//	ret = ft_printf("%d", d);
//	ft_printf(">>> ft_printf() printed %d chars\n", ret);
//	ret = printf("%d", d);
//	printf(">>> printf() printed %d chars\n\n", ret);
//}
//
//int	main(void)
//{
//	test_printf_string(1, "test\n");
//	test_printf_string(2, "");
//	//test_printf_null(3, NULL);
//	return (0);
//}
