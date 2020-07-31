/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:37:52 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/31 10:37:39 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
