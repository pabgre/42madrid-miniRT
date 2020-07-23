/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:03:08 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/12 16:43:21 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s1)
{
	char	*out;
	int		i;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	if (!(out = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i >= 0)
	{
		out[i] = s1[i];
		i--;
	}
	return (out);
}
