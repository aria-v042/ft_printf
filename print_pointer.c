/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:30:18 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/29 21:36:50 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO:
#include "ft_printf.h"

void	util_putnbr_base(unsigned long long n, char *base, int *len)
{
	unsigned long long	base_size;

	base_size = ft_strlen(base);
	if (n >= base_size)
		util_putnbr_base(n / base_size, base, len);
	ft_putchar_fd(base[n % base_size], STDOUT_FILENO);
	(*len)++;
}

int	print_pointer(va_list *ap_ptr)
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
	util_putnbr_base(address, "0123456789abcdef", &len);
	return (len);
}
