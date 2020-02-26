/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinto-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:06:04 by npinto-g          #+#    #+#             */
/*   Updated: 2019/12/03 14:27:56 by npinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int		c;

	c = 0;
	while (s[c] != '\0')
	{
		c++;
	}
	return ((size_t)c);
}

char		*ft_strdup(const char *s1)
{
	char	*copy;
	int		c;

	c = 0;
	copy = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (copy == NULL)
		return (0);
	while (s1[c] != '\0')
	{
		copy[c] = s1[c];
		c++;
	}
	copy[c] = '\0';
	return (copy);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*subs;

	if (s == 0)
		return (0);
	if (ft_strlen(s) < start || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	if (!(subs = (char*)malloc(len * sizeof(char) + 1)))
		return (0);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start];
		start++;
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	str = (char*)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (str == NULL)
		return (0);
	while (*s1 != '\0')
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
