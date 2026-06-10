/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hexadecimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:58:30 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/31 16:01:24 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_hexadecimal(va_list *ap_ptr, char specifier)
{
	unsigned int	num;

	num = va_arg(*ap_ptr, unsigned int);
	if (specifier == 'x')
		return (ft_putnbr_base(num, BASE16_LOWERCASE));
	else if (specifier == 'X')
		return (ft_putnbr_base(num, BASE16_UPPERCASE));
	return (0);
}
