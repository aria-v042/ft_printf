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

int	print_format(const char *format, va_list *argptr)
{
	// TODO
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		bytes_printed;

	bytes_printed = 0;
	args = va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			bytes_printed += print_format(*++format, &args); // TODO
		}
		else
		{
			ft_putchar_fd(*format, STDOUT_FILENO);
			bytes_printed++;
		}
		format++;
	}
	va_end(args);
	return (bytes_printed);
}
