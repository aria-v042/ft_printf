/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 03:46:04 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/31 16:01:15 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long n, char *base)
{
	unsigned long long	base_size;
	int					bytes_printed;

	bytes_printed = 0;
	base_size = ft_strlen(base);
	if (n >= base_size)
		bytes_printed += ft_putnbr_base(n / base_size, base);
	ft_putchar_fd(base[n % base_size], STDOUT_FILENO);
	return (++bytes_printed);
}

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
