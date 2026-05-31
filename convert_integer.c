/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 02:14:31 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/31 03:45:53 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(va_list *ap_ptr)
{
	int	num;

	num = va_arg(*ap_ptr, int);
	ft_putnbr_fd(num, STDOUT_FILENO);
	return ((int)ft_numlen(num));
}
