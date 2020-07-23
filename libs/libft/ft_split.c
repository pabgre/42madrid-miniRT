/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinto-g <npinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:22:28 by jballest          #+#    #+#             */
/*   Updated: 2020/07/06 11:37:08 by npinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wcount(char const *s, char c)
{
	int		i;
	int		wcount;

	i = 0;
	wcount = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			wcount++;
		}
	}
	return (wcount);
}

static char		*ft_wordsplit(char const *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_split(char const *s, char c)
{
	char	**words;
	int		i;

	if (!s || !c)
	{
		words = malloc(sizeof(char*));
		words[0] = NULL;
		return (words);
	}
	if (!(words = (char **)malloc(sizeof(char*) * (ft_wcount(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && *s != c)
		{
			words[i++] = ft_wordsplit(s, c);
			while (*s && *s != c)
				s++;
		}
	}
	words[i] = NULL;
	return (words);
}
