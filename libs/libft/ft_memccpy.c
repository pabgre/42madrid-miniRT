/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:46:24 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/11 19:23:55 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char*)src)[i] != (unsigned char)c)
	{
		((unsigned char*)dst)[i] = ((char*)src)[i];
		i++;
	}
	if (i == n)
	{
		return (NULL);
	}
	else
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		return (&dst[i + 1]);
	}
}
