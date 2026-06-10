/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:58:01 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/31 15:59:16 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_unsigned(va_list *ap_ptr)
{
	unsigned int	num;

	num = va_arg(*ap_ptr, unsigned int);
	return (ft_putnbr_base(num, BASE10));
}
