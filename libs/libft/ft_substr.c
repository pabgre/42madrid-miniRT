/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:44:52 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/11 18:42:22 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	j;

	j = 0;
	if (!s)
		return (NULL);
	while (((char*)s)[j] != '\0' && j < start)
		j++;
	if (!(out = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && ((char*)s)[j + i] != '\0')
	{
		out[i] = ((char*)s)[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
