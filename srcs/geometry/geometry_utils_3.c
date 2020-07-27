/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:03:47 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/27 11:47:47 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "raytracer.h"
#include "polinom.h"
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

t_ray_hit_data	choose_hit_point_2(t_ray_hit_data data, t_line ray,
										t_cylinder c, t_c_data c_data)
{
	c_data.mid_p = line_plane_intersection(ray, pl(c.dir,
			add(c.center, prod(c.dir, c.height))));
	if (distance(c_data.mid_p, add(c.center,
		prod(c.dir, c.height))) > c.radius)
		c_data.mid_p = line_plane_intersection(ray, pl(c.dir,
		add(c.center, prod(c.dir, -c.height))));
	if (c_data.a_in && which_is_near(c_data.pt_a, c_data.mid_p, ray.point))
	{
		data.hit_point = c_data.pt_a;
		data.normal = subs(data.hit_point,
						closest_point_line(data.hit_point, l(c.dir, c.center)));
	}
	else if (c_data.b_in && which_is_near(c_data.pt_b, c_data.mid_p, ray.point))
	{
		data.hit_point = c_data.pt_b;
		data.normal = subs(data.hit_point,
						closest_point_line(data.hit_point, l(c.dir, c.center)));
	}
	else
	{
		data.hit_point = c_data.mid_p;
		data.normal = is_in_positive_plane_side(data.hit_point,
						pl(c.dir, c.center)) ? c.dir : prod(c.dir, -1);
	}
	return (data);
}

t_ray_hit_data	choose_hit_point_1(t_vector pt_a, t_vector pt_b,
									t_cylinder cylinder, t_line ray)
{
	t_ray_hit_data	data;
	bool			a_in;
	bool			b_in;
	t_c_data		c_data;

	a_in = is_pt_in_cylinder(pt_a, cylinder);
	b_in = is_pt_in_cylinder(pt_b, cylinder);
	data.hit_object = CYLINDER;
	if (a_in && b_in)
	{
		data.hit_point = closest_point(pt_a, pt_b, ray.point);
		data.normal = subs(data.hit_point, closest_point_line(data.hit_point,
											l(cylinder.dir, cylinder.center)));
	}
	else if (!a_in && !b_in)
		data.hit_object = NONE;
	else
	{
		c_data = cylinder_data_init(a_in, b_in, pt_a, pt_b);
		data = choose_hit_point_2(data, ray, cylinder, c_data);
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
	t_ray_hit_data data;

	data = ray_hit_cylinder(ray, cylinder);
	if (!is_in_positive_plane_side(data.hit_point, pl(ray.dir, ray.point)))
		data.hit_object = NONE;
	return (data);
}
