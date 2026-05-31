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
	int				len;

	len = 0;
	num = va_arg(*ap_ptr, unsigned int);
	if (specifier == 'x')
		ft_putnbr_base(num, BASE16_LOWERCASE, &len);
	else if (specifier == 'X')
		ft_putnbr_base(num, BASE16_UPPERCASE, &len);
	return (len);
}
