/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:04:10 by jballest          #+#    #+#             */
/*   Updated: 2019/11/06 19:16:55 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*m0;
	size_t	i;

	m0 = (char *)s;
	i = 0;
	while (*(m0 + i) != (char)c)
	{
		if (i == n - 1)
			return (0);
		i++;
	}
	return ((m0 + i));
}
