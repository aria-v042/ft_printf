/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:29:54 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/31 03:03:36 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(va_list *ap_ptr)
{
	char	*s;

	s = va_arg(*ap_ptr, char *);
	if (!s)
	{
		ft_putstr_fd("(null)", STDOUT_FILENO);
		return (6);
	}
	ft_putstr_fd(s, STDOUT_FILENO);
	return ((int)ft_strlen(s));
}
