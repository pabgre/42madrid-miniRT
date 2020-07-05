/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:38:35 by jballest          #+#    #+#             */
/*   Updated: 2019/11/18 13:16:01 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_check(char c, const char *check)
{
	while (*check != 0)
	{
		if (c == *check)
			return (0);
		check++;
	}
	return (1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	trb;
	size_t	tra;

	trb = 0;
	if (!s1)
		return (NULL);
	while (char_check(s1[trb], set) == 0)
		trb++;
	tra = ft_strlen(s1) - 1;
	if (trb >= tra || *s1 == 0)
		return (ft_strdup(""));
	while (char_check(s1[tra], set) == 0)
		tra--;
	if (!(str = (char *)malloc((tra - trb + 2) * sizeof(char))))
		return (NULL);
	ft_strlcpy(str, s1 + trb, tra - trb + 2);
	return (str);
}
