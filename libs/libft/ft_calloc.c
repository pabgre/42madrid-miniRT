/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:57:34 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/07 16:04:28 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*out;
	size_t	s;

	s = count * size;
	out = malloc(s);
	if (!out)
		return (NULL);
	else
	{
		ft_bzero(out, s);
		return (out);
	}
}
