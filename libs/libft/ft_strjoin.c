/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:52:10 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/11 18:45:21 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		i;
	char	*out;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(out = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	size = 0;
	while (s1[size] != '\0')
	{
		out[size] = s1[size];
		size++;
	}
	while (s2[i] != '\0')
	{
		out[size + i] = s2[i];
		i++;
	}
	out[size + i] = '\0';
	return (out);
}
