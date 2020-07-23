/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:50:22 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/07 17:31:58 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (i + j < len && needle[j] != '\0' &&
		haystack[i + j] == needle[j] && haystack[j] != '\0')
		{
			j++;
		}
		if (needle[j] == '\0')
			return (&((char*)haystack)[i]);
		i++;
	}
	return (NULL);
}
