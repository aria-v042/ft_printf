/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 01:10:39 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/19 01:26:12 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s) + 1;
	dup = (char *)malloc(size);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, size);
	return (dup);
}
//
///* DEBUGGING */
//
//#include <stdio.h>
//
//int	main(void)
//{
//	char	*res;
//
//	res = ft_strdup("ola teste");
//	printf("res: \"%s\"\n", res);
//	return (0);
//}
