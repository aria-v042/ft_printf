/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 03:38:26 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/31 15:59:54 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define BASE10 "0123456789"
# define BASE16_LOWERCASE "0123456789abcdef"
# define BASE16_UPPERCASE "0123456789ABCDEF"

/* ==== CORE ==== */

int		ft_printf(const char *format, ...);

/* ==== FORMAT CONVERSION ==== */

int		parse_format(const char *format, va_list *ap_ptr);

int		convert_char(va_list *ap_ptr);
int		convert_string(va_list *ap_ptr);
int		convert_pointer(va_list *ap_ptr);
int		convert_integer(va_list *ap_ptr);
int		convert_unsigned(va_list *ap_ptr);
int		convert_hexadecimal(va_list *ap_ptr, char specifier);

/* ==== UTILS ==== */

void	ft_putnbr_base(unsigned long long n, char *base, int *len);
size_t	ft_numlen(int n);

#endif
