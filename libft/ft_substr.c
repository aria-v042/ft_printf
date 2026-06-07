/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 02:37:55 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/19 02:37:55 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sublen;

	if ((size_t)start >= ft_strlen(s))
		sublen = 0;
	else
	{
		sublen = ft_strlen(s + start);
		if (len < sublen)
			sublen = len;
	}
	sub = (char *)malloc(sublen + 1);
	if (!sub)
		return (NULL);
	if (sublen == 0)
		*sub = '\0';
	else
		ft_strlcpy(sub, s + start, sublen + 1);
	return (sub);
}
