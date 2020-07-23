/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:16:53 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/17 11:27:57 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector cross_prod(t_vector u, t_vector v)
{
	t_vector w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = -(u.x*v.z - u.z*v.x);
	w.z = u.x * v.y - u.y * v.x;
	return(w);
}

double magnitude(t_vector u)
{
	return(sqrt(dot_prod(u,u)));
}

double distance(t_vector u, t_vector v)
{
	return(magnitude(subs(u,v)));
}

double angle(t_vector u, t_vector v)
{
	double aux;

	aux = dot_prod(u,v) / (magnitude(u) * magnitude(v));
	return (acos(aux));
}

t_vector normalize(t_vector u)
{
	return (prod(u, 1.0 / magnitude(u)));
}

t_vector	rotate(t_vector u, t_vector axis, double theta)
{
	t_vector u_par;
	t_vector u_orth;
	t_vector w;
	t_vector res;

	u_par = prod(axis, dot_prod(u, axis) / dot_prod(axis, axis));
	u_orth = subs(u, u_par);
	w = cross_prod(axis, u_orth);

	res = prod(add(prod(u_orth, cos(theta) / magnitude(u_orth)),
					prod(w, sin(theta) / magnitude(w))), magnitude(u_orth));
	res = add(res, u_par);
	return (res);
}
