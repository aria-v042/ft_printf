/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 03:33:06 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/31 15:50:45 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format(const char *format, va_list *ap_ptr)
{
	if (*format == 'c')
		return (convert_char(ap_ptr));
	if (*format == 's')
		return (convert_string(ap_ptr));
	if (*format == 'p')
		return (convert_pointer(ap_ptr));
	if (*format == 'd' || *format == 'i')
		return (convert_integer(ap_ptr));
	if (*format == 'u')
		return (convert_unsigned(ap_ptr));
	if (*format == 'x' || *format == 'X')
		return (convert_hexadecimal(ap_ptr, *format));
	if (*format == '%')
	{
		ft_putchar_fd('%', STDOUT_FILENO);
		return (1);
	}
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
			bytes_printed += parse_format(++format, &ap);
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
