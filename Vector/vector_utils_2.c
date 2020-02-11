/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:16:53 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/11 20:18:23 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

vector cross_prod(vector u, vector v)
{
	vector w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = -(u.x*v.z - u.z*v.x);
	w.z = u.x * v.y - u.y * v.x;
	return(w);
}

double magnitude(vector u)
{
	return(sqrt(dot_prod(u,u)));
}

double distance(vector u, vector v)
{
	return(magnitude(subs(u,v)));
}

double angle(vector u, vector v)
{
	double aux;

	aux = dot_prod(u,v) / (magnitude(u) * magnitude(v));
	return (acos(aux));
}

vector normalize(vector u)
{
	return (prod(u, 1.0 / magnitude(u)));
}
