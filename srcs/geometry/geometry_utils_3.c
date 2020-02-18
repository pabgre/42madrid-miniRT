/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:03:47 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/18 19:38:31 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"
#include "../../includes/raytracer.h"
#include "../../includes/polinom.h"
#include <math.h>

t_polinom2		cylinder_ray_equation(t_line ray, t_cylinder cylinder)
{
	t_polinom2	pol;
	t_vector	aux;
	t_vector	oa;
	t_vector	ab;


	oa = subs(ray.point, cylinder.a_point);
	ab = subs(cylinder.a_point, cylinder.b_point);

	aux = cross_prod(ray.dir, ab);
	pol.a = dot_prod(aux, aux);
	pol.b = 2 * dot_prod(aux, cross_prod(oa, ab));
	pol.c = dot_prod(cross_prod(oa, ab),cross_prod(oa, ab)) - cylinder.radius * cylinder.radius * dot_prod(ab, ab);
	return (pol);
}

double		ray_hit_cylinder(t_line ray, t_cylinder cylinder)
{
	t_polinom2 pol;

	pol = cylinder_ray_equation(ray, cylinder);
	return (discr(pol));
}

t_ray_hit_data	cylinder_hit_point(t_line ray, t_cylinder cylinder)
{
	t_ray_hit_data data;

	data = ray_hit_data_init(cylinder.a_point);
	if (ray_hit_cylinder(ray, cylinder) >= 0)
	{
		data.hit_object = CYLINDER;
	}
	return (data);
}
