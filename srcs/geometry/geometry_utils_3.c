/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:03:47 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/24 18:22:28 by jballest         ###   ########.fr       */
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

	oa = subs(ray.point, cylinder.center);
	ab = cylinder.dir;
	aux = cross_prod(ray.dir, ab);
	pol.a = dot_prod(aux, aux);
	pol.b = 2 * dot_prod(aux, cross_prod(oa, ab));
	pol.c = dot_prod(cross_prod(oa, ab), cross_prod(oa, ab))
	- cylinder.radius * cylinder.radius * dot_prod(ab, ab);
	return (pol);
}

bool			is_pt_in_cylinder(t_vector pt, t_cylinder cylinder)
{
	t_line			cylinder_line;

	cylinder_line = l(cylinder.dir, cylinder.center);
	return (distance(closest_point_line(pt, cylinder_line), cylinder.center)
			<= cylinder.height);
}

t_ray_hit_data	choose_hit_point_1(t_vector pt_a, t_vector pt_b,
									t_cylinder cylinder, t_line ray)
{
	t_ray_hit_data	data;
	bool			a_in_cylinder;
	bool			b_in_cylinder;
	t_vector		middle_point;

	a_in_cylinder = is_pt_in_cylinder(pt_a, cylinder);
	b_in_cylinder = is_pt_in_cylinder(pt_b, cylinder);
	data.hit_object = CYLINDER;
	if (a_in_cylinder && b_in_cylinder)
		data.hit_point = closest_point(pt_a, pt_b, ray.point);
	else if (!a_in_cylinder && !b_in_cylinder)
		data.hit_object = NONE;
	else
	{
		middle_point = line_plane_intersection(ray, pl(cylinder.dir,
			add(cylinder.center, prod(cylinder.dir, cylinder.height))));
		if (distance(middle_point, add(cylinder.center,
			prod(cylinder.dir, cylinder.height))) > cylinder.radius)
			middle_point = line_plane_intersection(ray, pl(cylinder.dir,
			add(cylinder.center, prod(cylinder.dir, -cylinder.height))));
		if (a_in_cylinder && which_is_near(pt_a, middle_point, ray.point))
			data.hit_point = pt_a;
		else if (b_in_cylinder && which_is_near(pt_b, middle_point, ray.point))
			data.hit_point = pt_b;
		else
			data.hit_point = middle_point;
	}
	return (data);
}

t_ray_hit_data	ray_hit_cylinder(t_line ray, t_cylinder cylinder)
{
	t_polinom2		pol;
	t_ray_hit_data	data;
	t_vector		pt_a;
	t_vector		pt_b;
	double			disc;

	pol = cylinder_ray_equation(ray, cylinder);
	disc = discr(pol);
	data = ray_hit_data_init();
	if (disc >= 0)
	{
		pt_a = add(ray.point,
					prod(ray.dir, -(-pol.b + sqrt(disc)) / (-2 * pol.a)));
		pt_b = add(ray.point,
					prod(ray.dir, -(-pol.b - sqrt(disc)) / (-2 * pol.a)));
		data = choose_hit_point_1(pt_a, pt_b, cylinder, ray);
		data.color = cylinder.color;
	}
	return (data);
}

t_ray_hit_data	cylinder_hit_point(t_line ray, t_cylinder cylinder)
{

	return (ray_hit_cylinder(ray, cylinder));
}
