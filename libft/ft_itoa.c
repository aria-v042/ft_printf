/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 03:44:18 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/20 03:45:43 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
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

char	*ft_itoa(int n)
{
	char		*aoti;
	long long	big;
	size_t		len;

	len = ft_numlen(n);
	aoti = (char *)malloc(len + 1);
	if (!aoti)
		return (NULL);
	aoti[len--] = '\0';
	if (n == 0)
		return (*aoti = '0', aoti);
	big = (long long) n;
	if (big < 0)
	{
		*aoti = '-';
		big *= -1;
	}
	while (big > 0)
	{
		aoti[len--] = '0' + (big % 10);
		big /= 10;
	}
	return (aoti);
}
//
///* DEBUGGING: */
//
//#include <stdio.h>
//
//int	main(void)
//{
//	char	*str;
//
//	str = ft_itoa(-10004);
//	printf("str = %s\n", str);
//	return (0);
//}
