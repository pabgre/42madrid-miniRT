/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:24:44 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/27 11:48:53 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "raytracer.h"
#include "polinom.h"
#include <math.h>

bool		is_pt_in_cylinder(t_vector pt, t_cylinder cylinder)
{
	t_line			cylinder_line;

	cylinder_line = l(cylinder.dir, cylinder.center);
	return (distance(closest_point_line(pt, cylinder_line), cylinder.center)
			<= cylinder.height);
}

t_c_data	cylinder_data_init(bool a_in, bool b_in,
								t_vector pt_a, t_vector pt_b)
{
	t_c_data c_data;

	c_data.a_in = a_in;
	c_data.b_in = b_in;
	c_data.pt_a = pt_a;
	c_data.pt_b = pt_b;

	return (c_data);
}
