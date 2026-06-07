/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 23:56:55 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/20 02:53:19 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(const char *s, char c)
{
	size_t	wcount;
	int		word;

	wcount = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && !word)
		{
			word = 1;
			wcount++;
		}
		else if (*s == c && word)
		{
			word = 0;
		}
		s++;
	}
	return (wcount);
}

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

static char	**ft_freewords(char **words, size_t w)
{
	while (w--)
		free(words[w]);
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**words;
	size_t			wlen;
	size_t			w;

	words = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!words)
		return (NULL);
	w = 0;
	while (*s)
	{
		wlen = ft_wordlen(s, c);
		if (wlen)
		{
			words[w] = (char *)malloc(wlen + 1);
			if (!words[w])
				return (ft_freewords(words, w));
			ft_strlcpy(words[w++], s, (wlen + 1));
			s += wlen;
		}
		else
			s++;
	}
	words[w] = NULL;
	return (words);
}
