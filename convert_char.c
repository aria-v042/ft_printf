/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:49:48 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/31 15:49:54 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list *ap_ptr)
{
	unsigned char	c;

	c = va_arg(*ap_ptr, int);
	ft_putchar_fd(c, STDOUT_FILENO);
	return ((int)sizeof(unsigned char));
}
