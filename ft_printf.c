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
