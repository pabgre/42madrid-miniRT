/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:31:12 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/11 19:05:06 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	nb_digit(int n)
{
	int size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int		aux;
	int		size;
	char	*out;

	aux = 0;
	size = nb_digit(n);
	if (!(out = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	out[size - 1] = '0';
	out[size] = '\0';
	if (n < 0)
		out[0] = '-';
	while (n != 0)
	{
		aux = n % 10;
		if (aux < 0)
			aux = -aux;
		out[size - 1] = '0' + aux;
		n = n / 10;
		size--;
	}
	return (out);
}
