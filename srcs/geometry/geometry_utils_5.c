/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 11:43:56 by psan-gre          #+#    #+#             */
/*   Updated: 2020/07/27 13:49:01 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "geometry.h"
#include "raytracer.h"

bool			is_in_positive_plane_side(t_vector point, t_m_plane pl)
{
	return (dot_prod(subs(point, pl.point), pl.normal) > 0);
}

t_ray_hit_data	ray_hit_math_plane(t_line ray, t_m_plane plane)
{
	t_ray_hit_data data;

	data = ray_hit_data_init();
	if (dot_prod(ray.dir, plane.normal) != 0)
	{
		data.hit_point = line_plane_intersection(ray, plane);
		if (is_in_positive_plane_side(data.hit_point, pl(ray.dir, ray.point)))
		{
			data.color = plane.color;
			data.hit_object = PLANE;
			data.normal = plane.normal;
		}
	}
	return (data);
}

bool			is_pt_between_origin_and_line(t_vector pt,
											t_vector origin, t_line line)
{
	bool		result;
	t_vector	origin_b;
	t_m_plane	plane;

	origin_b = closest_point_line(origin, line);
	plane = pl(normalize(subs(origin_b, origin)), origin_b);
	origin_b = line_plane_intersection(l(subs(pt, origin), origin), plane);
	result = distance(pt, origin_b) <= distance(origin, origin_b) + 0.1;
	result = result && distance(pt, origin) <= distance(origin, origin_b) + 0.1;
	return (result);
}

bool			is_point_in_triangle(t_vector pt, t_triangle triangle)
{
	t_line	line;
	bool	result;

	line = l(subs(triangle.point_b, triangle.point_a), triangle.point_a);
	result = is_pt_between_origin_and_line(pt, triangle.point_c, line);
	line = l(subs(triangle.point_c, triangle.point_b), triangle.point_b);
	result = result &&
				is_pt_between_origin_and_line(pt, triangle.point_a, line);
	line = l(subs(triangle.point_a, triangle.point_c), triangle.point_c);
	result = result &&
				is_pt_between_origin_and_line(pt, triangle.point_b, line);
	return (result);
}

t_ray_hit_data	ray_hit_triangle(t_line ray, t_triangle triangle)
{
	t_m_plane			plane_container;
	t_ray_hit_data		data;

	plane_container = pl(cross_prod(subs(triangle.point_a, triangle.point_b),
				subs(triangle.point_c, triangle.point_b)), triangle.point_b);
	data = ray_hit_math_plane(ray, plane_container);
	if (data.hit_object != NONE &&
	is_point_in_triangle(data.hit_point, triangle))
	{
		data.hit_object = TRIANGLE;
		data.color = triangle.color;
		data.normal = plane_container.normal;
	}
	else
	{
		data.hit_object = NONE;
	}
	return (data);
}
