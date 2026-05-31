/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 04:41:59 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/31 05:03:10 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexadecimal(va_list *ap_ptr, char specifier)
{
	unsigned int	num;
	int				len;

	len = 0;
	num = va_arg(*ap_ptr, unsigned int);
	if (specifier == 'x')
		util_putnbr_base(num, BASE16_LOWERCASE, &len);
	else if (specifier == 'X')
		util_putnbr_base(num, BASE16_UPPERCASE, &len);
	return (len);
}
