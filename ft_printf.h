/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 03:38:26 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/29 21:49:41 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

/* ==== CORE ==== */

int		ft_printf(const char *format, ...);

/* ==== FORMAT CONVERSION ==== */

int		convert_format(const char *format, va_list *ap_ptr);

int		print_char(va_list *ap_ptr);
int		print_string(va_list *ap_ptr);
int		print_pointer(va_list *ap_ptr);

/* ==== UTILS ==== */

void	util_putnbr_base(unsigned long long n, char *base, int *len);

#endif
