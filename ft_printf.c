/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 03:33:06 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/31 03:08:43 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_format(const char *format, va_list *ap_ptr)
{
	if (*format == 'c')
		return (print_char(ap_ptr));
	if (*format == 's')
		return (print_string(ap_ptr));
	if (*format == 'p')
		return (print_pointer(ap_ptr));
	if (*format == 'd' || *format == 'i')
		return (print_integer(ap_ptr));
//	if (*format == 'u')
//		return (print_unsigned(ap_ptr));
//	if (*format == 'x' || *format == 'X')
//		return (print_hexadecimal(ap_ptr));
//	if (*format == '%')
//		return (print_percent(ap_ptr));
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
			bytes_printed += convert_format(++format, &ap);
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
