/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 23:40:08 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/18 01:16:46 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *s)
{
	int	iota;
	int	sign;

	while (ft_isspace(*s))
	{
		s++;
	}
	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	iota = 0;
	while (*s >= '0' && *s <= '9')
	{
		iota *= 10;
		iota += *s - '0';
		s++;
	}
	return (iota * sign);
}
