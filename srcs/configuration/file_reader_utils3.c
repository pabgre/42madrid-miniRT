/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:53:08 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/23 12:57:17 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		*get_params(const char *buf, int size)
{
	double		*param;
	int			pos;
	int			l;

	pos = 0;
	l = 0;
	param = (double *)malloc(sizeof(double) * size);
	while (buf[pos])
	{
		if ((ft_isdigit(buf[pos]) || buf[pos] == '-') && l < size)
		{
			param[l] = ft_atod(&buf[pos]);
			l++;
			while ((buf[pos]) != 32 && buf[pos] != ',' && buf[pos])
				pos++;
		}
		pos++;
	}
	return (param);
}

char		*rm_spaces(char *buf)
{
	char	*aux;
	int		i;

	i = 0;
	aux = ft_strdup(buf);
	while (aux[i] != '\0')
	{
		if (aux[i] != 32)
		{
			aux[i] = ',';
		}
		i++;
	}
	return (aux);
}

size_t		str_array_len(char **array)
{
	size_t		i;

	i = 0;
	while (array[i] != NULL)
	{
		i++;
	}
	return (i);
}

size_t		array_len(double *array, size_t size)
{
	size_t		i;

	array = NULL;
	i = size / sizeof(array[0]);
	return (i);
}

double		*get_params_array(char **s_param)
{
	double		*param;
	size_t		i;
	size_t		j;
	size_t		len;

	i = (ft_isdigit(**s_param)) ? 0 : 1;
	j = 0;
	len = str_array_len(s_param);
	param = malloc(sizeof(param) * len);
	while (i < len)
	{
		param[j] = ft_atod(s_param[i]);
		i++;
		j++;
	}
	return (param);
}
