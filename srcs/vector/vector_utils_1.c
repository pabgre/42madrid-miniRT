/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:08:36 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/13 18:31:56 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_vector vec(double x, double y, double z)
{
	t_vector out;
	out.x = x;
	out.y = y;
	out.z = z;

	return (out);
}

t_vector prod(t_vector u, double lamda)
{
	return (vec(u.x * lamda, u.y * lamda, u.z * lamda));
}

t_vector add(t_vector u, t_vector v)
{
	return(vec(u.x + v.x, u.y + v.y, u.z + v.z));
}

t_vector subs(t_vector u, t_vector v)
{
	return(vec(u.x - v.x, u.y - v.y, u.z - v.z));
}

double dot_prod(t_vector u, t_vector v)
{
	return(u.x * v.x + u.y * v.y + u.z * v.z);
}
