/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 02:14:31 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/31 03:11:28 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_numlen(int n)
{
	size_t		count;
	long long	big;

	count = 0;
	if (n == 0)
		return (++count);
	big = (long long) n;
	if (big < 0)
	{
		count++;
		big *= -1;
	}
	while (big > 0)
	{
		count++;
		big /= 10;
	}
	return (count);
}

int	print_integer(va_list *ap_ptr)
{
	int	num;

	num = va_arg(*ap_ptr, int);
	ft_putnbr_fd(num, STDOUT_FILENO);
	return ((int)ft_numlen(num));
}
