/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 22:57:46 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/21 05:26:31 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
//
///* DEBUGGING */
//
//#include <string.h>
//
//int	main(void)
//{
//	char	src[] = "test overlap";
//	char	*dest;
//	char	*res;
//
//	// Test overlap
//	dest = src + 1
//	res = memcpy(dest, src, 1);
//	printf("%s\n", res);
//
//	// Test case where dest and src null but size is not zero
//	dest = NULL;
//	src = NULL;
//	dest = memcpy(dest, src, 1);
//	printf("%s\n", dest);
//
//	return (0);
//}
