/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:08:36 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/11 18:24:09 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

vector vec(double x, double y, double z)
{
	vector out;
	out.x = x;
	out.y = y;
	out.z = z;

	return (out);
}

vector prod(vector u, double lamda)
{
	return (vec(u.x * lamda, u.y * lamda, u.z * lamda));
}

vector add(vector u, vector v)
{
	return(vec(u.x + v.x, u.y + v.y, u.z + v.z));
}

vector subs(vector u, vector v)
{
	return(vec(u.x - v.x, u.y - v.y, u.z - v.z));
}
