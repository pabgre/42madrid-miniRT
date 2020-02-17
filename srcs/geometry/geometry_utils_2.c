/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:42:48 by pabgre            #+#    #+#             */
/*   Updated: 2020/02/17 16:16:15 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"
#include <math.h>

bool is_point_in_sphere(t_vector point, t_sphere my_sphere)
{
	bool equation;
	t_vector point_relativ;

	point_relativ = subs(point, my_sphere.center);
	equation = (dot_prod(point_relativ, point_relativ) <=
	my_sphere.radius * my_sphere.radius);
	return (equation);
}

bool is_point_in_cylinder(t_vector point, t_cylinder my_cylinder)
{
	bool equation;
	t_vector closest_point;
	double height;
	t_line axis;

	axis.point = my_cylinder.a_point;
	axis.dir = normalize(subs(my_cylinder.a_point, my_cylinder.b_point));
	height = distance(my_cylinder.a_point, my_cylinder.b_point);

	closest_point = closest_point_line(point, axis);
	equation = distance(point, closest_point) <= my_cylinder.radius;
	equation = equation &&
				(distance(closest_point, my_cylinder.b_point) < height &&
				distance(closest_point, my_cylinder.a_point) < height);
	return (equation);
}

bool	is_point_in_plane(t_vector point, t_plane my_plane, double epsilon)
{
	return (dist_point_plane(point,my_plane) < epsilon);
}

bool	is_point_in_triangle(t_vector point, t_triangle triangle, double epsilon)
{
	t_plane plane_container;
	bool equation;
	double triangle_dist;
	t_line aux_line;

	plane_container.point = triangle.point_a;
	plane_container.normal =
	cross_prod(subs(triangle.point_a, triangle.point_b),
	subs(triangle.point_a, triangle.point_c));
	equation = is_point_in_plane(point, plane_container, epsilon);

	aux_line.point = triangle.point_b;
	aux_line.dir = subs(triangle.point_b, triangle.point_c);
	triangle_dist = dist_point_line(triangle.point_a, aux_line);
	equation = equation && (distance(triangle.point_a, point) <= triangle_dist);

	aux_line.point = triangle.point_c;
	aux_line.dir = subs(triangle.point_c, triangle.point_a);
	triangle_dist = dist_point_line(triangle.point_b, aux_line);
	equation = equation && (distance(triangle.point_b, point) <= triangle_dist);

	aux_line.point = triangle.point_a;
	aux_line.dir = subs(triangle.point_a, triangle.point_b);
	triangle_dist = dist_point_line(triangle.point_c, aux_line);
	equation = equation && (distance(triangle.point_c, point) <= triangle_dist);
	return (equation);
}

bool	ray_hit_sphere(t_line ray, t_sphere sphere)
{
	double	disc;

	disc = pow(2 * (dot_prod(ray.dir, subs(ray.point, sphere.center))), 2);
	disc -= 4 * dot_prod(ray.dir, ray.dir) *
	(dot_prod(subs(ray.point, sphere.center), subs(ray.point, sphere.center))
	- sphere.radius * sphere.radius);
	return (disc >= 0);
}
