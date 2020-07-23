/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:28:43 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/23 12:30:13 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

size_t		declen(double d)
{
	int			integer;
	size_t		len;
	int			i;

	integer = d;
	len = nbrlen(integer) + 1;
	i = 0;
	while (d - integer)
	{
		d = d * 10;
		integer = d;
		i++;
	}
	len = (d < 0) ? len + 1 : len;
	len += (i == 0) ? 2 : i;
	return (len);
}

long double	ft_atod(const char *str)
{
	int				i;
	long double		intg;
	long double		dec;
	int				sign;
	int				z_len;

	i = 0;
	dec = 0;
	sign = 1;
	z_len = 0;
	while (!(ft_isdigit(str[i])))
	{
		sign = (str[i] == '-') ? sign * -1 : sign;
		i++;
	}
	intg = ft_atoi(str + i);
	i += nbrlen(intg);
	if (str[i] == '.')
	{
		i++;
		dec = ft_atoi(str + i);
		while (str[i++] == '0')
			z_len++;
	}
	return (intg * sign + (dec / pow(10, nbrlen(dec) + z_len)) * sign);
}
