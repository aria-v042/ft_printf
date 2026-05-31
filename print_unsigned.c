/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 03:27:20 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/31 04:15:53 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(va_list *ap_ptr)
{
	unsigned int	num;
	int				len;

	len = 0;
	num = va_arg(*ap_ptr, unsigned int);
	util_putnbr_base(num, "0123456789", &len);
	return (len);
}
