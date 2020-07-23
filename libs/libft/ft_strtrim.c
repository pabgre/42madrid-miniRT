/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 08:28:26 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/11 18:46:23 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		end;
	int		start;

	start = -1;
	end = 0;
	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		if (start == -1 && ft_strchr(set, s1[i]) == 0)
		{
			start = i;
		}
		if (ft_strchr(set, s1[i]) == 0)
			end = i;
		i++;
	}
	return (ft_substr(s1, start, (size_t)(end - start + 1)));
}
