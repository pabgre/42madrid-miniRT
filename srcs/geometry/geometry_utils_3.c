/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:03:47 by psan-gre          #+#    #+#             */
/*   Updated: 2020/02/20 21:59:08 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"
#include "../../includes/raytracer.h"
#include "../../includes/polinom.h"
#include <math.h>

#define MIN(x, y) x < y ? x : y


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
	pol.c = dot_prod(cross_prod(oa, ab),cross_prod(oa, ab)) - cylinder.radius * cylinder.radius * dot_prod(ab, ab);
	return (pol);
}

#include <unistd.h>

t_ray_hit_data	choose_hit_point(t_vector point_a, t_vector point_b, t_cylinder cylinder, t_line ray)
{
	t_ray_hit_data	data;
	bool			a_in_cylinder;
	bool			b_in_cylinder;
	t_line			cylinder_line;
	t_vector		middle_point;

	cylinder_line = l(cylinder.dir, cylinder.center);
	data = ray_hit_data_init();
	a_in_cylinder = distance(closest_point_line(point_a, cylinder_line), cylinder.center) <= cylinder.height;
	b_in_cylinder = distance(closest_point_line(point_b, cylinder_line), cylinder.center) <= cylinder.height;
	if (a_in_cylinder && b_in_cylinder)
	{
		data.hit_point = closest_point(point_a, point_b, ray.point);
		data.hit_object = CYLINDER;
	}
	else if (!a_in_cylinder && !b_in_cylinder)
		data.hit_object = NONE;
	else
	{
		middle_point = line_plane_intersection(ray, pl(cylinder.dir, add(cylinder.center, prod(cylinder.dir,cylinder.height))));
		if(distance(middle_point, add(cylinder.center, prod(cylinder.dir,cylinder.height))) > cylinder.radius)
		{
			middle_point = line_plane_intersection(ray, pl(cylinder.dir, add(cylinder.center, prod(cylinder.dir, -cylinder.height))));
		}
		if (a_in_cylinder && distance(point_a, ray.point) <= distance(middle_point, ray.point))
		{
			data.hit_point = point_a;
			data.hit_object = CYLINDER;
		}
		else if (b_in_cylinder && distance(point_b, ray.point) <= distance(middle_point, ray.point))
		{
			data.hit_point = point_b;
			data.hit_object = CYLINDER;
		}
		else
		{
			data.hit_point = middle_point;
			data.hit_object = PLANE;
		}
	}
	return (data);
}

t_ray_hit_data	ray_hit_cylinder(t_line ray, t_cylinder cylinder)
{
	t_polinom2		pol;
	t_ray_hit_data	data;
	t_vector		point_a;
	t_vector		point_b;
	double			disc;

	pol = cylinder_ray_equation(ray, cylinder);
	disc = discr(pol);
	data = ray_hit_data_init();
	if (disc >= 0)
	{
		point_a = add(ray.point, prod(ray.dir, -(-pol.b + sqrt(disc)) / (-2 * pol.a)));
		point_b = add(ray.point, prod(ray.dir, -(-pol.b - sqrt(disc)) / (-2 * pol.a)));
		data = choose_hit_point(point_a, point_b, cylinder, ray);
	}
	return (data);
}

t_ray_hit_data	cylinder_hit_point(t_line ray, t_cylinder cylinder)
{
	return (ray_hit_cylinder(ray, cylinder));
}
