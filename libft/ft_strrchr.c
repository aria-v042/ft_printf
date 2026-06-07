/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 20:44:55 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/15 01:55:42 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	chr;

	i = ft_strlen(s);
	chr = (unsigned char) c;
	while (i && (s[i] != chr))
		i--;
	if (s[i] == chr)
		return ((char *)&s[i]);
	return (NULL);
}
