/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:16:53 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/27 12:38:04 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	cross_prod(t_vector u, t_vector v)
{
	t_vector w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = -(u.x * v.z - u.z * v.x);
	w.z = u.x * v.y - u.y * v.x;
	return (w);
}

double		magnitude(t_vector u)
{
	return (sqrt(dot_prod(u, u)));
}

double		distance(t_vector u, t_vector v)
{
	return (magnitude(subs(u, v)));
}

double		angle(t_vector u, t_vector v)
{
	double aux;

	aux = dot_prod(u, v) / (magnitude(u) * magnitude(v));
	return (acos(aux));
}

t_vector	normalize(t_vector u)
{
	return (prod(u, 1.0 / magnitude(u)));
}
