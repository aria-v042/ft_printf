/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:57:09 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/31 15:59:29 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_pointer(va_list *ap_ptr)
{
	uintptr_t	address;
	int			len;

	address = (uintptr_t)va_arg(*ap_ptr, void *);
	if (!address)
	{
		ft_putstr_fd("(nil)", STDOUT_FILENO);
		return (5);
	}
	ft_putstr_fd("0x", STDOUT_FILENO);
	len = 2;
	ft_putnbr_base(address, BASE16_LOWERCASE, &len);
	return (len);
}
